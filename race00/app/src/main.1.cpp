#include "field.h"

void key_press_1(sf::RenderWindow &window, Dir &dir, const sf::Event &e) {
    if (e.type == sf::Event::EventType::Closed) {
        window.close();
    } else if (e.type == sf::Event::KeyPressed && e.key.code == sf::Keyboard::Left) {
        dir = Dir::left;
    } else if (e.type == sf::Event::KeyPressed && e.key.code == sf::Keyboard::Right) {
        dir = Dir::right;
    } else if (e.type == sf::Event::KeyPressed && e.key.code == sf::Keyboard::Up) {
        dir = Dir::up;
    } else if (e.type == sf::Event::KeyPressed && e.key.code == sf::Keyboard::Down) {
        dir = Dir::down;
    } else if (e.type == sf::Event::KeyPressed && e.key.code == sf::Keyboard::Escape) {
        window.close();
        return;
    }
}

void key_press_2(sf::RenderWindow &window, Dir &dir, const sf::Event &e) {
    if (e.type == sf::Event::EventType::Closed) {
        window.close();
    } else if (e.type == sf::Event::KeyPressed && e.key.code == sf::Keyboard::D) {
        dir = Dir::right;
    } else if (e.type == sf::Event::KeyPressed && e.key.code == sf::Keyboard::A) {
        dir = Dir::left;
    } else if (e.type == sf::Event::KeyPressed && e.key.code == sf::Keyboard::W) {
        dir = Dir::up;
    } else if (e.type == sf::Event::KeyPressed && e.key.code == sf::Keyboard::S) {
        dir = Dir::down;
    } else if (e.type == sf::Event::KeyPressed && e.key.code == sf::Keyboard::Escape) {
        window.close();
        return;
    }
}

void test_1(int width, int height) {
    sf::RenderWindow window(sf::VideoMode(width * SIZE_PICTURE, height * SIZE_PICTURE), "Snake");
    window.setFramerateLimit(4);

    srand(time(0));
    Snakes s(width, height);
    Snakes snake(width - 2, height - 2);
    Field field(width, height, window);
    Dir dir_1 = Dir::right;
    Dir dir_2 = Dir::right;
    field.Print_Field();
    field.check_field(s);
    field.check_field(snake);
    field.create_apple();
    field.create_apple();
    field.create_wall();
    while (window.isOpen()) {
        sf::Event e;

        field.free_field_snake(s);
        field.free_field_snake(snake);
        while (window.pollEvent(e)) {
            key_press_1(window, dir_1, e);
            key_press_2(window, dir_2, e);
        }
        s.next(dir_1);
        snake.next(dir_2);
        if (field.check_field(s) == false) {
            return;
        }
        if (field.check_field(snake) == false) {
            return;
        }
        while (field.count_apples() != 2) {
            field.create_apple();
        }
        field.Print_Field();
        window.display();
    }
}
