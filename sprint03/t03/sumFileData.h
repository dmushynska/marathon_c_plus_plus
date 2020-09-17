#pragma once
#include <string>
#include <fstream>

template <class T>
T sumFileData(const std::string& fileName) {
    std::ifstream s(fileName);
    std::istream_iterator<T> eos;
    std::istream_iterator<T> iterator(s);
    T d = 0;
    while (iterator != eos) {
        d += *iterator;
        iterator.operator++();
    }
    return d;
}