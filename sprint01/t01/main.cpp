// #include <algorithm>
#include <iostream>
#include <vector>
#include <string>

bool strSTR(std::string s) {
    std::string mercer = "mercer", emer = "emer", jim = "jim";
    for (auto &it : s) {
        it = tolower(it);
    }
    if ((s.find(mercer) == std::string::npos)
        && (s.find(emer) == std::string::npos)
        && (s.find(jim) == std::string::npos)) {
            return false;
        }
    return true;
}

int main(int argc, char *argv[]) {
    std::vector<std::string> v;
    if (argc == 1) {
        std::cerr << "usage: ./moveAlong [args]\n";
    }
    for (int i = 1; i < argc; i++) {
        if (strSTR(argv[i]) == true) {
            v.push_back(argv[i]);
        }
    }
    for (auto it : v) {
        std::cout << it << ", move along!\n";
    }
}