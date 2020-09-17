#include "Log.h"
#include <ctime>
#include <iomanip>
#include "LoggerWorker.h"

Log::~Log() {
    LoggerWorker &ww = LoggerWorker::getLogger();
    ww.log(m_logLevel, m_inputStream.rdbuf()->str());
}

void LoggerWorker::log(Log::LogLevel level, const std::string &logMessage) {
    {
        std::unique_lock<std::mutex> lock(m_runMutex);
        m_logQueue.push(LogMessage{logMessage, level});
    }
    m_condVar.notify_one();
}

std::string getTimeInLog() {
    auto now = std::chrono::system_clock::now();
    auto in_time_t = std::chrono::system_clock::to_time_t(now);
    std::stringstream ss;
    ss << std::put_time(std::localtime(&in_time_t), "%d:%m:%YT%H:%M:%S");
    return ss.str();
}

std::string getLogLevel(Log::LogLevel level) {
    if (level == Log::LogLevel::Info)
        return "Info";
    else if (level == Log::LogLevel::Debug)
        return "Debug";
    else if (level == Log::LogLevel::Warning)
        return "Warning";
    return "";
}

void LoggerWorker::run() {
    while (true) {
        std::unique_lock<std::mutex> lck(m_runMutex);
        m_condVar.wait(lck, [this] {
            return !this->isRunning() || !this->m_logQueue.empty();
        });
        if (!isRunning() && m_logQueue.empty())
            return;
        auto elem = m_logQueue.front();
        m_logFileStream << "[" << getTimeInLog() << "] "
                        << "[" << getLogLevel(elem.logLevel) << "] " << elem.message << std::endl;
        m_logQueue.pop();
    }
}
