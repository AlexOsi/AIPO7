#include <random>
#include "../inc/ThreadWrapper.hpp"
#include "../inc/m_BD.hpp"
#include "../inc/shared_m_BD.hpp"
#include <functional>
#include <iostream>


std::random_device rd;
std::mt19937 randomNum(rd());

void getset(std::function<void(Employee)> set, std::function<std::shared_ptr<Employee>(int)> get) {
    for (int i = 0; i < 100000; ++i) {
        int x = randomNum() % 10;
        if (x <= 1) {
            int id = randomNum() % 100;
            Employee emp = {id, FIRSTNAME[randomNum() % SIZEF],
                            SECONDNAME[randomNum() % SIZEC], static_cast<int>(randomNum() % 40 + 18),
                            CLOTHINGSIZE[randomNum() % SIZECS], static_cast<int>(randomNum() % 10 + 36),
                            static_cast<int>(randomNum() % 1000), static_cast<int>(randomNum() % 30000 + 50000) };
            set(emp);
            //printEmp(std::make_shared<Employee>(emp), "set");
        }
        else {
            auto emp = get(randomNum() % 100);
            //printEmp(emp, "get");
        }
    }
}
int main()
{
    BD b;
    shared_m_BD sb;
    ThreadWrapper t1, t2;
    auto beg1 = std::chrono::high_resolution_clock::now();
    size_t threadsNum = std::thread::hardware_concurrency();
    for (int i = 0; i < threadsNum; ++i)
        t1.push(std::thread{ getset , [&sb](Employee emp) {sb.set(emp); }, [&sb](int id) {return sb.get(id); } });
    t1.join();
    auto end1 = std::chrono::high_resolution_clock::now();
    auto r1 = std::chrono::duration_cast<std::chrono::microseconds>(end1 - beg1).count();

    auto beg2 = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < threadsNum; ++i)
        t2.push(std::thread{ getset,  [&b](Employee emp) {b.set(emp); }, [&b](int id) {return b.get(id); } });
    t2.join();
    auto end2 = std::chrono::high_resolution_clock::now();
    auto r2 = std::chrono::duration_cast<std::chrono::microseconds>(end2 - beg2).count();

    std::cout << "shared: " << r1 << " microseconds" << std::endl << "simple: " << r2 << " microseconds" << std::endl;
}