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

class snow {
private:
    float speedx,speedy, wx;
    sf::Sprite sprite;
    sf::Texture texture;
    sf::View* view;
    sf::RenderWindow* window;
public:
    snow(sf::View vw,sf::RenderWindow& ww) {
        window = &ww;
        view = &vw;
        texture.loadFromFile("sprites\\map\\snow.png");
        sprite.setTexture(texture);
        wx = rand() % int((view->getCenter().x - view->getSize().x / 2.0)  + window->getSize().x);
        sprite.setPosition({ wx,view->getCenter().y - view->getSize().y / 2.0f });
        
      
        speedx = rand() % 2 + 0.5f;
        speedy = rand() % 2 + 0.5f;
      
    }
    void update(float time) {
        
        sprite.move(speedx * time, speedy * time);
      
    }
    void draw() {
        window->draw(sprite);
    }
    bool getDelete() { return sprite.getPosition().y > view->getCenter().y + view->getSize().y / 2.0f; };
};

void SnowDelete(snow& las, std::list<snow*>& lasers) {
    
        for (auto it = lasers.begin(); it != lasers.end(); /* без ++it здесь */) {
            if ((*it)->getDelete() == true) {
                it = lasers.erase(it);
            }
            else {
                ++it;
            }
        }
    
}