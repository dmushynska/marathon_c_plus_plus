#include "food.h"

void print(FoodType type) {
    if (type == FoodType::ApplePie)
        std::cout << "Apple pie. Ugh, not again!\n";
    else if (type == FoodType::PoisonedFood)
        std::cout << "Poison. Ugh, not again!\n";
    else if (type == FoodType::Invalid)
        std::cout << "<wtf>. Ugh, not again!\n";
    else if (type == FoodType::HoneyNut) {
        std::cout << "Honey nut. Mmm, tasty!\n";
    } else if (type == FoodType::Sweetroll) {
        std::cout << "Sweetroll. Mmm, tasty!\n";
    }
}
