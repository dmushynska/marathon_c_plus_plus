#pragma once
#include <fstream>
#include <iostream>
#include <sstream>

class Log final {
public:
    enum class LogLevel {
        Debug,
        Warning,
        Info
    };

    ~Log();

    static Log createLog(LogLevel level) {
        return Log(level);
    }

    template <class T>
    Log& operator<<(T const& value);

private:
    Log(LogLevel level) : m_logLevel(level) {}
    LogLevel m_logLevel;
    std::stringstream m_inputStream;
};

template <class T>
Log& Log::operator<<(T const& value) {
    m_inputStream << value << " ";
    return *this;
}
