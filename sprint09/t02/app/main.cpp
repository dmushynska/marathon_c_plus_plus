#include "MultithreadedFileHandler.h"
#include "Worker.h"

int main(int argc, char **argv) {
    if (argc == 3) {
        if (std::ifstream(argv[1]) && std::ifstream(argv[2])) {
            Worker worker;
            MultithreadedFileHandler multi;
            worker.startNewThread(&MultithreadedFileHandler::loadFile, &multi, argv[1]);
            worker.startNewThread(&MultithreadedFileHandler::loadFile, &multi, argv[2]);
            worker.joinAllThreads();
        }
        else {
            std::cerr << "error\n";
        }
    } else {
        std::cerr << "usage: ./multithreadedFileHandler [file1] [file2]" << '\n';
        return 1;
    }
    return 0;
}