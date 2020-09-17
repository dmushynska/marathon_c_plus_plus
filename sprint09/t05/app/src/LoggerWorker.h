#pragma once
#include <queue>
#include <fstream>
#include <ctime>
#include <iomanip>
#include "Log.h"
#include "Worker.h"

inline std::string getTimeFileName() {
    auto now = std::chrono::system_clock::now();
    auto in_time_t = std::chrono::system_clock::to_time_t(now);
    std::stringstream ss;
    ss << std::put_time(std::localtime(&in_time_t), "%d_%m_%YT%H_%M_%S");
    return ss.str();
}

class LoggerWorker final : public Worker {
public:
    ~LoggerWorker() override {
        stop();
        m_condVar.notify_all();
        join();
        m_logFileStream.close();
    }

    static LoggerWorker& getLogger() {
        static LoggerWorker worker;
        return worker;
    }

    void log(Log::LogLevel level, const std::string& logMessage);

private:
    struct LogMessage {
        std::string message;
        Log::LogLevel logLevel;
    };

    LoggerWorker() {
        m_logFileStream.open(getTimeFileName() + ".txt");
        start();
    }

    void run() override;
    std::mutex m_runMutex;
    std::condition_variable m_condVar;
    std::ofstream m_logFileStream;
    std::queue<LogMessage> m_logQueue;
    inline static std::shared_ptr<LoggerWorker> m_logger{nullptr};
};


