#include <set>

#include "field.h"

void Showwindow(sf::RenderWindow &window, int i, int x) {
    static Menu structure;

    if (i == 0) {
        auto &sp1 = structure.GetMenu(0);
        sp1.setPosition(150, 150);
        window.draw(sp1);
    } else {
        auto &sp2 = structure.GetMenu(1);
        sp2.setPosition(230, 150);
        window.draw(sp2);
    }
    if (x == 2) {
        auto &sp3 = structure.GetMenu(2);
        sp3.setPosition(280, 400);
        window.draw(sp3);
    } else {
        auto &sp4 = structure.GetMenu(3);
        sp4.setPosition(280, 400);
        window.draw(sp4);
    }

    sf::Font font;
    sf::Text text;
    if (font.loadFromFile("res/ArialRegular.ttf")) {
        text.setFont(font);
        text.setString("Press esc to exit");
        text.setCharacterSize(50);
        text.setFillColor(sf::Color::Black);
        text.setStyle(sf::Text::Bold);
        text.setPosition(180, 700);
        window.draw(text);
    }
}

void Print_score(sf::RenderWindow &window) {
    sf::Font font;
    sf::Text text;
    std::string str;
    std::set<std::string> set;
    std::ifstream s(".test");
    for (int i = 0; std::getline(s, str); i++) {
        set.insert(str);
    }
    int i = 0;
    for (auto &it : set) {
        text.setString(it + "\n");
        if (font.loadFromFile("res/ArialRegular.ttf")) {
            text.setFont(font);
            text.setCharacterSize(50);
            text.setFillColor(sf::Color::Black);
            text.setStyle(sf::Text::Bold);
            text.setPosition(0, i *50);
            i++;
            window.draw(text);
            if (i == 10)
                break;
        }
    }
}

void menu(int width, int height) {
    sf::RenderWindow window(sf::VideoMode(800, 800), "Menu");
    int x = 2, i = 0;
    while (window.isOpen()) {
        sf::Event e;

        while (window.pollEvent(e)) {
            if (e.type == sf::Event::EventType::Closed) {
                window.close();
            } else if (e.type == sf::Event::KeyPressed && e.key.code == sf::Keyboard::Up) {
                i = 1;
                x = 2;
            } else if (e.type == sf::Event::KeyPressed && e.key.code == sf::Keyboard::Down) {
                x = 3;
                i = 0;
            } else if (e.type == sf::Event::KeyPressed && e.key.code == sf::Keyboard::Escape) {
                window.close();
                return;
            }
            if (e.type == sf::Event::KeyPressed && e.key.code == sf::Keyboard::Enter) {
                if (i == 1) {
                    test_1(width, height);
                    // test(width, height);
                }
                if (x == 3) {
                    window.clear(sf::Color(255, 255, 255, 255));
                    Print_score(window);
                    window.setFramerateLimit(1);
                    window.display();
                }
            }
        }
        window.setFramerateLimit(4);
        window.clear(sf::Color(255, 255, 255, 255));
        Showwindow(window, i, x);
        window.display();
    }
}

int main(int argc, char *argv[]) {
    int width, height;

    if (argc != 3) {
        std::cerr << "usage: ./race00 [width] [height]\n";
        return 1;
    }
    try {
        width = std::stoi(argv[1]);
        height = std::stoi(argv[2]);
    } catch (...) {
        std::cerr << "usage: ./race00 [width] [height]\n";
        return 1;
    }
    menu(width, height);
}
