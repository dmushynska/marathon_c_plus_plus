#include "draugr.h"

void Draugr::setName(const std::string &name) {
    m_name = name;
}

Draugr::Draugr()
    : Draugr(100, 50) {}
Draugr::Draugr(double health) : Draugr(health, 50) {}

Draugr::Draugr(double health, int frostResist) : m_health(health), m_frostResist(frostResist) {
    std::cout << "Draugr (" << m_health << " health, " << m_frostResist << "% frost resist was born!\n";
}

// Draugr::Draugr(Draugr &d) : m_health(d.m_health), m_frostResist(d.m_frostResist), m_name(d.m_name) {
//     std::cout << "Copy constructor was called\n";
// }

// Draugr::Draugr(Draugr &&d) : m_health(d.m_health), m_frostResist(d.m_frostResist), m_name(std::move(d.m_name)) {
//     std::cout << "Move constructor was called\n";
// }



void Draugr::shoutPhrase(int shoutNumber) const {
    std::cout << "Draugr " << m_name <<" (" << m_health << " health, " << m_frostResist << "% frost resist) shouts:\n";

    switch (shoutNumber) {
        case 0:
            std::cout << "Qiilaan Us Dilon!" << std::endl;
            break;
        case 1:
            std::cout << "Bolog Aaz, Mal Lir!" << std::endl;
            break;
        case 2:
            std::cout << "Kren Sosaal!" << std::endl;
            break;
        case 3:
            std::cout << "Dir Volaan!" << std::endl;
            break;
        case 4:
            std::cout << "Aar Vin Ok!" << std::endl;
            break;
        case 5:
            std::cout << "Unslaad Krosis!" << std::endl;
            break;
        case 6:
            std::cout << "Faaz! Paak! Dinok!" << std::endl;
            break;
        case 7:
            std::cout << "Aav Dilon!" << std::endl;
            break;
        case 8:
            std::cout << "Sovngarde Saraan!" << std::endl;
            break;
    }
}
