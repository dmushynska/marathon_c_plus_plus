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

void logic(char *number) {
    Draugr().shoutPhrase(parse(number));
}

int main(int ac, char **av) try {
    if (ac == 2) {
        logic(av[1]);
    } else {
        throw std::invalid_argument("usage: ./draugr [shoutNumber]");
    }
} catch (std::exception &ex) {
    std::cerr << ex.what() << std::endl;
    return EXIT_FAILURE;
}
