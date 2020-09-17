#include <algorithm>
#include <fstream>
#include <iostream>
#include <set>
#include <sstream>
#include <string>

int error(int argc, char **argv, std::multiset<std::string> &list) {
    std::ifstream stream(argv[1]);
    std::string str;
    int size;

    if (argc != 2) {
        std::cerr << "usage: ./stdAlgoV1 [file_name]\n";
        return 1;
    }
    // if (!stream.is_open() || stream.fail()) {
    //     std::cerr << "error\n";
    //     return 1;
    // }
    for (int i = 0; stream >> str && !stream.fail(); i++) {
        size = str.size() - 1;
            if (str[size] == '!' || str[size] == ',' || str[size] == '.' || str[size] == '?')
                str.erase(str.end() - 1);
            list.insert(str);
    }
    return 0;
}

std::string &get_name_file(std::string &s) {
    std::string name, type;
    std::stringstream new_s(s);
    getline(new_s, name, '.');
    std::reverse(s.begin(), s.end());
    std::stringstream news(s);
    getline(new_s, type, '.');
    if (type.size() != 0)
        type = "." + type;
    return name = name + "_mod" + type;
}

int main(int argc, char **argv) {
    std::multiset<std::string> list;
    if (error(argc, argv, list) > 0)
        return 1;
    std::string s(argv[1]);
    std::ofstream sout(get_name_file(s));
    std::string one;
    if (list.size() != 0)
        for (auto &it : list) {
            if (one != it) {
                one = it;
                sout << it << ": " << list.count(it) << "\n";
            }
        }
    else
        std::cerr << "error\n";
}