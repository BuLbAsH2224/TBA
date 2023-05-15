#pragma once
#include "settings.h"
#include "vragi.h"
struct Powers {
    sf::Texture texture;
    sf::Sprite sprite;
    bool visible = false;
};
class Laser {
private:
    sf::Sprite sprite;
    sf::Texture texture;
    int angle;
    float speedy, speedx, speed;
    bool left;
public:
    Laser(sf::Vector2f pos,Player& pl){
        texture.loadFromFile("sprites\\powers\\EmeraldHG.png");
        sprite.setTexture(texture);
        sf::FloatRect bounds = sprite.getLocalBounds();
        sprite.setOrigin(bounds.width / 2, bounds.height / 2);
        sprite.setPosition(pos);
        speed = rand() % 15 + 5.f;
        
        
        if (pl.left == true) {
            left = true;
            angle = rand() % 90 + 30;
            speedx = speed * sin(angle * 3.141592653589793f / 180.f);
            speedy = speed * cos(angle * 3.141592653589793f / 180.f);
        }
        if (pl.left == false) {
            left = false;
            angle = rand() % 90 + 30;
            speedx = speed * sin(angle * 3.141592653589793f / 180.f);
            speedy = -speed * cos(angle * 3.141592653589793f / 180.f);
        }
        sprite.setRotation(angle);
      
    }

        
    void update() {
        if (left == true) {
            sprite.move(-speedx, speedy);
        }
        if (left == false) {
            sprite.move(speedx, speedy);
        }

    }

    sf::Sprite& getSprite() { return sprite; }
    sf::FloatRect getHitBox() { return sprite.getGlobalBounds(); }
};

class Bubles {
private:
    sf::Sprite sprite;
    sf::Texture texture;
    int angle;
    float speedy, speedx;
    bool left;
public:
    Bubles(sf::Vector2f pos, Player& pl, float time) {
        texture.loadFromFile("sprites\\powers\\SAWBubles2.png");
        sprite.setTexture(texture);
        sf::FloatRect bounds = sprite.getLocalBounds();
        sprite.setOrigin(bounds.width / 2, bounds.height / 2);
        sprite.setPosition(pos);

        speedx = 1.f * time;
        speedy = 0;
        angle = rand() % 90 + 30;

        if (pl.left == true) {
            left = true;
        }
        if (pl.left == false) {
            left = false;
        }
        sprite.setRotation(angle);
    }

    void update() {
        if (left == true) {
            sprite.move(-speedx, speedy);
        }
        if (left == false) {
            sprite.move(speedx, speedy);
        }

    }
    sf::Sprite& getSprite() { return sprite; }
    sf::FloatRect getHitBox() { return sprite.getGlobalBounds(); }
};

class BarrageHands {
private:
    sf::Sprite sprite;
    sf::Texture texture;
    float speedy, speedx;
    float deletepos;
    bool left;
public:
    BarrageHands(sf::Vector2f pos, Player& pl) {
        if (pl.stand == 1) {
          
                texture.loadFromFile("sprites\\stands\\barrageHands\\TwHand.png");
        }
        if (pl.stand == 3) {

            texture.loadFromFile("sprites\\stands\\barrageHands\\WRHand.png");
        }
        if (pl.stand == 4) {

            texture.loadFromFile("sprites\\stands\\barrageHands\\HGHand.png");
        }
        if (pl.stand == 5) {

            texture.loadFromFile("sprites\\stands\\barrageHands\\SAWHand.png");
        }
        sprite.setTexture(texture);
        if (pl.left == true) {
            sprite.setPosition(pos.x , rand() % 50 + 30 + pos.y);
          
            deletepos = pos.x - 70;
        }
        if (pl.left == false) {
            sprite.setPosition(pos.x + 58, rand() % 50 + 30 + pos.y);
            deletepos = pos.x + 128.f;
            sprite.setRotation(180);
        }
        
        speedx = rand() % 15 + 5;
        speedy = 0;
        
   
        if (pl.left == true) {
            left = true;
        }
        if (pl.left == false) {
            left = false;
        }
       
    }
    float GetPos() { return sprite.getPosition().x; }
    float GetDeletePos() { return deletepos; }
    bool GetLeft() { return left; };
    
    void update() {
        if (left == true) {
            sprite.move(-speedx, speedy);
        }
        if (left == false) {
            sprite.move(speedx, speedy);
        }
     
    }
    sf::Sprite& getSprite() { return sprite; }
    sf::FloatRect getHitBox() { return sprite.getGlobalBounds(); }
};

    void PowrsObjectsINIT(Powers& obj, std::string fileName) {
        obj.texture.loadFromFile(fileName);
        obj.sprite.setTexture(obj.texture);


    }

    void Powersbjupdate(Powers& obj, sf::Vector2f pos, int a) {
        if (a == 1 && isTimeStopped == false) {
            obj.sprite.setPosition(pos);
        }
    }
    void PowersObjectsDraw(sf::RenderWindow& window, Powers& obj) {

        if (obj.visible == true) {
            window.draw(obj.sprite);
        }
    }


    void WrOxyDamagePl(Powers& obj, Player& pl, float time) {
        if (isWrOxy == true) {
            if (pl.sprite.getGlobalBounds().intersects(obj.sprite.getGlobalBounds())) {

              
               if (WROxy.getElapsedTime().asSeconds() > 1.f) {
                    pl.health -= 0.009f * time;
                }
            }
        }
    }

    void DeleteBarrageHands(BarrageHands& las, std::list<BarrageHands*>& lasers) {
        for (auto it = lasers.begin(); it != lasers.end(); /* без ++it здесь */) {
            if ((*it)->GetLeft() == false) {
                if ((*it)->GetPos() >= (*it)->GetDeletePos()) {
                    it = lasers.erase(it);
                }
                else {
                    ++it;
                }
            }
            else if ((*it)->GetLeft() == true) {
                if ((*it)->GetPos() <= (*it)->GetDeletePos()) {
                    it = lasers.erase(it);
                }
                else {
                    ++it;
                }
            }
        }
            
       
    }

    void LaserDamage(Laser& las, std::list<Laser*>& lasers, Vragi& vrag) {
        if (vrag.health > 0) {
            for (auto it = lasers.begin(); it != lasers.end(); /* без ++it здесь */) {
                if ((*it)->getHitBox().intersects(vrag.sprite.getGlobalBounds())) {
                    vrag.health -= 5.f;
                    it = lasers.erase(it);
                }
                else {
                    ++it;
                }
            }
        }
    }

   
    void BublesDamage(Bubles& las, std::list<Bubles*>& lasers, Vragi& vrag) {
        if (vrag.health > 0) {
            for (auto it = lasers.begin(); it != lasers.end(); /* без ++it здесь */) {
                if ((*it)->getHitBox().intersects(vrag.sprite.getGlobalBounds())) {
                    vrag.health -= 1.f;
                    it = lasers.erase(it);
                }
                else {
                    ++it;
                }
            }
        }
    }


    void WrOxyDamageVragov(Powers& obj, Vragi& pl, float time) {
        if (isWrOxy == true) {
            if (pl.sprite.getGlobalBounds().intersects(obj.sprite.getGlobalBounds())) {

             
               if (WROxy.getElapsedTime().asSeconds() > 1.f) {
                    pl.health -= 0.005f * time;
                }
            }
        }
    }


    class DimensionClones {
    private:
        sf::Sprite sprite;
        sf::Texture texture;
        Vragi* vragPtr;
        int color;
        sf::Clock die;
    public:
        DimensionClones(sf::Vector2f pos, Vragi& vrag) {
            texture = vrag.texture; // Создаем новый объект sf::Texture с помощью конструктора копирования
            sprite.setTexture(texture);
            sprite.setPosition(pos);
            vragPtr = &vrag;
            color = rand() % 5 + 1;
            if (color == 1) {
                sprite.setColor(Purple);
            }
            else if (color == 2) {
                sprite.setColor(sf::Color::Green);
            }
            else if (color == 3) {
                sprite.setColor(sf::Color::Yellow);
            }
            else if (color == 4) {
                sprite.setColor(sf::Color::Blue);
            }
            else if (color == 5) {
                sprite.setColor(sf::Color::Red);
            }
            auto rect = vrag.sprite.getTextureRect();
            rect.left += rect.width;
            rect.width = -rect.width;
            sprite.setTextureRect(rect);
        }
        bool getDeletes() {
            return sprite.getGlobalBounds().intersects(vragPtr->sprite.getGlobalBounds()) && vragPtr->health > 0;
        }
        bool getDeletesClock() {
            return die.getElapsedTime().asSeconds() >= 15.f;
        }
        auto getVrag() { return vragPtr; }
        sf::Sprite& getSprite() { return sprite; }
        sf::FloatRect getHitBox() { return sprite.getGlobalBounds(); }
    };

    void DimensionClonesDamage(DimensionClones& las, std::list<DimensionClones*>& lasers) {
        for (auto it = lasers.begin(); it != lasers.end(); /* без ++it здесь */) {
            if ((*it)->getDeletesClock() == true) {
            
                it = lasers.erase(it);
            }
            else {
                ++it;
            }
        }
        for (auto it = lasers.begin(); it != lasers.end(); /* без ++it здесь */) {
            if ((*it)->getDeletes() == true) {
                (*it)->getVrag()->health-= 10.f;
                it = lasers.erase(it);
            }
            else {
                ++it;
            }
        }

    }

   



    void BarrageDamage(Vragi& vrag, float time,Player& pl, Stand& st) {
        if (st.sprite.getGlobalBounds().intersects(vrag.sprite.getGlobalBounds()) && st.barrage == true) {
            if (pl.stand == 1) {
                vrag.health = vrag.health - 0.009f * time;
            }
            if (pl.stand == 3) {
                vrag.health = vrag.health - 0.01f * time;
            }
            if (pl.stand == 4) {
                vrag.health = vrag.health - 0.01f * time;
            }
            if (pl.stand == 5) {
                vrag.health = vrag.health - 0.02f * time;
            }
            if (pl.stand == 6) {
                vrag.health = vrag.health - 0.01f * time;
            }
        }
    }