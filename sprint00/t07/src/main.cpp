#include "inventory.h"
static void exit() {
    std::cout << "Bye.\n";
}

int insert_command(char &a, std::string &command) {
    std::cin >> command;
    if (command == "insert" || command == "remove") {
        std::cin >> a;
        if (a != 'w' && a != 'p' && a != 'f' && a != 'a') {
            if (std::cin.peek() != '\n') {
                std::getline(std::cin, command);
                return 1;
            }
            return 2;
        }
    }
    if (std::cin.peek() != '\n') {
        std::getline(std::cin, command);
        return 1;
    }
    return 0;
}

int main() {
    char a;
    std::string command;
    std::vector<char> v;

    while (1) {
        std::cout << "Enter command:> ";
        int check = insert_command(a, command);
        if (command == "insert" && check != 1 && check != 2) {
            insert(a, v);
        } else if (command == "remove" && check != 1 && check != 2) {
            remove(a, v);
        } else if (command == "show" && check != 1 && check != 2) {
            show(v);
        } else if (command == "help" && check != 1 && check != 2) {
            help();
        } else if (command == "exit" && check != 1 && check != 2) {
            exit();
            return 0;
        } else if (check == 2) {
            std::cerr << "Invalid item.\n";
        } else {
            std::cerr << "Invalid command.\n";
        }
    }
    return 0;
}