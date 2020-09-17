#pragma once
#include <SFML/Graphics.hpp>
#include <deque>
#include <iostream>

template <typename Container>
void outputContainer(const Container& container) {
    std::ostream_iterator<typename Container::value_type> out_it(std::cout, "\n");
    std::copy(std::begin(container), std::end(container), out_it);
}

enum class What_is {
    is_head_snake,
    is_snake,
    is_wall,
    is_space,
    is_apple
};

enum class Head {
    is_head,
    is_body,
    is_tail
};

enum class Dir {
    up,
    down,
    right,
    left,
    without
};

enum class Color {
    red = 0,
    blue = 1,
    green = 2,
    orange = 3
};

struct Cordinates {
    int x = 0;
    int y = 0;
};

struct BodyPart {
    Head head;
    Dir dir;
    Cordinates cordinates;
};

inline int set_x(Dir dir, int x) {
    if (dir == Dir::left)
        return x - 1;
    else if (dir == Dir::right)
        return x + 1;
    return x;
}

inline int set_y(Dir dir, int y) {
    if (dir == Dir::down)
        return y + 1;
    else if (dir == Dir::up) {
        return y - 1;
    }
    return y;
}

inline Dir reverse_dir(Dir dir) {
    if (dir == Dir::left)
        return Dir::right;
    else if (dir == Dir::right)
        return Dir::left;
    else if (dir == Dir::down)
        return Dir::up;
    return Dir::down;
}

class Snakes {
    std::deque<BodyPart> m_deque;
    Cordinates tail = {0, 0};
    sf::Clock time_delete;
    sf::Time time = sf::seconds(4);
    Color head = Color::red;
    Color body = Color::blue;

public:
    Snakes(int x, int y) {
        m_deque.push_front({Head::is_head, Dir::right, (x / 2) - 2, (y / 2)});
        m_deque.push_front({Head::is_body, Dir::right, (x / 2) - 1, (y / 2)});
        m_deque.push_front({Head::is_body, Dir::right, (x / 2) + 0, (y / 2)});
        m_deque.push_front({Head::is_tail, Dir::right, (x / 2) + 1, (y / 2)});
    }

    const std::deque<BodyPart>& get_body_deque() const {
        return m_deque;
    }

    int color_head() {
        switch (head) {
            case Color::red:
                return 0;
            case Color::blue:
                return 1;
            case Color::green:
                return 2;
            case Color::orange:
                return 3;
        }
        return 0;
    }

    int color_body() {
        switch (body) {
            case Color::red:
                return 0;
            case Color::blue:
                return 1;
            case Color::green:
                return 2;
            case Color::orange:
                return 3;
        }
        return 1;
    }

    void next(Dir dir) {
        if (time_delete.getElapsedTime() > time) {
            tail = {m_deque.back().cordinates.x, m_deque.back().cordinates.y};
            time_delete.restart();
            m_deque.pop_back();
        }
        if (dir != Dir::without && m_deque[0].dir != reverse_dir(dir)) {
            change_dir(dir);
        } else
            not_change_dir();
    }

    void eat_apple(int x, int y) {
        m_deque.back().head = Head::is_body;
        m_deque.push_back({Head::is_tail, m_deque.back().dir, tail.x, tail.y});
    }

private:
    void change_dir(Dir dir) {
        tail = {m_deque.back().cordinates.x, m_deque.back().cordinates.y};
        m_deque.push_front({Head::is_head, dir, set_x(dir, m_deque[0].cordinates.x), set_y(dir, m_deque[0].cordinates.y)});
        m_deque[1].head = Head::is_body;
        m_deque.pop_back();
        m_deque.back().head = Head::is_tail;
    }

    void not_change_dir() {
        Dir dir = m_deque[0].dir;

        tail = {m_deque.back().cordinates.x, m_deque.back().cordinates.y};
        m_deque.push_front({Head::is_head, dir, set_x(dir, m_deque[0].cordinates.x), set_y(dir, m_deque[0].cordinates.y)});
        m_deque[1].head = Head::is_body;
        m_deque.pop_back();
        m_deque.back().head = Head::is_tail;
    }
};
