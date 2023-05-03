#pragma once
struct Quests {
    sf::Texture texture;
    sf::Sprite sprite;
    bool active = false;
    bool done = false;
};
void QuestsInit(Quests& obj, std::string fileName) {
    obj.texture.loadFromFile(fileName);
    obj.sprite.setTexture(obj.texture);
}

void Questsupdate(Quests& obj, sf::Vector2f pos) {
        obj.sprite.setPosition(pos);
}
void QuestsDraw(sf::RenderWindow& window, Quests& obj) {

    if (obj.active == true) {
        window.draw(obj.sprite);
    }
}

class QuestDialogue {

private:
    sf::Sprite sprite;
    sf::Texture texture;
    bool visible;
public:
    QuestDialogue() {
        texture.loadFromFile("sprites\\hud\\PlHp100.png");
        sprite.setTexture(texture);
        visible = true;
    }


    void update(sf::Vector2f pos, Player& pl) {
        sprite.setPosition(pos.x - 936.f, pos.y - 500.f);
        if (pl.health > 90) { texture.loadFromFile("sprites\\hud\\PlHp100.png"); }
        else   if (pl.health > 80) { texture.loadFromFile("sprites\\hud\\PlHp90.png"); }
        else   if (pl.health > 70) { texture.loadFromFile("sprites\\hud\\PlHp80.png"); }
        else   if (pl.health > 60) { texture.loadFromFile("sprites\\hud\\PlHp70.png"); }
        else   if (pl.health > 50) { texture.loadFromFile("sprites\\hud\\PlHp60.png"); }
        else   if (pl.health > 40) { texture.loadFromFile("sprites\\hud\\PlHp50.png"); }
        else   if (pl.health > 30) { texture.loadFromFile("sprites\\hud\\PlHp40.png"); }
        else   if (pl.health > 20) { texture.loadFromFile("sprites\\hud\\PlHp30.png"); }
        else   if (pl.health > 10) { texture.loadFromFile("sprites\\hud\\PlHp20.png"); }
        else   if (pl.health > 0) { texture.loadFromFile("sprites\\hud\\PlHp10.png"); }
    }

    void draw(sf::RenderWindow& window) {
        if (visible == true) {
            window.draw(sprite);
        }
    }
};