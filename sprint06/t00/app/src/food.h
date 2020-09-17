#pragma once
#include <iostream>
#include <string>

enum class FoodType {
    ApplePie,
    HoneyNut,
    Sweetroll,
    PoisonedFood,
    Invalid
};

class FoodItem {
public:
    virtual const std::string &getName() const = 0;
    virtual ~FoodItem() = default;
};

class ApplePie : public FoodItem {
    static inline const std::string food = "Apple pie";

public:
    const std::string &getName() const override {
        return food;
    }
};

class HoneyNut : public FoodItem {
    static inline const std::string food = "Honey nut";

public:
    const std::string &getName() const override {
        return food;
    }
};

class Sweetroll : public FoodItem {
    static inline const std::string food = "Sweetroll";

public:
    const std::string &getName() const override {
        return food;
    }
};

class PoisonedFood : public FoodItem {
    static inline const std::string food = "Poison";

public:
    const std::string &getName() const override {
        return food;
    }
};

class AbstractWizard {
protected:
    AbstractWizard() = default;
    ~AbstractWizard() = default;
    FoodType deductFoodType(FoodItem &item) {
        if (item.getName() == "Apple pie")
            return FoodType::ApplePie;
        else if (item.getName() == "Honey nut")
            return FoodType::HoneyNut;
        else if (item.getName() == "Sweetroll")
            return FoodType::Sweetroll;
        else if (item.getName() == "Poison")
            return FoodType::PoisonedFood;
        else
            return FoodType::Invalid;
    }
};

void print(FoodType type);

class MightyWizard : public AbstractWizard {
public:
    MightyWizard(std::string &name) : m_name(name) {}
    void checkFood(FoodItem &food_item) {
        print(deductFoodType(food_item));
    }
    void checkFood(FoodItem *food_item) {
        if (food_item == nullptr) {
            std::cout << "<wtf>. Ugh, not again!\n";
        } else {
            checkFood(*food_item);
        }
    }

private:
    std::string m_name;
};
