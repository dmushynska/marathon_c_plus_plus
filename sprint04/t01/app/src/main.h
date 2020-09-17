#pragma once

class Sword final {
    public:
        Sword(int damage) : m_damage(damage) {};
        int getDamage() const {
            return m_damage;
        }

    private:
        const int m_damage;
};


class Imperial final {
    public:
        Imperial(int weapon_);
        ~Imperial();
        void setWeapon(class Axe *sword);
        void attack(Stormcloak& enemy);
        void consumeDamage(int amount);
        int getHealth() const;

    private:
        Sword* m_weapon;
        int m_health = 100;
};