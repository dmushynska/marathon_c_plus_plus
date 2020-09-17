#include <algorithm>
#include <forward_list>
#include <fstream>
#include <iostream>
#include <sstream>

int error(int argc, char **argv, std::forward_list<std::string> &list) {
    std::ifstream stream(argv[1]);
    std::string str;

    if (argc != 2) {
        std::cerr << "usage: ./stdAlgoV1 [file_name]\n";
        return 1;
    }
    if (!stream.is_open()) {
        std::cerr << "error\n";
        return 1;
    }
    for (int i = 0; !stream.fail(); i++) {
        stream >> str;
        list.push_front(str);
    }
    return 0;
}

void algorithm(std::forward_list<std::string> &list) {
    list.remove_if([](const std::string &str) {
        return std::find_if(str.begin(), str.end(), [](const char &c) {
            return (c == 'c' || c == 'b' || c == 'l');
        }) != str.end();
    });
    std::replace_if(
        list.begin(), list.end(), [](const std::string &str) {
            return str.size() > 10;
        },
        "Long one");
    std::replace_if(
        list.begin(), list.end(), [](const std::string &str) {
            return str.size() < 4;
        },
        "Short one");
    list.unique();
    list.sort();
    list.reverse();
}


int main(int argc, char **argv) {
    std::forward_list<std::string> list;
    if (error(argc, argv, list) > 0)
        return 1;
    algorithm(list);
    std::string s(argv[1]) ;
    std::ofstream sout(s + "_mod");
    for (auto &it : list) {
        sout << it << "\n";
    }
}
