#include <regex>

#include "draugr.h"
int parse(std::string str) try {
    std::size_t index;
    int num = std::stoi(str, &index);

    if (num < 0 || num > 8 || index != str.size()) {
        throw std::invalid_argument("Invalid shoutNumber");
    }
    return num;
} catch (...) {
    throw std::invalid_argument("Invalid shoutNumber");
}

void logic(int number, double health, int frostResist, std::string &str, std::string &str1) {
    if (frostResist == 0) {
        Draugr d(health);
        d.setName(std::move(str));
        d.shoutPhrase(number);
        Draugr c(d);
        c.setName(std::move(str1));
        c.shoutPhrase(number);
    } else {
        Draugr d(health, frostResist);
        d.setName(std::move(str));
        d.shoutPhrase(number);
        d.setName(std::move(str1));
        Draugr s(std::move(d));
        s.shoutPhrase(number);
    }
}

int main(int ac, char **av) {
    double health = 0;
    int frostResist = 0;
    std::smatch result;
    try {
        if (ac == 4 || ac == 5) {
            try {
                std::string str(av[2]);
                std::regex r("([a-zA-Z]+),([a-zA-Z]+)");
                if (std::regex_match(str, result, r)) {
                } else {
                    throw std::invalid_argument("invalid input\n");
                }
                if (ac == 4 || ac == 5)
                    health = std::stod(av[3]);
                if (ac == 5)
                    frostResist = std::stoi(av[4]);
                if (health > 100 || frostResist > 100)
                    throw std::invalid_argument("Error");
            } catch (...) {
                throw std::invalid_argument("Error");
            }
            std::string str = *(result.begin() + 1);
            std::string str1 = *(result.begin() + 2);
            logic(parse(av[1]), health, frostResist, str, str1);
        } else {
            throw std::invalid_argument("usage: ./draugr [shoutNumber] [health] [frostResist]\n");
        }
    } catch (std::exception &ex) {
        std::cerr << ex.what() << std::endl;
        return EXIT_FAILURE;
    }
}
