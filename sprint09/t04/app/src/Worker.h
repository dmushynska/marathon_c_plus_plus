#pragma once
#include <iostream>
#include <thread>
#include <vector>
#include <future>

class Worker {
public:
    Worker() = default;
    ~Worker() = default;
    Worker(Worker &&) = delete;
    Worker(const Worker &) = delete;
    Worker &operator=(Worker &&) = delete;
    Worker &operator=(const Worker &) = delete;

    template <typename Function, class... Args>
    auto startAsync(Function &&func, Args &&... args) {
        return std::async(std::forward<Function>(func), std::forward<Args>(args)...);
    }
};