#include <iostream>
#include <string>

void check(const std::string &ptr, unsigned long index) {
    if (ptr[index] != 0)
        throw("error");
}

int main(int argc, char **argv) {
    auto count = 0;
    auto index = 0ul;

    if (argc != 5) {
        std::cerr << "usage:./automaton [name] [level] [health] [stamina]\n";
        return 1;
    }
    try {
        auto name = std::string(argv[++count]);
        auto level = std::stoi(argv[++count], &index, 10);
        check(argv[count], index);
        auto health = std::stof(argv[++count], &index);
        check(argv[count], index);
        auto stamina = std::stod(argv[++count], &index);
        check(argv[count], index);
        std::cout << "Name = " << name << std::endl;
        std::cout << "Level = " << level << std::endl;
        std::cout << "Health = " << health << std::endl;
        std::cout << "Stamina = " << stamina << std::endl;
    } catch (...) {
        std::cerr << "Invalid argument " << argv[count] << std::endl;
    }
    return 0;
}