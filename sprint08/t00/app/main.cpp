#include "player.h"

template <typename T>
bool IsInRange(const T& val, const T& from, const T& to) {
    return (val >= from && val <= to);
}

int main(int argc, char** argv) {
    srand(time(0));
    if (argc != 3) {
        std::cerr << "usage: ./smartPointers [width] [height]\n";
        return 1;
    }
    size_t x = std::stoi(argv[1]), y = std::stoi(argv[2]);
    if (IsInRange(x, (size_t)5, (size_t)20) != true || IsInRange(y, (size_t)5, (size_t)20) != true) {
        std::cerr << "Invalid map size\n";
        return 1;
    }

    Player* play = new Player;
    std::shared_ptr<Player> ptr_play(play);
    Map* map = new Map(x, y, ptr_play);
    std::shared_ptr<Map> ptr_map(map);
    MoveManager move(ptr_play, ptr_map);
    ptr_map->outputMap();
    std::string command;
    std::regex r(R"/s*([a-z]+)/s*");
    std::smatch result;
    std::cout << ":> ";
    while (std::getline(std::cin, command)) {
        if (std::regex_match(command, result, r)) {
            if (*(result.begin()) == "e") {
                return 0;
            }
            move.processInputAndMove(*(result.begin()));
        } else {
            std::cout << "invalid input" << std::endl;
        }
        std::cout << ":> ";
    }
}