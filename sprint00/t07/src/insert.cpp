#include "inventory.h"

void insert(const char &a, std::vector<char> &v) {
    if (v.size() < 12) {
        v.push_back(a);
        std::cout << a << " was inserted.\n";
    }
    else
        std::cerr << "Inventory is full.\n";
}