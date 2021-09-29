#pragma once
#include <string>
#include "Employee.hpp"
#include <memory>
#include <unordered_map>
#include <shared_mutex>
class shared_m_BD {
public:
    shared_m_BD() = default;
    ~shared_m_BD() = default;
    shared_m_BD(shared_m_BD&&) noexcept = default;
    shared_m_BD(const shared_m_BD&) = delete;
    shared_m_BD& operator=(shared_m_BD&&) noexcept = default;
    shared_m_BD& operator=(const shared_m_BD&) = delete;

    void set(int id, std::string f, std::string s, int a, std::string c, int sh, int d, int sal);

    void set(Employee e);

    std::shared_ptr<Employee> get(int id);

private:
    mutable std::shared_mutex m_sm;
    std::unordered_map<int, Employee> m_map;
};