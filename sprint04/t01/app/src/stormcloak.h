#pragma once
#include "imperial.h"

    Stormcloak::Stormcloak(int weapon_) {
        m_weapon = new Axe(weapon_);
    }
    Stormcloak::~Stormcloak() {
        delete m_weapon;
    }
    void Stormcloak::setWeapon(class Sword *sword) {
        consumeDamage(sword->getDamage());
    }
    void Stormcloak::attack(Imperial& enemy) {
        enemy.setWeapon(m_weapon);
    }
    void Stormcloak::consumeDamage(int amount) {
        m_health -= amount;
    }
    int Stormcloak::getHealth() const {
        return m_health;
    }