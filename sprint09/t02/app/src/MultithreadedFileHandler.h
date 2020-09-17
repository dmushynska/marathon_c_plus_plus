#pragma once
#include <fstream>
#include <iostream>
#include <thread>
#include <chrono>

class MultithreadedFileHandler {
public:
    MultithreadedFileHandler() = default;
    ~MultithreadedFileHandler() = default;

    void processFile() {
        std::cout << m_file << std::endl;
        m_fileLoaded = false;
        m_condVar.notify_all();
    }

    void loadFile(const std::string& fileName) {
        std::unique_lock lock(m_mutex);

        m_condVar.wait(lock, [this] {
            return m_fileLoaded == false;
        });
        if (!m_file.empty()) {
            std::cout << "-----1 second sleep-----\n";
            std::this_thread::sleep_for(std::chrono::seconds(1));
        }
        std::ifstream in(fileName);
        if (in) {
            m_file = {std::istreambuf_iterator<char>(in), {}};
            processFile();
        } else {
            std::cerr << "error" << std::endl;
        }
    }

private:
    std::string m_file;
    std::mutex m_mutex;
    std::condition_variable m_condVar;
    bool m_fileLoaded{false};
};
