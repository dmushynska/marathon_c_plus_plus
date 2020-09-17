#include "inventory.h"

void remove(const char &a, std::vector<char> &v) {
    if (std::count(v.begin(), v.end(), a) <= 0) {
        std::cerr << "Invalid item.\n";
        return;
    }

    for (int i = 0; i < v.size(); i++)
        if (v[i] == a) {
            v.erase((v.begin() + i));
            break;
        }
    std::cout << a << "was removed.";
}