#include "../inc/m_BD.hpp"
#include <utility>


void BD::set(int id, std::string f, std::string s, int a, std::string c, int sh, int d, int sal) {
    std::lock_guard lock(m_m);
    m_map[id] = { id, std::move(f), std::move(s), a, std::move(c), sh, d, sal };
}

void BD::set(Employee e) {
    std::lock_guard lock(m_m);
    m_map[e.id] = e;
}

std::shared_ptr<Employee> BD::get(int id) {
    std::lock_guard lock(m_m);
    auto l = m_map.find(id);
    if (l == m_map.end())
        return nullptr;
    return std::make_shared<Employee>(l->second);
}
