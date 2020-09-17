
#include "src/all.h"

void print(std::list<Rabbit> &rlist) {
    std::cout << "Males: " << std::count_if(rlist.begin(), rlist.end(), MEN)
              << "\n";
    std::cout << "Females: " << std::count_if(rlist.begin(), rlist.end(), FEM)
              << "\n";
    std::cout << "Vampires: " << VAMPIRE << "\n" << std::endl;
}


int main() {
    srand(time(0));
    std::list<Rabbit> rlist;
    int rand = srandom(1);
    if (rand == 1) {
        rlist.push_back({Gender::Female, true, 0});
        rand = srandom(9);
    } else
        rand = srandom(10);
    for (int i = 0; i < rand; i++)
        rlist.push_back({Gender::Female, false, 0});
    for (int i = 0; i < 10 - rand; i++)
        rlist.push_back({Gender::Male, false, 0});
    while (rlist.size() < 1000 && rlist.size() != 0) {
        print(rlist);
        algorithm(rlist);
    }
}