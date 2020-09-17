#pragma once
#include <iostream>

class Draugr {
    double m_health;
    const int m_frostResist;
public:
    Draugr();
    explicit Draugr(double health);
    explicit Draugr(double health, int frostResist);
    void shoutPhrase(int shoutNumber) const;
};
