#pragma once
#include "settings.h"
sf::Color Purple(125, 34, 216);
sf::Color Goluboi(46, 215, 228);

struct Map {
    sf::Texture texture;
    sf::Sprite sprite;
    bool used;
    int type = 1;
};
void MapObjectsINIT(Map& obj, std::string fileName, sf::Vector2f pos) {
    obj.texture.loadFromFile(fileName);
    obj.sprite.setTexture(obj.texture);
    obj.used = false;
    obj.sprite.setPosition(pos);
 
}


void Mapbjupdate(Map& obj) {
    if (D4CDimension == true) {
        obj.sprite.setColor(Purple);
    }
    else {
        obj.sprite.setColor(sf::Color::White);
    }
}



void MapObjectsDraw(sf::RenderWindow& window, Map& obj) {
     window.draw(obj.sprite);  
}