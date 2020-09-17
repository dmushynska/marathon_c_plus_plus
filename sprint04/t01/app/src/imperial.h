#pragma once
#include "Sword.h"
#include "Axe.h"
class Imperial;
class Stormcloak final {
    public:
        Stormcloak(int weapon_);
        ~Stormcloak();
        void setWeapon(class Sword *sword);
        void attack(Imperial& enemy);
        void consumeDamage(int amount);
        int getHealth() const;

    private:
        Axe* m_weapon = nullptr;
        int m_health = 100;
};

class Imperial final {
   public:
    Imperial(int weapon_) {
        m_weapon = new Sword(weapon_);
    }
    ~Imperial() {
        delete m_weapon;
    }
    void setWeapon(class Axe* sword) {
        consumeDamage(sword->getDamage());
    }
    void attack(Stormcloak& enemy) {
        enemy.setWeapon(m_weapon);
    }
    void consumeDamage(int amount) {
        m_health -= amount;
    }
    int getHealth() const {
        return m_health;
    }

   private:
    Sword* m_weapon = nullptr;
    int m_health = 100;
};
