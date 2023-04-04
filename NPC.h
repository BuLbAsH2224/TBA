#pragma once
#include "settings.h"
struct NPC {
    sf::Texture texture;
    sf::Sprite sprite;
    bool statics;
};

void NPCInit(NPC& obj, std::string fileName, sf::Vector2f pos) {
    obj.texture.loadFromFile(fileName);
    obj.sprite.setTexture(obj.texture);
    obj.sprite.setPosition(pos);

}

void NPCUpdate(NPC& obj) {

}

void NPCDraw(sf::RenderWindow& window, NPC& obj) {

    window.draw(obj.sprite);

}
