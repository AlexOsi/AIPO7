cmake_minimum_required(VERSION 3.17)
project(AIPO7)

set(CMAKE_CXX_STANDARD 17)

set(HEADERS
        inc/Employee.hpp
        inc/m_BD.hpp
        inc/shared_m_BD.hpp
        inc/ThreadWrapper.hpp)

set(SOURCES
        src/main.cpp
        src/m_BD.cpp
        src/shared_m_BD.cpp
        src/ThreadWrapper.cpp)
add_executable(AIPO7
        ${HEADERS}
        ${SOURCES})