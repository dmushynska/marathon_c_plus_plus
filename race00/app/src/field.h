#pragma once
#include <chrono>
#include <ctime>
#include <random>
#include <vector>
#include <fstream>

#include "snakes.h"
#include "texture.h"

inline int crandom(int x) {
    return rand() % x;
}

class Field {
public:
    Field(int x, int y, sf::RenderWindow &wind)
        : m_v(y, std::vector<What_is>(x, What_is::is_space)), window(wind) {}

    void Print_Field() {
        window.clear();

        for (int i = 0; i < m_v.size(); i++) {
            for (int j = 0; j < m_v[0].size(); j++) {
                if (m_v[i][j] == What_is::is_space) {
                    auto &sp = structure.GetSprite(4);
                    sp.setPosition(j * 256, i * 256);
                    window.draw(sp);
                } else if (m_v[i][j] == What_is::is_snake) {
                    auto &sp = structure.GetSprite(0);
                    sp.setPosition(j * 256, i * 256);
                    window.draw(sp);
                } else if (m_v[i][j] == What_is::is_wall) {
                    auto &sp = structure.GetSprite(5);
                    sp.setPosition(j * 256, i * 256);
                    window.draw(sp);
                } else {
                    auto &sp = structure.GetSprite(7);
                    sp.setPosition(j * 256, i * 256);
                    window.draw(sp);
                }
            }
        }
    }

    void print_end_game() {
        window.clear();
        auto &sp = structure.GetSprite(6);
        sp.setPosition(500, 500);
        window.draw(sp);
        window.display();
        window.setFramerateLimit(1);
        std::ofstream sout(".test", std::ios_base::app);
            sout << store << "\n";
    }

    bool check_field(Snakes &s) {
        const auto &old_body = s.get_body_deque();
        int add = 0;
        for (auto &it : m_wall) {
            m_v[it.x][it.y] = What_is::is_wall;
        }
        m_v[apple.x][apple.y] = What_is::is_apple;
        if (old_body.size() > 1 && old_body[0].cordinates.x > -1 && old_body[0].cordinates.x < m_v[0].size() && old_body[0].cordinates.y > -1 && old_body[0].cordinates.y < m_v.size())
            if (m_v[old_body[0].cordinates.y][old_body[0].cordinates.x] == What_is::is_apple) {
                s.eat_apple(old_body[0].cordinates.x, old_body[0].cordinates.y);
                add = 1;
            }
        const auto &body = s.get_body_deque();
        for (int i = 0; i < body.size(); i++) {
            const auto &part = body[i];

            if (body.size() > 1 && part.cordinates.x > -1 && part.cordinates.x < m_v[0].size() && part.cordinates.y > -1 && part.cordinates.y < m_v.size()) {
                if (m_v[part.cordinates.y][part.cordinates.x] == What_is::is_space) {
                    m_v[part.cordinates.y][part.cordinates.x] = What_is::is_snake;
                } else if (m_v[body[0].cordinates.y][body[0].cordinates.x] == What_is::is_apple) {
                    m_v[body[0].cordinates.y][body[0].cordinates.x] = What_is::is_snake;
                } else if (m_v[part.cordinates.y][part.cordinates.x] == What_is::is_wall) {
                    print_end_game();
                    return false;
                } else if (m_v[part.cordinates.y][part.cordinates.x] == What_is::is_snake) {
                    print_end_game();
                    return false;
                }
            } else {
                print_end_game();
                return false;
            }
        }
        if (add == 1) {
            create_apple();
            store++;
        }
        window.setFramerateLimit(24 / body.size());
        return true;
    }

    void
    free_field() {
        for (auto &it : m_v)
            it.assign(it.size(), What_is::is_space);
    }

    void create(const What_is &is, Cordinates &cord) {
        cord.x = crandom(m_v.size());
        cord.y = crandom(m_v[0].size());
        if (m_v[cord.x][cord.y] == What_is::is_space) {
            m_v[cord.x][cord.y] = is;
        } else {
            cord.x = crandom(m_v.size());
            cord.y = crandom(m_v[0].size());
        }
    }

    void create_apple() {
        create(What_is::is_apple, apple);
    }

    void create_wall() {
        Cordinates wall;
        create(What_is::is_wall, wall);
        m_wall.push_back(wall);
    }

    std::vector<std::vector<What_is>> &GetField() {
        return m_v;
    }

private:
    sf::RenderWindow &window;
    Structure structure;
    std::vector<std::vector<What_is>> m_v;
    std::vector<Cordinates> m_wall;
    Cordinates apple;
    int store = 0;
    Cordinates head;
};

void test(int width, int height);
