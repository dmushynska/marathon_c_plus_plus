#include <iostream>
#include <map>
#include <regex>
#include <string>

#include "../utils/algorithmUtils.h"
#include "src/test.h"

long long op(Digit a, Digit b, const std::string &manip) {
    if (manip == "*") {
        return a.GetDigit() * b.GetDigit();
    } else if (manip == "/") {
        return a.GetDigit() / b.GetDigit();
    } else if (manip == "-") {
        return a.GetDigit() - b.GetDigit();
    } else {
        return a.GetDigit() + b.GetDigit();
    }
}

template <typename RandIt>
void operetion(std::map<std::string, long long> &map, RandIt begin, RandIt end) {
    Digit a, b;

    if (check_all_is_digit(map, *begin, *(begin + 2), a, b) == false)
        return;
    else if (*(begin + 1) == "/" && b.GetDigit() == 0) {
        std::cout << "division by zero" << std::endl;
        return;
    } else if (*end != '\0') {
        map[*end] = (long long)op(a, b, *(begin + 1));
    }
    std::cout << ":> " << op(a, b, *(begin + 1)) << std::endl;
}

int main(int argc, char *argv[]) {
    std::regex r(
        R"(\s*([a-zA-Z]+|[\-\+]?[0-9]+)\s*([\+\-\*\/])\s*([a-zA-Z]+|[\-\+]?[0-9]+)\s*(?:=\s*([a-zA-Z]+))?\s*)");
    std::map<std::string, long long> map;
    std::cout << ":> ";

    for (std::string line; std::getline(std::cin, line, '\n'); std::cout << ":> ") {
        std::smatch result;
        if (line.empty())
            continue;
        else if (line == "quit") {
            return 0;
        }
        if (std::regex_match(line, result, r)) {
            operetion(map, result.begin() + 1, result.end() - 1);
        } else {
            std::cout << "invalid input\n";
        }
    }
}
