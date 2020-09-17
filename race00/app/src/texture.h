#pragma once
#include <SFML/Graphics.hpp>
#include <array>
#include <string>
#define SIZE_PICTURE 256

struct Textures {
    sf::Texture texture;
    sf::Sprite sprite;

    Textures(const std::string &file) {
        texture.loadFromFile(file);
        sprite.setTexture(texture);
    }
};

class Structure {
    std::array<Textures, 8> m_texture_sprite {
        Textures("res/red.jpg"), //0
        Textures("res/blue.jpg"), //1
        Textures("res/green.jpg"), //2
        Textures("res/orange.jpg"), //3
        Textures("res/field.jpg"),//4
        Textures("res/stop.png"), //5
        Textures("res/game_over.png"),//6
        Textures("res/apple.png"),//7
    };

public:
    Structure() {}

    sf::Sprite &GetSprite(int num) {
        return m_texture_sprite[num].sprite;
    }
};


class Menu {
    std::array<Textures, 4> m_texture_sprite {
        Textures("res/game.png"), //0
        Textures("res/game1.png"), //1
        Textures("res/leaderboard.png"), //2
        Textures("res/leaderboard-1.png"), //3
    };

public:
    Menu() {}

    sf::Sprite &GetMenu(int num) {
        return m_texture_sprite[num].sprite;
    }
};
