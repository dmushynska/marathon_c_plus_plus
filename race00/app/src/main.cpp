#include "field.h"

void key_press(sf::RenderWindow &window, Dir &dir, const sf::Event &e) {
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

void test(int width, int height) {
    sf::RenderWindow window(sf::VideoMode(width * SIZE_PICTURE, height * SIZE_PICTURE), "Snake");
    window.setFramerateLimit(4);

    srand(time(0));
    Snakes s(width, height);
    Field field(width, height, window);
    Dir dir_1 = Dir::right;
    field.Print_Field();
    field.check_field(s);
    field.create_apple();
    field.create_wall();
    while (window.isOpen()) {
        sf::Event e;

        field.free_field_snake(s);
        while (window.pollEvent(e)) {
            key_press(window, dir_1, e);
        }
        s.next(dir_1);
        if (field.check_field(s) == false) {
            return;
        }
        while (field.count_apples() != 1) {
            field.create_apple();
        }
        field.Print_Field();
        window.display();
    }
}
