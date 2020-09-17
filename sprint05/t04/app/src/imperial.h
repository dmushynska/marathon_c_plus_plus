#pragma once
#include <string>

#include "Weapon.h"

class Soldier {
public:
    Soldier(std::string&& name, int health) : m_name(name), m_health(health) {
        std::cout << "Soldier " << m_name << " was created" << std::endl;
    }
    virtual ~Soldier() {
        std::cout << "Soldier " << m_name << " was deleted" << std::endl;
    }

    void attack(Soldier& other) {
        m_health -= other.m_weapon->getDamage();
        std::cout << m_name << " attacks " << other.m_name << " and deals " << m_weapon->getDamage() << " damage" << std::endl;
    }
    void setWeapon(Weapon* weapon) {
        m_weapon = weapon;
    }
    int getHealth() const {
        return m_health;
    }

private:
    Weapon* m_weapon;
    std::string m_name;
    int m_health;
};

class Stormcloak final : public Soldier {
public:
    Stormcloak() : Soldier(std::move("Flynn"), 100) {
        std::cout << "Stormcloak soldier was created" << std::endl;
    }
    ~Stormcloak() {
        std::cout << "Stormcloak soldier was deleted\n";
    }
};

class Imperial final : public Soldier {
public:
    Imperial() : Soldier(std::move("Martin"), 100) {
        std::cout << "Imperial soldier was created" << std::endl;
    }
    ~Imperial() {
        std::cout << "Imperial soldier was deleted\n";
    }
};
