#pragma once
#include <iostream>
#include <set>
#include <string>

namespace Creatures {
class Creature;
};

namespace Spells {
enum class SpellType {
    Healing,
    Equilibrium,
    Flames,
    Freeze,
    Fireball
};

class ISpell {
public:
    virtual ~ISpell() = default;
    virtual bool cast(Creatures::Creature& owner, Creatures::Creature& other) = 0;
    virtual SpellType getType() const = 0;
};

class Healing : public ISpell {
public:
    bool cast(Creatures::Creature& owner, Creatures::Creature& other) override;
    SpellType getType() const override {
        return SpellType::Healing;
    }
};

class Equilibrium : public ISpell {
public:
    bool cast(Creatures::Creature& owner, Creatures::Creature& other) override;
    SpellType getType() const override {
        return SpellType::Equilibrium;
    }
};

class Flames : public ISpell {
public:
    bool cast(Creatures::Creature& owner, Creatures::Creature& other) override;
    SpellType getType() const override {
        return SpellType::Flames;
    }
};

class Freeze : public ISpell {
public:
    bool cast(Creatures::Creature& owner, Creatures::Creature& other) override;
    SpellType getType() const override {
        return SpellType::Freeze;
    }
};

class Fireball : public ISpell {
public:
    bool cast(Creatures::Creature& owner, Creatures::Creature& other) override;
    SpellType getType() const override {
        return SpellType::Fireball;
    }
};

}  // namespace Spells

bool operator==(Spells::ISpell& lhs, Spells::ISpell& rhs);
