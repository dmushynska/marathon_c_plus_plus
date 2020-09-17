#pragma once
#include <ctime>
#include <iostream>
#include <list>
#include <random>
#include <string>
#include <chrono>
#include <thread>
#define FEM [](const Rabbit &a) {                              \
    return Gender::Female == a.gender && a.isVampire == false; \
}
#define MEN [](const Rabbit &a) {                            \
    return Gender::Male == a.gender && a.isVampire == false; \
}
#define VAMPIRE std::count_if(rlist.begin(), rlist.end(), [](const Rabbit &a) { \
    return a.isVampire == true;                                                 \
})
enum class Gender {
    Male,
    Female
};

struct Rabbit {
    Gender gender;
    bool isVampire;
    int age;
};

void print(std::list<Rabbit> &rlist);
void die_and_plus_one_year(std::list<Rabbit> &rlist);
void catch_someone(std::list<Rabbit> &rlist);
void burn(std::list<Rabbit> &rlist);
void algorithm(std::list<Rabbit> &rlist);
int srandom(int x);
bool operator==(const Rabbit &a, const Rabbit &b);