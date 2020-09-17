#pragma once
#include <algorithm>
#include <iostream>
#include <map>
#include "../../utils/algorithmUtils.h"

class Digit {
public:
    Digit() = default;

    explicit Digit(int x) {
        digit = x;
    }

    Digit &operator=(int x) {
        digit = x;
        return *this;
    }

    long long GetDigit() {
        return digit;
    }

private:
    long long digit = 0;
};

long long check_if_is_in_map(std::map<std::string, long long> &map, const std::string &x);
bool check_all_is_digit(std::map<std::string, long long> &map, std::string x, std::string y, Digit &a, Digit &b);
