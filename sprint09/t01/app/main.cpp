#include "MultithreadedClass.h"
#include "src/Worker.h"

int main(int argc, char** argv) {
    MultithreadedClass obj;
    Worker worker;
    if (argc == 4) {
        int addValue, subtractValue, count;
        try {
            addValue = std::stoi(argv[1]), subtractValue = std::stoi(argv[2]), count = std::stoi(argv[3]);
        }
        catch(...) {
            std::cerr << "error\n";
            return 1;
        }
        if ((addValue > 2000 || addValue < -2000) || (subtractValue > 2000 || subtractValue < -2000) || (count > 10 || count < 5)) {
            std::cerr << "Incorrect values\n";
            return 1;
        }
        for (auto i = 0; i < count; ++i) {
            worker.startNewThread(&MultithreadedClass::add, &obj, addValue);
        }
        for (auto i = 0; i < count; ++i) {
            worker.startNewThread(&MultithreadedClass::subtract, &obj, subtractValue);
        }
        worker.joinAllThreads();
        std::cout << obj.getInt() << std::endl;
    } else {
        std::cerr << "usage: ./simpleWorkerV2 [addValue] [subtractValue] [count]\n";
    }
}
