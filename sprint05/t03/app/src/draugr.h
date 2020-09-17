#pragma once
#include <iostream>
#include <string>

class Draugr {
    double m_health;
    const int m_frostResist;

protected:
    // Draugr();
    // ~Draugr();
    Draugr(Draugr& other);
    Draugr(Draugr&& other);

public:
    Draugr();
    explicit Draugr(double health);
    explicit Draugr(double health, int frostResist);

    void shoutPhrase(int shoutNumber) const;
    void setName(const std::string& name);
    std::string m_name;
};
