#pragma once
#include <thread>

class MultithreadedClass {
public:
    MultithreadedClass() = default;
    ~MultithreadedClass() = default;
    int getInt() const {
        return m_int;
    }
    void add(int addValue) {
        m_mutex.lock();
        for (int i = 0; i < addValue; i++) {
            m_int++;
        }
        m_mutex.unlock();
    }
    void subtract(int subtractValue) {
        std::lock_guard<std::mutex> lock(m_mutex);
        for (int i = 0; i < subtractValue; i++) {
            m_int--;
        }
    }

private:
    int m_int{0};
    std::mutex m_mutex;
};