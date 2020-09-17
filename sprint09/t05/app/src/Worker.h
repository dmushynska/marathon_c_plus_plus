#pragma once
#include <future>
#include <iostream>
#include <thread>
#include <vector>

class Worker {
public:
    Worker() = default;
    virtual ~Worker() = default;
    Worker(const Worker &) = delete;
    Worker(const Worker &&) = delete;

    void start() {
        if (!m_isRunning) {
            m_worker = std::thread(&Worker::run, this);
            m_isRunning = true;
        }
    }

    void stop() {
        m_isRunning = false;
    }

    void join() {
        if (m_worker.joinable())
            m_worker.join();
    }

    bool isRunning() const {
        return m_isRunning;
    }

protected:
    virtual void run() = 0;

private:
    std::atomic_bool m_isRunning{false};
    std::thread m_worker;
};