#pragma once
#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <string>

#include "ISpell.h"
const std::string& return_value(Spells::SpellType type);
namespace Creatures {
class Creature {
public:
    explicit Creature(const std::string& name) : m_name(name) {
        std::cout << m_name << " was born!\n";
    }

    virtual ~Creature() {
        for (auto& it : m_spells)
            delete it;
    }

    void learnSpell(Spells::ISpell* spell) {
        if (std::count_if(m_spells.begin(), m_spells.end(), [spell](Spells::ISpell* spell_copy) {
                return spell->getType() == spell_copy->getType();
            }) == 0) {
            m_spells.insert(spell);
            std::cout << m_name << " has learned " << return_value(spell->getType())
                      << " spell successfully!\n";
        } else {
            std::cout << m_name << " already know " << return_value(spell->getType())
                      << " spell!\n";
        }
    }

    void castSpell(const Spells::SpellType type, Creature& creature) {
        auto it = std::find_if(m_spells.begin(), m_spells.end(), [type](Spells::ISpell* spell) {
            return spell->getType() == type;
        });
        if (it == m_spells.end()) {
            std::cout << return_value(type) << " spell is not learned by " << m_name << ".\n";
        } else if ((*it)->cast(*this, creature) == true) {
            std::cout << m_name << " casted " << return_value(type) << " spell on " << creature.getName() << "!\n";
        } else {
            std::cout << m_name << " can't cast " << return_value(type) << "!\n";
        }
    }

    virtual void sayPhrase() const = 0;

    std::string getName() const {
        return m_name;
    }

    int getHealth() const {
        return m_health;
    }

    int getMana() const {
        return m_mana;
    }

    void setHealth(int health) {
        m_health += health;
    }

    void setMana(int mana) {
        m_mana += mana;
    }

private:
    std::string m_name;
    int m_health = 100;
    int m_mana = 100;
    std::set<Spells::ISpell*> m_spells;
};

class Imperial : public Creature {
public:
    Imperial(const std::string& name) : Creature(name), m_name(name) {}
    void sayPhrase() const override {
        std::cout << "I am " << m_name << ", Imperial soldier! Stop right here!\n";
    }

private:
    const std::string& m_name;
};
class Redguard : public Creature {
public:
    Redguard(const std::string& name) : Creature(name), m_name(name) {}
    void sayPhrase() const override {
        std::cout << "I am " << m_name << " from Redguards, wanna trade?\n";
    }

private:
    const std::string& m_name;
};

}  // namespace Creatures

std::ostream& operator<<(std::ostream& os, const Creatures::Creature& creature);
