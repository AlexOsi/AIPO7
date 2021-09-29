#include "../inc/ThreadWrapper.hpp"

ThreadWrapper::~ThreadWrapper() {
    join();
}
void ThreadWrapper::push(std::thread t) {
    m_t.push_back(std::move(t));
}
void ThreadWrapper::join() {
    for (auto& t : m_t)
        if (t.joinable())
            t.join();
}