#include "test.h"

long long check_if_is_in_map(std::map<std::string,signed long long> &map, const std::string &x, int y) {
    if (std::isdigit(x[0]) == false && x[0] != '+' && x[0] != '-') {
        if (map.count(x) == 0)
            throw std::logic_error("invalid operand" + std::to_string(y));
    }
    try {
        return std::stoi(x);
    } catch (...) {
        throw std::logic_error("operand" + std::to_string(y) + " is out of range");
    }

}

bool check_all_is_digit(std::map<std::string,signed long long> &map, std::string x, std::string y, Digit &a, Digit &b) {
    try {
        a = check_if_is_in_map(map, x, 1), b = check_if_is_in_map(map, y, 2);
    } catch (std::exception &ex) {
        std::cout << ex.what() << std::endl;
        return false;
    }
        return true;
}
