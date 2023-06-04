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
    float angle;
    float speedy, speedx, speed;
    bool left;
public:
    Laser(sf::Vector2f pos, Player& pl, float time) {
        texture.loadFromFile("sprites\\powers\\EmeraldHG.png");
        sprite.setTexture(texture);

        sf::FloatRect bounds = sprite.getLocalBounds();
        sprite.setOrigin(bounds.width / 2, bounds.height);
        sprite.setPosition(pos);
        speed = rand() % 2 + 1.f;


        if (pl.left == true) {
            left = true;
            angle = rand() % 70 + 60;
            speedx = (speed * sin(angle * 3.141592653589793f / 180.f)) * time;
            speedy = (-speed * cos(angle * 3.141592653589793f / 180.f)) * time;
        }
        if (pl.left == false) {
            left = false;
            angle = rand() % 70 + 60;
            speedx = (speed * sin(angle * 3.141592653589793f / 180.f)) * time;
            speedy = (-speed * cos(angle * 3.141592653589793f / 180.f)) * time;
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
class TheWorldKnive {
private:
    sf::Sprite sprite;
    sf::Texture texture;
   
    float speedy, speedx, speed;
    bool left;
    float damage;

public:
    TheWorldKnive(sf::Vector2f pos, Player& pl) {
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
void TheWorldKnivesDamage(TheWorldKnive& las, std::list<TheWorldKnive*>& lasers, Vragi& vrag) {
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
class AerosmithBullet {
private:
    sf::Sprite sprite;
    sf::Texture texture;
    float angle;
    float speedy, speedx, speed;
    bool left;
    float damage;
 
public:
    AerosmithBullet(sf::Vector2f pos, Player& pl) {
        texture.loadFromFile("sprites\\powers\\AerosmithBullet.png");
        sprite.setTexture(texture);

        sf::FloatRect bounds = sprite.getLocalBounds();
        sprite.setOrigin(bounds.width / 2, bounds.height);
        sprite.setPosition(pos);
        speed = rand() % 2 + 1.f;
        damage = 0.3f;

        if (pl.left == true) {
            left = true;
            angle = rand() % 70 + 60;
            speedx = (speed * sin(angle * 3.141592653589793f / 180.f));
            speedy = (-speed * cos(angle * 3.141592653589793f / 180.f));
        }
        else if (pl.left == false) {
            left = false;
            angle = rand() % 70 + 60;
            speedx = (speed * sin(angle * 3.141592653589793f / 180.f));
            speedy = (-speed * cos(angle * 3.141592653589793f / 180.f));
        }
        if (pl.left == true) {
            angle = -angle;
        }
        sprite.setRotation(angle);

    }
    
    void update(float time) {
        if (left == true) {
            sprite.move(-speedx * time, speedy * time);
        }
        if (left == false) {
            sprite.move(speedx * time, speedy * time);
        }

    }
    void draw(sf::RenderWindow& window) {
        window.draw(sprite);
    }
    float getDamage() { return damage; }
    sf::Sprite& getSprite() { return sprite; }
    sf::FloatRect getHitBox() { return sprite.getGlobalBounds(); }
};
void AerosmithBulletsDamage(AerosmithBullet& las, std::list<AerosmithBullet*>& lasers, Vragi& vrag) {
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

        speedx = 0.5f * time;
        speedy = 0;
        angle = rand() % 360;

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
            angle = angle - 2.f;
        }
        if (left == false) {
            sprite.move(speedx, speedy);
            angle = angle + 2.f;
        }
        
        sprite.setRotation(angle);
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
        if (pl.stand == 6) {

            texture.loadFromFile("sprites\\stands\\barrageHands\\D4CHand.png");
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
                    vrag.health -= 2.f;
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
    
    class SteelBall {
    private:
        sf::Sprite sprite;
        sf::Texture texture;
        int angle;
        float speedy, speedx;
        bool left;
        float damage;
    public:
        SteelBall(sf::Vector2f pos, Player& pl, bool charge) {
            texture.loadFromFile("sprites\\powers\\SteelBall.png");
            sprite.setTexture(texture);
            sf::FloatRect bounds = sprite.getLocalBounds();
            sprite.setOrigin(bounds.width / 2, bounds.height / 2);
            sprite.setPosition(pos);

            speedx = 0.5f ;
            speedy = 0;
            angle = rand() % 360;

            if (pl.left == true) {
                left = true;
            }
            if (pl.left == false) {
                left = false;
            }
            sprite.setRotation(angle);
            if (charge == false) {
                damage = 4.f;
            }
            else if (charge == true) {
                damage = 8.f;
            }
        }


        void update(float time) {
            if (left == true) {
                sprite.move(-speedx * time, speedy);
                angle = angle - 2.f * time;
            }
            if (left == false) {
                sprite.move(speedx * time, speedy);
                angle = angle + 2.f* time;
            }

            sprite.setRotation(angle);
        }
        void draw(sf::RenderWindow& window) {
            window.draw(sprite);
        }
        float getDamage() { return damage; }
        sf::Sprite& getSprite() { return sprite; }
        sf::FloatRect getHitBox() { return sprite.getGlobalBounds(); }
    };

    void SteelBallsDamage(SteelBall& las, std::list<SteelBall*>& lasers, Vragi& vrag) {
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

    class MandomBullet {
    private:
        sf::Sprite sprite;
        sf::Texture texture;
        int angle;
        float speedy, speedx;
        bool left;
        float damage;
    public:
        MandomBullet(sf::Vector2f pos, Player& pl, float time, bool charge) {
            texture.loadFromFile("sprites\\powers\\SAWBubles2.png");
            sprite.setTexture(texture);
            sf::FloatRect bounds = sprite.getLocalBounds();
            sprite.setOrigin(bounds.width / 2, bounds.height / 2);
            sprite.setPosition(pos);

            speedx = 0.5f * time;
            speedy = 0;


            if (pl.left == true) {
                left = true;

            }
            if (pl.left == false) {
                left = false;
                sprite.setRotation(180.f);
            }

            damage = 0.5f * time;
        }


        void update() {
            if (left == true) {
                sprite.move(-speedx, speedy);

            }
            if (left == false) {
                sprite.move(speedx, speedy);

            }

            sprite.setRotation(angle);
        }
        float getDamage() { return damage; }
        sf::Sprite& getSprite() { return sprite; }
        sf::FloatRect getHitBox() { return sprite.getGlobalBounds(); }
    };

    void MandomBulletDamage(MandomBullet& las, std::list<MandomBullet*>& lasers, Vragi& vrag) {
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

    class DimensionClones {
    private:
        sf::Sprite sprite;
        sf::Texture texture;
        Vragi* vragPtr;
        int color;
        sf::Clock die;
    public:
        DimensionClones(sf::Vector2f pos, Vragi& vrag) {
            texture = vrag.texture; 
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
                (*it)->getVrag()->health-= 20.f;
                it = lasers.erase(it);
            }
            else {
                ++it;
            }
        }

    }

    class SheerHeartAttack {
    private:
        sf::Sprite sprite;
        sf::Texture texture;
        Vragi* vragPtr;
        float damage;
        sf::Clock die;
        bool left;
        float speed;
    public:
        SheerHeartAttack(sf::Vector2f pos, Vragi& vrag) {
            texture.loadFromFile("sprites\\powers\\SAWBubles2.png");
            sprite.setTexture(texture);
            sprite.setPosition(pos);
            vragPtr = &vrag;
            damage = 20.f;
            left = false;
            speed = 0.09;

        }
        void update(float time) {
            if (sprite.getPosition().x < vragPtr->sprite.getPosition().x ) {
                sprite.move(0.1f * time, 0); // Враг движется вправо
                left = false;
            }
            else  {
                sprite.move(-0.1f * time, 0); // Враг движется влево
                left = true;
            }
            if (left == true) {
                texture.loadFromFile("sprites\\npc\\PlohoiParenLeft.png");
            }
            else if (left == false) {
                texture.loadFromFile("sprites\\npc\\PlohoiParenRight.png");
            }
        }
        bool getDeletes() {
            return sprite.getGlobalBounds().intersects(vragPtr->sprite.getGlobalBounds()) && vragPtr->health > 0;
        }
        bool getDeletesClock() {
            return die.getElapsedTime().asSeconds() >= 15.f;
        }
        float getDamage() { return damage; }
        auto getVrag() { return vragPtr; }
        sf::Sprite& getSprite() { return sprite; }
        sf::FloatRect getHitBox() { return sprite.getGlobalBounds(); }
    };

    void SheerHeartAttackDamage(SheerHeartAttack& las, std::list<SheerHeartAttack*>& lasers) {
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
                (*it)->getVrag()->health -= (*it)->getDamage();
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
                vrag.health = vrag.health - 0.005f * time;
            }
            else if (pl.stand == 3) {
                vrag.health = vrag.health - 0.005f * time;
            }
            else if (pl.stand == 4) {
                vrag.health = vrag.health - 0.005f * time;
            }
            else if (pl.stand == 5) {
                vrag.health = vrag.health - 0.012f * time;
            }
            else if (pl.stand == 6) {
                vrag.health = vrag.health - 0.005f * time;
            }
            else  if (pl.stand == 7) {
                vrag.health = vrag.health - 0.006f * time;
            }
        }
    }