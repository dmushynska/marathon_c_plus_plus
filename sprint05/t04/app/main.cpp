#include <iostream>

#include "src/imperial.h"
template <typename T>
bool IsInRange(const T& val, const T& from, const T& to) {
    return (val >= from && val <= to);
}
void the_fight(int weapon_1, int weapon_2) {
    Axe *axe = new Axe(weapon_1);
    Sword *sword = new Sword(weapon_2);
    Imperial i;
    Stormcloak s;

    i.setWeapon(axe);
    s.setWeapon(sword);
    std::cout << "\n***The battle has begun!***\n\n";
    while (i.getHealth() > 0 && s.getHealth() > 0) {
        s.attack(i);
        i.attack(s);
        std::cout << "<<<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>>\n";
    }
    if (i.getHealth() > 0)
        std::cout << "Imperial has won!\n" << std::endl;
    else
        std::cout << "Stormcloak has won!\n" << std::endl;
}

int main(int argc, char* argv[]) {
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
