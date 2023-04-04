#pragma once
#include "settings.h"
struct Vragi {
    bool left = false;
    sf::Texture texture;
    sf::Sprite sprite;
    int stand = 0;
    float health;
    bool statics;
};

void VragiInit(Vragi& obj, std::string fileName, int stand, float health, sf::Vector2f pos, bool tupoi) {
    obj.texture.loadFromFile(fileName);
    obj.sprite.setTexture(obj.texture);
    obj.stand = stand;
    obj.health = health;
    obj.sprite.setPosition(pos);
    obj.statics = tupoi;
}

void VragiUpdate(Vragi& obj) {
    if (obj.health > 0) {
        if (obj.statics == true) {

        }
    }
}

void VragiDraw(sf::RenderWindow& window, Vragi& obj) {
    if (obj.health > 0) {
        window.draw(obj.sprite);
    }
}


