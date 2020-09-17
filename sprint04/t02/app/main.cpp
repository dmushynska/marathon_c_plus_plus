#include <iostream>
#include <map>

#include "../utils/algorithmUtils.h"
#include "src/test.h"

int main(int argc, char *argv[]) {
    if (argc != 2) {
        std::cerr << "usage: ./dragonborn [action]\n";
    } else {
        try {
            const static std::map<std::string, Dragonborn::Actions> map{
                {"shout", Dragonborn::Actions::Shout},
                {"magic", Dragonborn::Actions::Magic},
                {"weapon", Dragonborn::Actions::Weapon},
            };
            Dragonborn d;
            d.executeAction(map.at(argv[1]));
        }
        catch (...) {
            std::cerr << "Invalid action\n";
        }
    }
}
