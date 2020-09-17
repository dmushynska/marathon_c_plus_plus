#pragma once
#include <iostream>
#include <vector>
#include <atomic>

class ClassWithAtomic {
public:
    ClassWithAtomic() = default;
    ~ClassWithAtomic() = default;

    void addToInt(int addValue) {
        // for (int i = 0; i < addValue; i++) {
            m_int+=addValue;
        // }
    }

    void subtractFromInt(int subtractValue) {
        // for (int i = 0; i < subtractValue; i++) {
            m_int-=subtractValue;
        // }
    }

    void pushToVector(int value) {
        // m_vecMutex.lock();
        std::lock_guard lg(m_vecMutex);
        m_vector.push_back(value);
        // m_vecMutex.unlock();
    }

    void eraseFromVector(int value) {
        // m_vecMutex.lock();
        std::lock_guard lg(m_vecMutex);
        m_vector.erase(std::remove(m_vector.begin(), m_vector.end(), value), m_vector.end());
        // m_vecMutex.unlock();
    }

    int getInt() const {
        return m_int;
    }

    std::vector<int> getVector() const {
        return m_vector;
    }

private:
    std::mutex m_vecMutex;
    std::atomic<int> m_int{0};
    std::vector<int> m_vector;
};
