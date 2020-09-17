#include "LoggerWorker.h"
#include "Log.h"

#define logInfo Log::createLog(Log::LogLevel::Info)
#define logDebug Log::createLog(Log::LogLevel::Debug)
#define logWarning Log::createLog(Log::LogLevel::Warning)

int main() {
    std::cout << "I am sworn to carry your logs." << std::endl;
    logInfo << "Main thread info" << 1;
    logDebug << "Main thread debug" << 2.0;
    const auto l1 = [] {
        logWarning << "Thread 1 warning" << true;
        std::string str = "!!!";  // replace me
        logDebug << "Thread 1 debug" << str << false;
        logInfo << "Thread 1 info" << 3.14f;
    };
    const auto l2 = [] {
        logInfo << "Thread 2 info" << -5;
        logDebug << "Thread 2 debug" << 'k';
        std::string str = "???";  // replace me

        logWarning << "Thread 2 warning" << str;
    };
    std::thread t1(l1);
    std::thread t2(l2);
    t1.join();
    t2.join();
    return 0;
}