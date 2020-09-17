#include "inventory.h"

void show(const std::vector<char> &v) {
    int x = 12;

    std::cout << "Inventory { ";
    for (auto it : v) {
        std::cout << it << " ";
        --x;
    }
    for (int i = x; i > 0; i--) {
        std::cout << "- ";
    }
    std::cout << "}\n";
}