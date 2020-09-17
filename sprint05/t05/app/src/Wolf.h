#pragma once
#include <iostream>

class Creature {
public:
    Creature() {
        std::cout << "Creature was created\n";
    }
    ~Creature() {
        std::cout << "Creature was deleted\n";
    }
};

class Wolf : virtual public Creature {
public:
    Wolf() = default;
    ~Wolf() = default;
};

class Human : virtual public Creature {
public:
    Human() = default;
    ~Human() = default;
};

class Werewolf final : public Wolf, public Human {
public:
    Werewolf() {
        std::cout << "Werewolf was created\n";
    }
    ~Werewolf() {
        std::cout << "Werewolf was deleted\n";
    }
};
