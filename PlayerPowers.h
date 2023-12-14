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
        else if (pl.stand == 3) {

            texture.loadFromFile("sprites\\stands\\barrageHands\\WRHand.png");
        }
        else  if (pl.stand == 4) {

            texture.loadFromFile("sprites\\stands\\barrageHands\\HGHand.png");
        }
        else if (pl.stand == 5) {

            texture.loadFromFile("sprites\\stands\\barrageHands\\SAWHand.png");
        }
        else if (pl.stand == 6) {

            texture.loadFromFile("sprites\\stands\\barrageHands\\D4CHand.png");
        }
        else if (pl.stand == 8) {

            texture.loadFromFile("sprites\\stands\\barrageHands\\KQHand.png");
        }
        else if (pl.stand == 9) {

            texture.loadFromFile("sprites\\stands\\barrageHands\\GeHand.png");
        }
        else if (pl.stand == 10) {

            texture.loadFromFile("sprites\\stands\\barrageHands\\WsHand.png");
        }
        else if (pl.stand == 11) {

            texture.loadFromFile("sprites\\stands\\barrageHands\\GeHand.png");
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
    class KqCoins {
    private:
        sf::Sprite sprite;
        sf::Texture texture;
        sf::Sprite BOOMsprite;
        sf::Texture BOOMtexture;
        sf::Clock die;
        sf::Clock BOOMtm;
        bool BOOM;
        float damage;
        sf::SoundBuffer BOOMBuffer;
        sf::Sound BOOMsound;
        
    public:
        KqCoins(sf::Vector2f pos, Player& pl, float time) {
            BOOM = false;
            BOOMtexture.loadFromFile("sprites\\powers\\BOOM.png");
            BOOMsprite.setTexture(BOOMtexture);
            texture.loadFromFile("sprites\\powers\\coin.png");
            sprite.setTexture(texture);
            BOOMBuffer.loadFromFile("sounds\\stands\\CoinBoom.ogg");
            BOOMsound.setBuffer(BOOMBuffer);
       
            sprite.setPosition({ pos.x,pos.y - sprite.getGlobalBounds().height });

            BOOMsprite.setPosition({ pos.x - (BOOMsprite.getGlobalBounds().width / 2.f),pos.y - BOOMsprite.getGlobalBounds().height });
          
            damage = 8.f;

        }

        void update() {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::J) && BOOM == false) {
                BOOM = true;
                BOOMsound.play();
                BOOMtm.restart();
            }


        }
        void draw(sf::RenderWindow& window) {
            if (BOOM == false) {
                window.draw(sprite);
            }
            else { window.draw(BOOMsprite); }
        }
        bool getDie() { return BOOM == false && die.getElapsedTime().asSeconds() >= 10.f; }
        bool getDieBoom() { return  BOOM == true && BOOMtm.getElapsedTime().asSeconds() >= 1.f; }
        float getDamage() { return damage; }
        bool getBoom() { return BOOM; }
        sf::Sprite& getSpriteBoom() { return BOOMsprite; }
        sf::Sprite& getSprite() { return sprite; }
        sf::FloatRect getHitBox() { return BOOMsprite.getGlobalBounds(); }
    };

    void KqCoinsDamage(KqCoins& las, std::list<KqCoins*>& lasers, Vragi& vrag) {
        for (auto it = lasers.begin(); it != lasers.end(); /* без ++it здесь */) {
            if ((*it)->getDie() == true) {

                it = lasers.erase(it);
            }
            else {
                ++it;
            }
        }
        for (auto it = lasers.begin(); it != lasers.end(); /* без ++it здесь */) {
            if ((*it)->getDieBoom() == true) {

                it = lasers.erase(it);
            }
            else {
                ++it;
            }
        }
        for (auto it = lasers.begin(); it != lasers.end(); /* без ++it здесь */) {
            if ((*it)->getHitBox().intersects(vrag.sprite.getGlobalBounds()) && vrag.health > 0 && (*it)->getBoom() == true) {
                vrag.health -= (*it)->getDamage();
                it = lasers.erase(it);
            }
            else {
                ++it;
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
            texture.loadFromFile("sprites\\powers\\SheertHeartAttackLeft.png");
            sprite.setTexture(texture);
            pos.y -= sprite.getGlobalBounds().height;
            sprite.setPosition(pos);
            vragPtr = &vrag;
            damage = 20.f;
            left = false;
            speed = 0.05;

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
                texture.loadFromFile("sprites\\powers\\SheertHeartAttackLeft.png");
            }
            else if (left == false) {
                texture.loadFromFile("sprites\\powers\\SheertHeartAttackRight.png");
            }
        }
        bool getDeletes() {
            return sprite.getGlobalBounds().intersects(vragPtr->sprite.getGlobalBounds()) && vragPtr->health > 0;
        }
        bool getDeletesClock() {
            return die.getElapsedTime().asSeconds() >= 15.f;
        }
        void draw(sf::RenderWindow& window) {
            window.draw(sprite);
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
            else  if (pl.stand == 8) {
                vrag.health = vrag.health - 0.006f * time;
            }
            else  if (pl.stand == 9) {
                vrag.health = vrag.health - 0.006f * time;
            }
            else  if (pl.stand == 10) {
                vrag.health = vrag.health - 0.006f * time;
            }
        }
    }

    class GeTree {
    private:
        sf::Sprite sprite;
        sf::Texture texture;
        sf::Clock die;
        sf::Clock animation;
        sf::Vector2f position;
        int cadr;
        bool animationOn;
       
        float times;
    public:
        GeTree(sf::Vector2f pos, bool left) {
            texture.loadFromFile("sprites\\powers\\GeTree1.png");
            sprite.setTexture(texture);
          
            if (left == true) {
                position = { pos.x - sprite.getLocalBounds().width ,pos.y  };
                sprite.setPosition(pos.x - 5.f - sprite.getLocalBounds().width, pos.y + sprite.getLocalBounds().height);
            }
            else {
                position = { pos.x,pos.y  };
                sprite.setPosition(pos.x + 5.f, pos.y + sprite.getLocalBounds().height);
            }
            
          
            cadr = 1;
            animationOn = true;
            
            times = 200;
        }
        void TreemoveTo(GeTree & obj, sf::Vector2f to, float dt, float speed)
        {

            if (obj.sprite.getPosition() != to)
            {
                sf::Vector2f const delta = to - obj.sprite.getPosition();
                float const ds = speed * dt;
                float const off = ds / std::sqrt(delta.x * delta.x + delta.y * delta.y);
                sf::Vector2f const pos = off < 1 ? obj.sprite.getPosition() + delta * off : to;
                obj.sprite.setPosition(pos);
            }
        }
        void update(GeTree& obj, float time,Vragi& vrag) {
            if (animationOn == true) {
                animation.restart();
                animationOn = false;
            }
            if (vrag.sprite.getGlobalBounds().intersects(obj.sprite.getGlobalBounds())) {
                sf::FloatRect playerBounds = vrag.sprite.getGlobalBounds();
                playerBounds.left += 5.f;
                playerBounds.width -= 10.f;
                playerBounds.top += 50.f;
                playerBounds.height -= 50.f;

                if (playerBounds.intersects(obj.sprite.getGlobalBounds())) {
                    sf::FloatRect enemyBounds = obj.sprite.getGlobalBounds();

                    // Определяем пересечение объектов по осям X и Y
                    float intersectX = std::max(0.f, std::min(playerBounds.left + playerBounds.width, enemyBounds.left + enemyBounds.width) - std::max(playerBounds.left, enemyBounds.left));
                    float intersectY = std::max(0.f, std::min(playerBounds.top + playerBounds.height, enemyBounds.top + enemyBounds.height) - std::max(playerBounds.top, enemyBounds.top));

                    // Определяем, по какой оси объекты пересекаются больше
                    if (intersectX > intersectY) {
                        if (playerBounds.top < enemyBounds.top) {
                            // Игрок находится сверху от врага, перемещаем игрока вверх, а врага вниз
                            vrag.sprite.move(0.f, -intersectY);

                        }
                        else {
                            // Игрок находится снизу от врага, перемещаем игрока вниз, а врага вверх
                            vrag.sprite.move(0.f, intersectY);

                        }
                    }
                    else {
                        if (playerBounds.left < enemyBounds.left) {
                            // Игрок находится слева от врага, перемещаем игрока влево, а врага вправо
                            vrag.sprite.move(-intersectX, 0.f);

                        }
                        else {
                            // Игрок находится справа от врага, перемещаем игрока вправо, а врага влево
                            vrag.sprite.move(intersectX, 0.f);

                        }
                    }
                }
            }
        
            if (cadr != 18) {
                if (animation.getElapsedTime().asMilliseconds() >= times) {
                    times = times + 200;
                    cadr++;
                }
                
                TreemoveTo(obj, position, 5.f, 0.01f * time);
               
                    if (rand() % 50 + 1 < 50) {
                        obj.getSprite().setPosition(obj.getSprite().getPosition().x - 0.01f, obj.getSprite().getPosition().y);
                 }
                    else {
                        obj.getSprite().setPosition(obj.getSprite().getPosition().x + 0.01f, obj.getSprite().getPosition().y);
                    }
                
                if (cadr == 2) {
                    texture.loadFromFile("sprites\\powers\\GeTree2.png");
                    sprite.setTexture(texture);
                }
                else if (cadr == 3) {
                    texture.loadFromFile("sprites\\powers\\GeTree3.png");
                    sprite.setTexture(texture);
                }
                else if (cadr == 4) {
                    texture.loadFromFile("sprites\\powers\\GeTree4.png");
                    sprite.setTexture(texture);
                }
                else if (cadr == 5) {
                    texture.loadFromFile("sprites\\powers\\GeTree" + std::to_string(cadr) + ".png");
                    sprite.setTexture(texture);
                }
                else if (cadr == 6) {
                    texture.loadFromFile("sprites\\powers\\GeTree" + std::to_string(cadr) + ".png");
                    sprite.setTexture(texture);
                }
                else if (cadr == 7) {
                    texture.loadFromFile("sprites\\powers\\GeTree" + std::to_string(cadr) + ".png");
                    sprite.setTexture(texture);
                }
                else if (cadr == 8) {
                    texture.loadFromFile("sprites\\powers\\GeTree" + std::to_string(cadr) + ".png");
                    sprite.setTexture(texture);
                }
                else if (cadr == 9) {
                    texture.loadFromFile("sprites\\powers\\GeTree" + std::to_string(cadr) + ".png");
                    sprite.setTexture(texture);
                }
                else if (cadr == 10) {
                    texture.loadFromFile("sprites\\powers\\GeTree" + std::to_string(cadr) + ".png");
                    sprite.setTexture(texture);
                }
                else if (cadr == 11) {
                    texture.loadFromFile("sprites\\powers\\GeTree" + std::to_string(cadr) + ".png");
                    sprite.setTexture(texture);
                }
                else if (cadr == 12) {
                    texture.loadFromFile("sprites\\powers\\GeTree" + std::to_string(cadr) + ".png");
                    sprite.setTexture(texture);
                }
                else if (cadr == 13) {
                    texture.loadFromFile("sprites\\powers\\GeTree" + std::to_string(cadr) + ".png");
                    sprite.setTexture(texture);
                }
                else if (cadr == 14) {
                    texture.loadFromFile("sprites\\powers\\GeTree" + std::to_string(cadr) + ".png");
                    sprite.setTexture(texture);
                }
                else if (cadr == 15) {
                    texture.loadFromFile("sprites\\powers\\GeTree" + std::to_string(cadr) + ".png");
                    sprite.setTexture(texture);
                }
                else if (cadr == 16) {
                    texture.loadFromFile("sprites\\powers\\GeTree" + std::to_string(cadr) + ".png");
                    sprite.setTexture(texture);
                }
                else if (cadr == 17) {
                    texture.loadFromFile("sprites\\powers\\GeTree" + std::to_string(cadr) + ".png");
                    sprite.setTexture(texture);
                }
                else if (cadr == 18) {
                    texture.loadFromFile("sprites\\powers\\GeTree.png");
                    sprite.setTexture(texture);
                }
            }
            
        }
        void draw(sf::RenderWindow& window) {
            window.draw(sprite);
        }
        bool getDeletesClock() {
            return die.getElapsedTime().asSeconds() >= 12.f;
        }
        sf::Sprite& getSprite() { return sprite; }
        sf::FloatRect getHitBox() { return sprite.getGlobalBounds(); }
    };
    
    void GeTreesDamage(GeTree& las, std::list<GeTree*>& lasers) {
        for (auto it = lasers.begin(); it != lasers.end(); /* без ++it здесь */) {
            if ((*it)->getDeletesClock() == true) {

                it = lasers.erase(it);
            }
            else {
                ++it;
            }
        }

    }

    class GeSoul {
    private:
        sf::Sprite sprite;
        sf::Texture texture;
        Vragi* vragPtr;
        sf::Clock TimeAction;
        sf::Vector2f position;
    public:
        GeSoul(sf::Vector2f pos, Vragi& vrag) {
            texture = vrag.texture;
            sprite.setTexture(texture);
            sprite.setPosition(pos);
            vragPtr = &vrag;
            position = pos;
            sprite.setColor(sf::Color::Blue);   
            auto rect = vrag.sprite.getTextureRect();
            rect.left += rect.width;
            rect.width = -rect.width;
            sprite.setTextureRect(rect);
        }
        void SoulmoveTo(GeSoul& obj, sf::Vector2f to, float dt, float speed)
        {

            if (obj.sprite.getPosition() != to)
            {
                sf::Vector2f const delta = to - obj.sprite.getPosition();
                float const ds = speed * dt;
                float const off = ds / std::sqrt(delta.x * delta.x + delta.y * delta.y);
                sf::Vector2f const pos = off < 1 ? obj.sprite.getPosition() + delta * off : to;
                obj.sprite.setPosition(pos);
            }
        }
        void update(GeSoul& obj,float time) {
            SoulmoveTo(obj, { position.x + 20.f + obj.getSprite().getGlobalBounds().width, position.y}, 5.f, 0.01f * time);
            vragPtr->stunned = true;

        }
        void draw(sf::RenderWindow& window) {
            window.draw(sprite);
        }
        bool getDeletes() {
            return vragPtr->health < 0;
        }
        bool getDeletesClock() {
            return TimeAction.getElapsedTime().asSeconds() >= 5.f;
        }
        auto getVrag() { return vragPtr; }
        
        sf::Sprite& getSprite() { return sprite; }
        sf::FloatRect getHitBox() { return sprite.getGlobalBounds(); }
    };

    void GeSoulDamage(GeSoul& las, std::list<GeSoul*>& lasers) {
        for (auto it = lasers.begin(); it != lasers.end(); /* без ++it здесь */) {
            if ((*it)->getDeletesClock() == true) {
                (*it)->getVrag()->stunned = false;
                it = lasers.erase(it);
            }
            else {
                ++it;
            }
        }
        for (auto it = lasers.begin(); it != lasers.end(); /* без ++it здесь */) {
            if ((*it)->getDeletes() == true) {
                (*it)->getVrag()->stunned = false;
                it = lasers.erase(it);
            }
            else {
                ++it;
            }
        }

    }

    class WsDisc {
    private:
        sf::Sprite sprite;
        sf::Texture texture;
        Vragi* vragPtr;
        sf::Clock TimeAction;
        sf::RectangleShape EffectTime;
        float width;
        float height;
        sf::SoundBuffer WsDiscbuffer;
        bool playsound;
        sf::Sound WsDiscSound;
    public:
        WsDisc(Vragi& vrag) {
            texture.loadFromFile("sprites\\powers\\WsDisc.png");
            sprite.setTexture(texture);
            sprite.setPosition({(vrag.sprite.getPosition().x + (vrag.sprite.getGlobalBounds().width / 2.f)) - (sprite.getGlobalBounds().width / 2.f),vrag.sprite.getPosition().y - sprite.getGlobalBounds().height});
            vragPtr = &vrag;
            width = 24.f;
            height = 6.f;
            EffectTime.setFillColor(sf::Color::White);
            EffectTime.setSize({ width,height });
            WsDiscbuffer.loadFromFile("sounds\\stands\\WsDisc.ogg");
            WsDiscSound.setBuffer(WsDiscbuffer);
            playsound = true;
        }
      
        void update() {
            if (playsound == true) {
                playsound = false;
                WsDiscSound.play();
            }
            sprite.setPosition({ (vragPtr->sprite.getPosition().x + (vragPtr->sprite.getGlobalBounds().width / 2.f)) - (sprite.getGlobalBounds().width / 2.f),vragPtr->sprite.getPosition().y - sprite.getGlobalBounds().height - 2.f });
            EffectTime.setPosition({ sprite.getPosition().x, sprite.getPosition().y - 6.f });
            EffectTime.setSize({ (10.f - TimeAction.getElapsedTime().asSeconds()) / 10.f * width, height });
            vragPtr->StandOff = true;

        }
        void draw(sf::RenderWindow& window) {
            window.draw(sprite);
            window.draw(EffectTime);
        }
        bool getDeletes() {
            return vragPtr->health < 0;
        }
        bool getDeletesClock() {
            return TimeAction.getElapsedTime().asSeconds() >= 10.f;
        }
        auto getVrag() { return vragPtr; }

        sf::Sprite& getSprite() { return sprite; }
        sf::FloatRect getHitBox() { return sprite.getGlobalBounds(); }
    };

    void WsDiscDamage(WsDisc& las, std::list<WsDisc*>& lasers) {
        for (auto it = lasers.begin(); it != lasers.end(); /* без ++it здесь */) {
            if ((*it)->getDeletesClock() == true) {
                (*it)->getVrag()->StandOff = false;
                it = lasers.erase(it);
            }
            else {
                ++it;
            }
        }
        for (auto it = lasers.begin(); it != lasers.end(); /* без ++it здесь */) {
            if ((*it)->getDeletes() == true) {
                (*it)->getVrag()->StandOff = false;
                it = lasers.erase(it);
            }
            else {
                ++it;
            }
        }

    }

    class WsAcidCloud {
    private:
        sf::Sprite sprite;
       
      
        sf::Clock TimeAction;
        sf::Clock Damage;
        sf::SoundBuffer buffer;
        bool soundplay;
        sf::Sound sound;
        sf::Texture textures[8];
        int cadr;
        float vremya;
        
    public:
        WsAcidCloud(Vragi& vrag, Stand& pl) {
            for (int i = 0; i < 8; i++) {
                textures[i].loadFromFile("sprites\\powers\\WsAcid" + std::to_string(i+1) + ".png");
            }
            sprite.setTexture(textures[0]);
            sprite.setPosition({ (pl.sprite.getPosition().x + (pl.sprite.getGlobalBounds().width / 2.f)) - (sprite.getGlobalBounds().width / 2.f), (pl.sprite.getPosition().y + (pl.sprite.getGlobalBounds().height / 2.f) - (sprite.getGlobalBounds().height / 2.f))});
            buffer.loadFromFile("sounds\\stands\\WsAcid.ogg");
           sound.setBuffer(buffer);
            soundplay = true;
            vremya = 150.f;
            cadr = 0;
           
        }

        void update(Stand& pl, Vragi& vrag) {
            if (soundplay == true) {
                sound.play();
                soundplay = false;
            }
            if (vremya <  TimeAction.getElapsedTime().asMilliseconds()) {
                
                vremya = vremya + 150.f;
                sprite.setTexture(textures[cadr]);
                if (cadr != 7) {
                    cadr++;
                }
                else {
                    cadr = 0;
                }
            }
            sprite.setPosition({ (pl.sprite.getPosition().x + (pl.sprite.getGlobalBounds().width / 2.f)) - (sprite.getGlobalBounds().width / 2.f), (pl.sprite.getPosition().y + (pl.sprite.getGlobalBounds().height / 2.f) - (sprite.getGlobalBounds().height / 2.f)) });
            if (Damage.getElapsedTime().asSeconds() > 1.f && vrag.sprite.getGlobalBounds().intersects(sprite.getGlobalBounds())) {
                vrag.health = vrag.health - 2.f - (vrag.health * 0.04f) ;
                Damage.restart();
           }
            

        }
        void draw(sf::RenderWindow& window) {
            window.draw(sprite);
         
        }
       
        bool getDeletesClock() {
            return TimeAction.getElapsedTime().asSeconds() >= 10.f;
        }
    

        sf::Sprite& getSprite() { return sprite; }
        sf::FloatRect getHitBox() { return sprite.getGlobalBounds(); }
    };

    void WsAcidCloudDamage(WsAcidCloud& las, std::list<WsAcidCloud*>& lasers) {
        for (auto it = lasers.begin(); it != lasers.end(); /* без ++it здесь */) {
            if ((*it)->getDeletesClock() == true) {
                
                it = lasers.erase(it);
            }
            else {
                ++it;
            }
        }
        

    }
    class CmoonRotate {
    private:
        
       
        sf::Clock TimeAction;
     
      
        sf::SoundBuffer buffer;
        bool soundplay;
        sf::Sound sound;
        sf::SoundBuffer buffer2;
        bool soundplay2;
        sf::Sound sound2;
        float angle;
        bool active;
        float vremya;
    public:
        CmoonRotate() {
           
           
            vremya = 50.f;
            buffer.loadFromFile("sounds\\stands\\CmGravityShift.ogg");
            sound.setBuffer(buffer);
            soundplay = false;
            buffer2.loadFromFile("sounds\\stands\\CmGravityShiftBack.ogg");
            sound2.setBuffer(buffer2);
            soundplay2 = false;
            angle = 0.f;
            active = false;
        }

        void update(Vragi& vrag,sf::View& view) {
            if (soundplay == true) {
                sound.play();
                soundplay = false;
            }
            if (active == true && vremya < TimeAction.getElapsedTime().asMilliseconds() && angle != -10.f){
                view.setRotation(angle);
                vremya = vremya + 50.f;
                angle -= 1.f;
                
               
            }
            if (active == true) {
                vrag.sprite.move(0.05f, 0.f);
                vrag.stunned = true;
                vrag.StandOff = true;
            }
            if (active == true && 10.f < TimeAction.getElapsedTime().asSeconds()) {
                active = false;
                vrag.stunned = false;
                vrag.StandOff = false;
            
            }
            if (active == false && view.getRotation() != 0.f) {
                view.setRotation(angle);
                angle += 1.f;
              
            }
            if (active == false && soundplay2 == true) {
                sound2.play();
                soundplay2 = false;
            }
        }
        
        void Activate() {
            vremya = 100.f;
            angle = 0.f;
            active = true;
            TimeAction.restart();
            soundplay = true;
            soundplay2 = true;
       }
       
    };

    