#include "field.h"

void test(int width, int height) {
    sf::RenderWindow window(sf::VideoMode(width * 256, height * 256), "Snake");
    window.setFramerateLimit(4);

    srand(time(0));
    Snakes s(width, height);
    Field field(width, height, window);
    Dir dir = Dir::right;
    field.Print_Field();
    field.create_apple();
    field.create_wall();
    while (window.isOpen()) {
        sf::Event e;

        while (window.pollEvent(e)) {
            if (e.type == sf::Event::EventType::Closed) {
                window.close();
            } else if (e.type == sf::Event::KeyPressed && e.key.code == sf::Keyboard::Left) {
                dir = Dir::left;
            } else if (e.type == sf::Event::KeyPressed && e.key.code == sf::Keyboard::Right) {
                ;
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
        s.next(dir);
        if (field.check_field(s) == false) {
            return;
        }
        field.Print_Field();
        field.free_field();
        window.display();
    }
}
