// #include <iostream>
#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
#include <string>

int insert_command(std::string &command, std::string &namebook) {
    std::string new_command;
    getline(std::cin, command);
    std::stringstream s(command);
    s >> command;
    if (command == "add" || command == "delete" || command == "read") {
        s >> namebook;
    }
    s >> new_command;
    if (!s.fail()) {
        std::getline(s, command);
        return 1;
    }
    return 0;
}

void add(std::map<std::string, std::string> &map, const std::string &namebook) {
    std::ifstream sin("./library/" + namebook);
    std::string text;
    if (sin.fail()) {
        std::cerr << "invalid book\n";
        return;
    }
    std::getline(sin, text, '\0');
    map.insert({namebook, text});
    std::cout << namebook << " added" << std::endl;
}

void my_delete(std::map<std::string, std::string> &map, const std::string &namebook) {
    if (map.count(namebook) == 0) {
        std::cerr << "invalid book\n";
    }
    else {
        map.erase(namebook);
        std::cout << namebook << " deleted" << std::endl;
    }
}

void read(std::map<std::string, std::string> &map, const std::string &namebook) {
    if (map.count(namebook) == 0) {
        std::cerr << "invalid book\n";
    }
    else {
        std::string s = map[namebook];
        std::cout << s << std::endl;
    }
}

int main() {
    std::string command, namebook;
    std::map<std::string, std::string> map;

    while (1) {
        std::cout << "Enter command:> ";
        int check = insert_command(command, namebook);
        if (command == "add" && check != 1) {
            add(map, namebook);
        } else if (command == "delete" && check != 1) {
            my_delete(map, namebook);
        } else if (command == "read" && check != 1) {
            read(map, namebook);
        } else if (command == "list" && check != 1) {
            for (auto &it : map)
                std::cout << it.first << std::endl;
        } else if (command == "quit" && check != 1) {
            std::cout << "bye\n";
            break;
        } else {
            std::cerr << "invalid command\n";
        }
    }
    return 0;
}