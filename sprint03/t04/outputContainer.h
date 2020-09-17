#pragma once
#include <iostream>

template <typename Container>
void outputContainer(const Container& container) {
    std::ostream_iterator<typename Container::value_type> out_it(std::cout, "\n");
    std::copy(std::begin(container), std::end(container), out_it);
}
