#pragma once

template <class Container>
void squareValue(Container& container) {
    for (typename Container::iterator it = std::begin(container);
                                        it != std::end(container); it++)
        *it *= *it;
}