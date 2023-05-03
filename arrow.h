/*#pragma once
#include "settings.h"
struct RandomObjects {
    sf::Texture texture;
    sf::Sprite sprite;
    bool visible; // флаг, указывающий, должен ли объект быть отображен
};
void RandomObjectsINIT(RandomObjects& obj, std::string fileName) {
    obj.texture.loadFromFile(fileName);
    obj.sprite.setTexture(obj.texture);
    obj.visible = false;
}
void randomizePosition(RandomObjects& obj) {
    int x = rand() % 1000;
    int y = rand() % 1000;
    obj.sprite.setPosition(x, y);
}
bool isOnScreen(int screenWidth, int screenHeight, RandomObjects& obj) {
    sf::FloatRect bounds = obj.sprite.getGlobalBounds();
    return (bounds.left >= 0 && bounds.left + bounds.width <= screenWidth
        && bounds.top >= 0 && bounds.top + bounds.height <= screenHeight);
}

// метод для обновления состояния объекта
void RandomObjupdate(int screenWidth, int screenHeight, RandomObjects& obj) {
    // с вероятностью 1/100 объект становится видимым и перемещается в случайную позицию
   
        if (rand() % 300 == 1) {
            obj.visible = true;
            randomizePosition(obj);
        }
 
    // если объект видим и находится за пределами экрана, то он становится невидимым
    if (obj.visible == true && !isOnScreen(screenWidth, screenHeight, obj)) {
        obj.visible = false;
    }
}
void RandomObjectsDraw(sf::RenderWindow& window, RandomObjects& obj) {
    if (obj.visible == true) {
        window.draw(obj.sprite);
    }
}*/