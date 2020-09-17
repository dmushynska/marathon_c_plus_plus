#include <algorithm>
#include <forward_list>
#include <fstream>
#include <iostream>
#include <sstream>

struct Name {
    int size = 0;
    bool rich = false;
    bool length = false;
    bool vel = true;
    int mel;
};

bool vel_is_in_str(const std::string &str) {
    int size = str.size();
    return (str[size - 1] == 'l' && str[size - 2] == 'e' && str[size - 3] == 'v');
}

void print(struct Name &name) {
    std::cout << "size: " << name.size << "\n"
              << "contains 'rich': " << (name.rich == true ? "true" : "false")
              << "\n"
              << "none of lengths is 15: "
              << (name.length == true ? "true" : "false") << "\n"
              << "all end with 'vel': "
              << (name.vel == true ? "true" : "false") << "\n"
              << "not contains 'mel': " << name.size - name.mel << "\n";
}

void parse_name(struct Name &name, const std::forward_list<std::string> &list) {
    name.length = std::none_of(list.begin(), list.end(), [](const std::string &str) {
        return str.size() == 15;
    });
    name.rich = std::count_if(list.begin(), list.end(), [](const std::string &str) {
        return str.find("rich") != std::string::npos;
    });
    name.vel = std::any_of(list.begin(), list.end(), [](const std::string &str) {
        return vel_is_in_str(str);
    });
    name.mel = std::count_if(list.begin(), list.end(), [](const std::string &str) {
        return (str.find("mel") != std::string::npos);
    });
}

int main(int argc, char **argv) {
    std::string str;
    std::ifstream stream(argv[1]);
    std::forward_list<std::string> list;
    struct Name name;

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
        name.size = i;
    }
    list.pop_front();
    parse_name(name, list);
    print(name);
}