#include "all.h"
void die_and_plus_one_year(std::list<Rabbit> &rlist) {
    for (auto &it : rlist) {
        it.age++;
    }
    rlist.remove_if([](const Rabbit &a) {
        return ((a.isVampire == true && a.age == 9) || (a.isVampire == false && a.age == 4));
    });
}

void catch_someone(std::list<Rabbit> &rlist) {
    for (auto &it : rlist) {
        if (it.isVampire == false) {
            it.isVampire = true;
            return;
        }
    }
}

void burn(std::list<Rabbit> &rlist) {
    int female = std::count_if(rlist.begin(), rlist.end(), FEM),
        male = std::count_if(rlist.begin(), rlist.end(), MEN),
        who_be;

    for (int i = (female < male) ? female : male; i > 0; i--) {
        who_be = srandom(100);
        if (who_be > 50) {
            rlist.push_back({Gender::Female, false, 0});
        } else if (srandom(100) == 99) {
            if (srandom(1) == 1)
                rlist.push_back({Gender::Female, true, 0});
            else
                rlist.push_back({Gender::Male, true, 0});
        } else {
            rlist.push_back({Gender::Male, false, 0});
        }
    }
}

void algorithm(std::list<Rabbit> &rlist) {
    int Va = VAMPIRE;
    for (int i = 0; i < Va; i++)
        catch_someone(rlist);
    die_and_plus_one_year(rlist);
    burn(rlist);

    std::this_thread::sleep_for(std::chrono::seconds(1));
}
