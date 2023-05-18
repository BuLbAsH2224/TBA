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

class ItemsForShop {
private:
    sf::Sprite sprite;
    sf::Texture texture;
    int ID;
public:
    ItemsForShop() {
        texture.loadFromFile("sprites\\hud\\inventory\\testitem.png");
        sprite.setTexture(texture);
    }
    void setID(int id) { ID = id; }
};

class Shop {
private:
    sf::Sprite backgroundsprite;
    sf::Texture backgroundtexture;
    ItemsForShop item[3];
public:
    Shop() {
        backgroundtexture.loadFromFile("sprites\\hud\\inventory\\testitem.png");
        backgroundsprite.setTexture(backgroundtexture);
    }
    void SetShopItems(int id1, int id2, int id3) {
        item[1].setID(id1);
        item[2].setID(id2);
        item[3].setID(id3);
    }
};