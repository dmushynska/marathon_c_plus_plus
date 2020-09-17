#include "creature.h"

int main() {
    Creatures::Redguard jojo("JoJo");
    jojo.sayPhrase();

    Creatures::Imperial dio("Dio");
    dio.sayPhrase();

    std::cout << jojo << std::endl << dio << std::endl;
    Spells::ISpell *jojo_healing = new Spells::Healing;
    Spells::ISpell *jojo_fireball = new Spells::Fireball;
    Spells::ISpell *jojo_equilibrium = new Spells::Equilibrium;
    jojo.learnSpell(jojo_healing);
    jojo.learnSpell(jojo_fireball);
    jojo.learnSpell(jojo_equilibrium);

    Spells::ISpell *dio_equilibrium = new Spells::Equilibrium;
    dio.learnSpell(dio_equilibrium);
    dio.learnSpell(dio_equilibrium);

    jojo.castSpell(Spells::SpellType::Fireball, dio);
    dio.castSpell(Spells::SpellType::Equilibrium, jojo);

    std::cout << jojo << std::endl << dio << std::endl;

    Spells::ISpell *dio_flames = new Spells::Flames;
    Spells::ISpell *dio_freeze = new Spells::Freeze;
    dio.castSpell(Spells::SpellType::Flames, jojo);
    dio.learnSpell(dio_flames);
    dio.learnSpell(dio_freeze);
    jojo.castSpell(Spells::SpellType::Healing, jojo);
    dio.castSpell(Spells::SpellType::Freeze, jojo);

    std::cout << jojo << std::endl << dio << std::endl;

    jojo.castSpell(Spells::SpellType::Fireball, dio);
    jojo.castSpell(Spells::SpellType::Fireball, dio);
    jojo.castSpell(Spells::SpellType::Fireball, dio);

    std::cout << jojo << std::endl << dio << std::endl;
}