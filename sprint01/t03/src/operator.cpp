#include "all.h"

static auto rank(const Rabbit &r) {
    return std::tie(r.age, r.gender, r.isVampire);
}

bool operator==(const Rabbit &a, const Rabbit &b) {
    return rank(a) == rank(b);
}

int srandom(int x) {
    return rand() % x;
}
