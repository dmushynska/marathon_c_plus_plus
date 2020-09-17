#pragma once
#include <iostream>
#include <string>

class Draugr {
    double m_health;
    const int m_frostResist;
public:
    Draugr();
    void shoutPhrase(int shoutNumber) const;
};
