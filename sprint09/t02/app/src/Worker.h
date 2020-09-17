#pragma once
#include <iostream>
#include <thread>
#include <vector>

class Worker {
public:
    Worker() = default;
    ~Worker() {
        for (auto &it : m_workerThreads) {
            it.~thread();
        }
    }
    template <typename Function, class... Args>
    void startNewThread(Function &&func, Args &&... args) {
        m_workerThreads.push_back(std::thread(func, args...));
    }
    void joinAllThreads() {
        for (auto &it : m_workerThreads) {
            it.join();
        }
    }

private:
    std::vector<std::thread> m_workerThreads;
};