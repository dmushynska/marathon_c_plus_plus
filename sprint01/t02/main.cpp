#include <deque>
#include <iostream>
#include <sstream>
#include <string>

struct Country {
    std::string country;
    int stamina;
    int distance;
};

bool parse_str(std::string &str, Country &c) {
    std::stringstream s(str);

    int i;
    std::cin >> i;

    getline(s, c.country, ',');
    if (s.fail() || c.country.empty())
        return false;
    s >> c.stamina;
    // std::cout << "stam "<< c.stamina << "\n";
    if (s.peek() != ',' || s.fail())
        return false;
    s.ignore(1);
    s >> c.distance;
    // std::cout << "dist " << c.distance << "\n";
    if (s.fail())
        return false;
    return true;
}

void parse_argv(int argc, char **argv, int &error, std::deque<Country> &d) {
    Country c;
    for (int i = 1; i < argc; i++) {
        std::string s(argv[i]);
        if (parse_str(s, c) == false) {
            error = i;
            break;
        } else {
            d.push_back(c);
        }
    }
}

void print(const std::deque<Country> &d, int pos) {
    size_t size = d.size();
    for (int i = pos; i < size; i++) {
        std::cout << i << ". " << d[i].country << '\n';
    }
    for (int i = 0; i < pos; i++) {
        std::cout << i << ". " << d[i].country << '\n';
    }
}

bool algorithm(const std::deque<Country> &d, int pos) {
    int res = 0;

    for (int i = pos; i < d.size(); i++) {
        res = (res + d[i].stamina) - d[i].distance;
        if (res < 0)
            return false;
    }
    for (int i = 0; i < pos; i++) {
        res = (res + d[i].stamina) - d[i].distance;
        if (res < 0)
            return false;
    }
    return true;
}

int main(int argc, char **argv) {
    int error = 0;

    if (argc == 1) {
        std::cerr << "usage: ./visitAll [[name,stamina,distance] ...]\n";
        return 1;
    }
    std::deque<Country> d;
    parse_argv(argc, argv, error, d);
    if (error != 0) {
        std::cerr << "Argument " << argv[error] << " is not valid\n";
        return 1;
    }
    for (int i = 0; i < d.size(); i++) {
        if (algorithm(d, i) == true) {
            error = 0;
            print(d, i);
            break;
        }
        error = 1;
    }
    if (error == 1) {
        std::cerr << "Mission: Impossible\n";
        return 1;
    }
    return 0;
}