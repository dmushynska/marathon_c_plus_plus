#pragma once
#include <iostream>

template<class Container>
void outputAny(const Container& c) {
    for (const auto &it : c)
        std::cout << it << std::endl;
}