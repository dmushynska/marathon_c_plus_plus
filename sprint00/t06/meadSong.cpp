#include "meadSong.h"
void first(int index) {
    std::string str = "of mead on the wall, ";
    std::string str1 = "of mead.";
    if (index == 0)
        std::cout << NOMORE << MANY << str << NO_MORE << MANY << str1 << "\n";
    else if (index == 1)
        std::cout << index << ONE << str << index << ONE << str1 << "\n";
    else
        std::cout << index << MANY << str << index << MANY << str1 <<"\n";
}

void second(int index) {
    std::string str = "down and pass it around, ";
    std::string str1 = "of mead on the wall.\n\n";
    if (index == 0) {
        std::cout << GOTO << 99 << MANY << str1;
    }
    else if (index == 1) {
        std::cout << TAKEIT << str << NO_MORE << MANY << str1;
    }
    else if (index == 2) {
        std::cout << TAKEONE << str << 1 << ONE << str1;
    }
    else {
        std::cout << TAKEONE << str << (index - 1) << MANY << str1;
    }
}

void meadSong(void) {
    for (int i = 100; i >= 0; i--) {
        first(i);
        second(i);
    }
}