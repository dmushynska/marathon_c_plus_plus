#include "castSpells.h"

int castFloatToInt(float number) {
    return static_cast<int>(number);
}

int* castToNonConstIntPtr(const int* ptr) {
    return const_cast<int*>(ptr);
}

// int main () {
//   const int a = 3;
//   std::cout << castFloatToInt(3.14) << std::endl
//   << *castToNonConstIntPtr(&a) << std::endl;
// }