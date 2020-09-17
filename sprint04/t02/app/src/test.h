#pragma once
#include <iostream>
#include <map>
#include <functional>


class Dragonborn final {
public:
    enum class Actions {
        Shout,
        Magic,
        Weapon,
        Invalid
    };

    void executeAction(const Actions action) {
        const static std::map<Actions, void (Dragonborn::*)() const> map {
            {Actions::Shout, &Dragonborn::shoutThuum},
            {Actions::Magic, &Dragonborn::attackWithMagic},
            {Actions::Weapon, &Dragonborn::attackWithWeapon},
        };

        std::invoke(map.at(action), this);
    }

private:
    void shoutThuum() const {
        std::cout << "Yol Toor Shul\n";
    }
    void attackWithMagic() const {
        std::cout << "*attacks with magic spell*\n";
    }
    void attackWithWeapon() const {
        std::cout << "*attacks with weapon*\n";
    }
};