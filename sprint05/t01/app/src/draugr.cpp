#include "draugr.h"

Draugr::Draugr()
    : Draugr(100, 50) {}
Draugr::Draugr(double health) : Draugr(health, 50) {}
Draugr::Draugr(double health, int frostResist) : m_health(health), m_frostResist(frostResist) {
    std::cout << "Draugr with " << m_health << " health, " << m_frostResist << "% frost resist was born!\n";
}

void Draugr::shoutPhrase(int shoutNumber) const {
    std::cout << "Draugr (" << m_health << " health, " << m_frostResist << "% frost resist) shouts:\n";

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
