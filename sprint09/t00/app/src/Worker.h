#pragma once
#include <iostream>
#include <thread>

class Worker {
public:
    Worker() = default;

    ~Worker() {
        m_thread->join();
    }

    template <typename Function, class... Args>
    void startWorker(Function&& func, Args&&... args) {
        joinThread();
        m_thread = new std::thread(func, args...);
    }

    void joinThread() {
        if (m_thread) {
            m_thread->join();
            delete m_thread;
            m_thread = nullptr;
        }
    }

private:
    std::thread* m_thread{nullptr};
};