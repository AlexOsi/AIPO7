#pragma once
#include "Employee.hpp"
#include <memory>
#include <unordered_map>
#include <mutex>

class BD {
public:
    BD() = default;
    ~BD() = default;
    BD(BD&&) noexcept = default;
    BD(const BD&) = delete;
    BD& operator=(BD&&) noexcept = default;
    BD& operator=(const BD&) = delete;

    void set(int id, std::string f, std::string s, int a, std::string c, int sh, int d, int sal);

    void set(Employee e);

    std::shared_ptr<Employee> get(int id);

private:
    mutable std::mutex m_m;
    std::unordered_map<int, Employee> m_map;
};