#include <iostream>
#include "src/Axe.h"
#include "src/Sword.h"
#include "src/imperial.h"
#include "src/stormcloak.h"

#include "../utils/algorithmUtils.h"

void the_fight(int weapon_1, int weapon_2) {
    Imperial i(weapon_1);
    Stormcloak s(weapon_2);
    while (i.getHealth() > 0 && s.getHealth() > 0) {
        std::cout << "<<<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>>\n";
        i.attack(s);
        std::cout << "Imperial soldier attacks and deals "<< weapon_1
            << " damage\n"
            << "Stormcloak soldier consumes " << weapon_1 << " of damage\n";
        s.attack(i);
        std::cout << "Stormcloak soldier attacks and deal "<< weapon_2 <<" damage\n"
        << "Imperial soldier consumes " << weapon_2 << " of damage" << std::endl;
    }
    std::cout << "<<<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>>\n";
    if (i.getHealth() > 0)
        std::cout << "Imperial has won!" << std::endl;
    else if (i.getHealth() <= 0 && s.getHealth() <= 0)
        std::cout << "Imperial has won!" << std::endl;
    else
        std::cout << "Stormcloak has won!" << std::endl;
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        std::cerr << "usage: ./imperialVsStormcloak [dmgOfSword] [dmgOfAxe]\n";
        return 1;
    }
    int weapon_1 = std::stoi(argv[1]), weapon_2 = std::stoi(argv[2]); 
    if (IsInRange(weapon_1, 10, 20) != true || IsInRange(weapon_2, 10, 20) != true) {
        std::cerr << "Damage has to be in a range of 10-20 points.\n";
        return 1;
    }
    the_fight(weapon_1, weapon_2);
    return 0;
}
