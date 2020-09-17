#include "referenceOrPointer.h"

void multiplyByPointer(int* ptr, int mult) {
    *ptr *= mult;
}

void multiplyByReference(int& ref, int mult) {
    ref *= mult;
}

// int main() {
//     int a = 3;
//     int &b = a;
//     multiplyByPointer(&a, a);
//     std::cout << a << std::endl; // 9
//     multiplyByReference(b, a);
//     std::cout << b << std::endl; // 81
// }