#pragma once
#include "settings.h"
#include "vragi.h"
#include "standIplayer.h"
class VragTheWorldKnive {
private:
    sf::Sprite sprite;
    sf::Texture texture;

    float speedy, speedx, speed;
    bool left;
    float damage;

public:
    VragTheWorldKnive(sf::Vector2f pos, Vragi& pl) {
        texture.loadFromFile("sprites\\powers\\TheWorldKnives.png");
        sprite.setTexture(texture);

        sf::FloatRect bounds = sprite.getLocalBounds();
        sprite.setOrigin(bounds.width / 2, bounds.height);
        sprite.setPosition(pos);
        speed = rand() % 2 + 1.f;
        damage = 3.f;

        if (pl.left == true) {
            left = true;
            sprite.setRotation(-180.f);
            speedx = 1.f;
            speedy = 0;
        }
        else {
            left = false;

            speedx = 1.f;
            speedy = 0;
        }


    }

    void update(float time, Powers& timestop) {
        if (sprite.getGlobalBounds().intersects(timestop.sprite.getGlobalBounds()) && timestop.visible == true) {
            // do nothing
        }
        else {
            if (left == true) {
                sprite.move(-speedx * time, speedy * time);
            }
            if (left == false) {
                sprite.move(speedx * time, speedy * time);
            }
        }
    }
    void draw(sf::RenderWindow& window) {
        window.draw(sprite);
    }
    float getDamage() { return damage; }
    sf::Sprite& getSprite() { return sprite; }
    sf::FloatRect getHitBox() { return sprite.getGlobalBounds(); }
};
void VragTheWorldKnivesDamage(VragTheWorldKnive& las, std::list<VragTheWorldKnive*>& lasers, Player& vrag) {
    if (vrag.health > 0) {
        for (auto it = lasers.begin(); it != lasers.end(); /* ��� ++it ����� */) {
            if ((*it)->getHitBox().intersects(vrag.sprite.getGlobalBounds())) {
                vrag.health -= (*it)->getDamage();
                it = lasers.erase(it);
            }
            else {
                ++it;
            }
        }
    }
}
