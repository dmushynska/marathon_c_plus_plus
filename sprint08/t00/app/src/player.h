#pragma once
#include <ctime>
#include <iostream>
#include <memory>
#include <random>
#include <regex>
#include <string>

inline int crandom(int x) {
    return rand() % x;
}

class Player;
class Map;

class MoveManager final {
public:
    enum class Direction {
        Up,
        Down,
        Left,
        Right
    };

    MoveManager(std::shared_ptr<Player>& player, std::shared_ptr<Map>& map);

    ~MoveManager() = default;

    void processInputAndMove(const std::string& inputStr);

private:
    bool checkMove(Direction dir) const;
    std::shared_ptr<Map> m_map;
    std::shared_ptr<Player> m_player;
};

class Player final {
public:
    Player() = default;

    ~Player() = default;

    void movePlayer(MoveManager::Direction dir) {
        if (dir == MoveManager::Direction::Right) {
            m_posX++;
        } else if (dir == MoveManager::Direction::Left) {
            m_posX--;
        } else if (dir == MoveManager::Direction::Up) {
            m_posY--;
        } else if (dir == MoveManager::Direction::Down){
            m_posY++;
        }
    }

    char getIdentifier() const {
        return 'P';
    }

    size_t posX() const {
        return m_posX;
    }

    size_t posY() const {
        return m_posY;
    }

private:
    size_t m_posX{0};
    size_t m_posY{0};
};

class Map final {
public:
    Map(size_t width, size_t height, std::shared_ptr<Player>& player) : m_width(width), m_height(height), m_player(player) {
        generateMap();
    }

    ~Map() = default;

    void outputMap() const {
        size_t iterator = 0;
        for (size_t i = 0; i < m_height; i++) {
            for (size_t j = 0; j < m_width; j++, iterator++) {
                if (j == m_player->posX() && i == m_player->posY()) {
                    std::cout << m_player->getIdentifier();
                } else {
                    std::cout << m_map[iterator];
                }
                std::cout << " ";
            }
            std::cout << std::endl;
        }
    }

    size_t width() const {
        return m_width;
    }

    size_t height() const {
        return m_height;
    }

private:
    void generateMap() {
        size_t size = m_width * m_height;
        char* map = (char*)malloc(sizeof(char) * (size + 1));
        map[size] = '\0';
        size_t rand_int = 0;

        for (size_t i = 0; i < size; i++) {
            rand_int = crandom(3);
            if (rand_int == 1) {
                map[i] = '.';
            } else if (rand_int == 2) {
                map[i] = '@';
            } else {
                map[i] = 'T';
            }
        }
        std::unique_ptr<char[]> nmap(map);
        m_map = std::move(nmap);
    }

    const size_t m_width{0};
    const size_t m_height{0};
    std::shared_ptr<Player> m_player;
    std::unique_ptr<char[]> m_map;
};