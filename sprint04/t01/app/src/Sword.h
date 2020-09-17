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