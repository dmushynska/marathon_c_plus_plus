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

void logic(int number, double health, int frostResist) {
    if (health == 0 && frostResist == 0)
        Draugr().shoutPhrase(number);
    else if (frostResist == 0) {
        Draugr d(health);
        d.shoutPhrase(number);
    } else {
        Draugr d(health, frostResist);
        d.shoutPhrase(number);
    }
}

int main(int ac, char **av) try {
    if (ac > 1 && ac < 5) {
        double health = 0;
        int frostResist = 0;
        try {
            if (ac == 3 || ac == 4)
                health = std::stod(av[2]);
            if (ac == 4)
                frostResist = std::stoi(av[3]);
            if (frostResist > 100)
                throw std::invalid_argument("Error");
        } catch (...) {
            throw std::invalid_argument("Error");
        }
        logic(parse(av[1]), health, frostResist);
    } else {
        throw std::invalid_argument("usage: ./draugr [shoutNumber] [health] [frostResist]\n");
    }
} catch (std::exception &ex) {
    std::cerr << ex.what() << std::endl;
    return EXIT_FAILURE;
}
