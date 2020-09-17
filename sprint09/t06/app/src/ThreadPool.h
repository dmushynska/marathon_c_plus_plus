#pragma once
#include <condition_variable>
#include <future>
#include <iostream>
#include <queue>
#include <thread>
#include <vector>

class ThreadPool final {
public:
    explicit ThreadPool(size_t threads) {
        for (size_t i = 0; i < threads; i++) {
            m_workerThreads.emplace_back([this] {
                std::packaged_task<void()> task;

                while (true) {
                    {
                        std::unique_lock<std::mutex> lock(m_queueMutex);

                        m_condVar.wait(lock, [this] {
                            return !m_isRunning || !m_taskQueue.empty();
                        });

                        if (!m_isRunning && m_taskQueue.empty())
                            return;

                        task = std::move(m_taskQueue.front());
                        m_taskQueue.pop();
                    }
                    task();
                }
            });
        }
    }

    ~ThreadPool() {
        m_isRunning = false;
        m_condVar.notify_all();

        for (auto& it : m_workerThreads) {
            it.join();
        }
    }

    ThreadPool(const ThreadPool&) = delete;
    ThreadPool(const ThreadPool&&) = delete;
    ThreadPool& operator=(const ThreadPool&) = delete;

    template <typename Function, class... Args>
    auto enqueueTask(Function&& func, Args&&... args) {
        using return_type = typename std::result_of<Function(Args...)>::type;

        auto task = std::make_shared<std::packaged_task<return_type()>>(
            std::bind(std::forward<Function>(func), std::forward<Args>(args)...));
        std::future<return_type> res = task->get_future();

        {
            std::unique_lock<std::mutex> lock(m_queueMutex);
            m_taskQueue.emplace([task]() {
                (*task)();
            });
        }
        m_condVar.notify_one();
        return res;
    }

private:
    std::vector<std::thread> m_workerThreads;
    std::queue<std::packaged_task<void()>> m_taskQueue;
    std::condition_variable m_condVar;
    std::mutex m_queueMutex;
    bool m_isRunning{true};
};