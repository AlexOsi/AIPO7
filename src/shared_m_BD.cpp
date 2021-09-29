#include "../inc/shared_m_BD.hpp"

#include <utility>

void shared_m_BD::set(int id, std::string f, std::string s, int a, std::string c, int sh, int d, int sal) {
    m_sm.lock();
    m_map[id] = { id, std::move(f), std::move(s), a, std::move(c), sh, d, sal };
    m_sm.unlock();
}

void shared_m_BD::set(Employee e) {
    m_sm.lock();
    m_map[e.id] = e;
    m_sm.unlock();
}

std::shared_ptr<Employee> shared_m_BD::get(int id) {
    m_sm.lock_shared();
    auto l = m_map.find(id);
    m_sm.unlock_shared();
    if (l == m_map.end())
        return nullptr;
    return std::make_shared<Employee>(l->second);
}