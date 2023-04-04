#pragma once
#include "settings.h"
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
    
}
void MapObjectsDraw(sf::RenderWindow& window, Map& obj) {
     window.draw(obj.sprite);  
}