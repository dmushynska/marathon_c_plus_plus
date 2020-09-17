#include "ISpell.h"

#include "creature.h"

const std::string &return_value(Spells::SpellType type) {
    static const std::map<Spells::SpellType, std::string> map{
        {Spells::SpellType::Healing, "healing"},
        {Spells::SpellType::Equilibrium, "equilibrium"},
        {Spells::SpellType::Flames, "flames"},
        {Spells::SpellType::Freeze, "freeze"},
        {Spells::SpellType::Fireball, "fireball"},
    };
    return map.at(type);
}

bool Spells::Healing::cast(Creatures::Creature& owner, Creatures::Creature& other) {
    static_cast<void>(other);
    if (owner.getMana() > 14) {
        owner.setHealth(10);
        owner.setMana(-15);
        return true;
    }
    return false;
}

bool Spells::Equilibrium::cast(Creatures::Creature& owner, Creatures::Creature& other) {
    static_cast<void>(other);
    if (owner.getHealth() > 24) {
        owner.setHealth(-25);
        owner.setMana(25);
        return true;
    }
    return false;
}

bool Spells::Flames::cast(Creatures::Creature& owner, Creatures::Creature& other) {
    if (owner.getMana() > 13) {
        owner.setMana(-14);
        other.setHealth(-8);
        return true;
    }
    return false;
}

bool Spells::Freeze::cast(Creatures::Creature& owner, Creatures::Creature& other) {
    if (owner.getMana() > 29) {
        owner.setMana(-30);
        other.setHealth(-20);
        return true;
    }
    return false;
}

bool Spells::Fireball::cast(Creatures::Creature& owner, Creatures::Creature& other) {
    if (owner.getMana() > 49) {
        owner.setMana(-50);
        other.setHealth(-40);
        return true;
    }
    return false;
}

bool operator==(Spells::ISpell& lhs, Spells::ISpell& rhs) {
    return (lhs.getType() == rhs.getType());
}

std::ostream& operator<<(std::ostream& os, const Creatures::Creature& creature) {
    os << creature.getName() << " : " << creature.getHealth() << " HP, " << creature.getMana() << " MP.";
    return os;
}
