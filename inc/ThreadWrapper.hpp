#pragma once
#include <thread>
#include <vector>
class ThreadWrapper {
public:
    ~ThreadWrapper();
    void push(std::thread t);
    void join();
private:
    std::vector<std::thread> m_t;
};