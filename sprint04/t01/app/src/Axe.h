#pragma once
class Axe final {
    public:
        Axe(int damage) : m_damage(damage) {};
        int getDamage() const {
            return m_damage;
        }

    private:
        const int m_damage;
};