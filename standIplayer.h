#pragma once
#include "settings.h"





bool isTimeStopped = false;
bool isEmeraldSplash = false;
bool isWrOxy = false;
bool isMandomTime = false;
bool PlayerAttack = false;
bool SAWBublCreate = false;
bool D4CDimension = false;
bool D4CDimensionClones = false;

sf::Clock EmeraldSplashTm;
sf::Clock timestop;
sf::Clock AttackTm;
sf::Clock MandomTime;
sf::Clock MandomTimeTimeout;
sf::Clock Barrageplayer;
sf::Clock WROxy;
sf::Clock SAWBublTm;
sf::Clock Hbuttontime;
sf::Clock Gbuttontime;

struct Stand {
    sf::Texture texture;
    sf::Sprite sprite;
    bool visible = false;
    bool barrage = false;
    
};
void moveTo(Stand& obj, sf::Vector2f to, float dt, float speed)
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


struct Player {
    bool up = false;
    bool left = false;
    sf::Texture texture;
    sf::Sprite sprite;
    int stand = 0;
    int old_stand;
    float speed = 0.2f;
    int money = 0;
    float health = 200;
    float maxhealth = 200;
    int FighTech = 1;
    bool attacking;
    bool stoi = false;
   
};

void PlayerInit(Player& obj, std::string fileName) {
    obj.texture.loadFromFile(fileName);
    obj.sprite.setTexture(obj.texture);
    obj.stand = 0;
    obj.sprite.setPosition(1632,1054);
}
void StandInit(Stand& obj, std::string fileName) {
    obj.texture.loadFromFile(fileName);
    obj.sprite.setTexture(obj.texture);
    obj.sprite.setPosition(500 - 100, 500);
    
}


void PlayerDraw(sf::RenderWindow& window, Player& obj) {
    window.draw(obj.sprite);
}

void PlayerUpdate(Player& obj, std::string LeftSpriteFileNAME, std::string RightSpriteMOVEFileNAME, std::string LeftSpriteMoveFileNAME, std::string RightSpriteFileNAME, Stand& stands, float time) {
    if (obj.health > obj.maxhealth) {
        obj.health = obj.maxhealth;
    }
    if (obj.stand != 0) {
        obj.old_stand = obj.stand;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && obj.sprite.getPosition().y >= 0 && obj.stoi == false) {
        obj.sprite.move(0, -obj.speed * time);
        obj.up = true;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && obj.sprite.getPosition().y + 96.f <= 2160 && obj.stoi == false) {
        obj.sprite.move(0, obj.speed * time);
        obj.up = false;
    }
  
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && obj.sprite.getPosition().x + 44.f <= 3840 && obj.stoi == false) {
        if (obj.attacking == true) {
            obj.texture.loadFromFile("sprites\\player\\player1rightAttacking.png");
        }
        else {
            obj.texture.loadFromFile(RightSpriteMOVEFileNAME);
        }
        obj.sprite.move(obj.speed * time, 0);
        obj.left = false;
    }
    else {
        if (obj.attacking == true && obj.left == false) {
            obj.texture.loadFromFile("sprites\\player\\player1rightAttacking.png");
        }
        else  if (obj.left == false) {
            obj.texture.loadFromFile(RightSpriteFileNAME);
        }

    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)&& obj.sprite.getPosition().x >= 0 && obj.stoi == false) {
        obj.left = true;
        if (obj.attacking == true) {
            obj.texture.loadFromFile("sprites\\player\\player1leftAttacking.png");
        }
        else {
            obj.texture.loadFromFile(LeftSpriteMoveFileNAME);
        }
       
        obj.sprite.move(-obj.speed * time, 0);
    }
    else {
        if (obj.attacking == true && obj.left == true) {
            obj.texture.loadFromFile("sprites\\player\\player1leftAttacking.png");
        }
        else if (obj.left == true) {
            obj.texture.loadFromFile(LeftSpriteFileNAME);
        }

    }
   
   
     }


void StandDraw(sf::RenderWindow& window, Stand& obj) {
    if (obj.visible == true) {
        window.draw(obj.sprite);
    }
}

void StandUpdate(Stand& stand, Player& obj, float time) {
    if (obj.stand == 0) {
        stand.visible = false;
    }
 if (stand.visible == true && obj.stoi == false) {
       /*1 - the world
       2 - Mandom
       3 - Weather Report
       4 - Hierophat Green
       5 - Soft And Wet
       6 - D4C
        */
        if (obj.stand == 1) {
           
                
            
            if (obj.left == true) {
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
                    stand.texture.loadFromFile("sprites\\stands\\TwLeftMove.png");
                }
                else {
                    stand.texture.loadFromFile("sprites\\stands\\TwLeft.png");
                }
                if (stand.barrage == false) {
                    moveTo(stand, { obj.sprite.getPosition().x + 60, obj.sprite.getPosition().y - 50 }, 3.5, 0.11f * time);
                }
                if (stand.barrage == true) {
                    moveTo(stand, { obj.sprite.getPosition().x - 60, obj.sprite.getPosition().y - 20 }, 3.5, 0.25f * time);
                }
                
            }
            if (obj.left == false) {
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
                    stand.texture.loadFromFile("sprites\\stands\\TwRightMove.png");
                }
                else {
                    stand.texture.loadFromFile("sprites\\stands\\TwRight.png");
                }
                if (stand.barrage == false) {
                    moveTo(stand, { obj.sprite.getPosition().x - 60, obj.sprite.getPosition().y - 50 }, 3.5, 0.11f * time);
                }
                if (stand.barrage == true) {
                    moveTo(stand, { obj.sprite.getPosition().x + 60, obj.sprite.getPosition().y - 20 }, 3.5, 0.25f * time);
                }
               

            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::H)) {
                if (isTimeStopped == false && timestop.getElapsedTime().asSeconds() > 30.f)
                {
                    
               
                  
                    isTimeStopped = true; 
                  
                    timestop.restart();
                }
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::R) && Barrageplayer.getElapsedTime().asSeconds() > 20.f) {
                if (stand.barrage == false )
                {
                    Barrageplayer.restart();
                    stand.barrage = true;
                }
            }
        }
        if (obj.stand == 2) {
            
            if (obj.left == true) {
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
                    stand.texture.loadFromFile("sprites\\stands\\MandomLeftMove.png");
                }
                else {
                    stand.texture.loadFromFile("sprites\\stands\\Mandom1Left.png");
                }
               
                moveTo(stand, { obj.sprite.getPosition().x + 50, obj.sprite.getPosition().y  }, 3.5, 0.15f * time);

            }
            if (obj.left == false) {
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
                    stand.texture.loadFromFile("sprites\\stands\\MandomRightMove.png");
                }
                else {
                    stand.texture.loadFromFile("sprites\\stands\\Mandom1Right.png");
                }
                
                moveTo(stand, { obj.sprite.getPosition().x - 20, obj.sprite.getPosition().y  }, 3.5, 0.15f * time);

            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::H)) {
                if (isMandomTime == false && MandomTimeTimeout.getElapsedTime().asSeconds() > 15.f)
                {



                    isMandomTime = true;
                    MandomTime.restart();
                    MandomTimeTimeout.restart();
                }
            }
        }
        if (obj.stand == 3) {



            if (obj.left == true) {
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
                    stand.texture.loadFromFile("sprites\\stands\\WRLeftMove.png");
                }
                else {
                    stand.texture.loadFromFile("sprites\\stands\\WRLeft.png");
                }
                if (isWrOxy == true && WROxy.getElapsedTime().asSeconds() < 1.f) {
                    moveTo(stand, { obj.sprite.getPosition().x - 60, obj.sprite.getPosition().y - 20 }, 3.5, 0.25f * time);
                }
                else if (stand.barrage == false) {
                    moveTo(stand, { obj.sprite.getPosition().x + 60, obj.sprite.getPosition().y - 50 }, 3.5, 0.11f * time);
                }
                else if (stand.barrage == true) {
                    moveTo(stand, { obj.sprite.getPosition().x - 60, obj.sprite.getPosition().y - 20 }, 3.5, 0.25f * time);
                }

            }
            if (obj.left == false) {
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
                    stand.texture.loadFromFile("sprites\\stands\\WRRightMove.png");
                }
                else {
                    stand.texture.loadFromFile("sprites\\stands\\WRRight.png");
                }
                if (isWrOxy == true && WROxy.getElapsedTime().asSeconds() < 1.f) {
                    moveTo(stand, { obj.sprite.getPosition().x + 60, obj.sprite.getPosition().y - 20 }, 3.5, 0.25f * time);
                }
                else if (stand.barrage == false) {
                    moveTo(stand, { obj.sprite.getPosition().x - 60, obj.sprite.getPosition().y - 50 }, 3.5, 0.11f * time);
                }
                else if (stand.barrage == true) {
                    moveTo(stand, { obj.sprite.getPosition().x + 60, obj.sprite.getPosition().y - 20 }, 3.5, 0.25f * time);
                }


            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::H)) {
                if (isWrOxy == false && WROxy.getElapsedTime().asSeconds() > 30.f)
                {

                    isWrOxy = true;
                    WROxy.restart();
                }
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::R) && Barrageplayer.getElapsedTime().asSeconds() > 20.f) {
                if (stand.barrage == false)
                {
                    Barrageplayer.restart();
                    stand.barrage = true;
                }
            }
        }
        if (obj.stand == 4) {



            if (obj.left == true) {
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
                    stand.texture.loadFromFile("sprites\\stands\\HGLeftMove.png"); //  TwLeftMove.png
                }
                else {
                    stand.texture.loadFromFile("sprites\\stands\\HG.png");
                }
                
                if (isEmeraldSplash == true) {
                    moveTo(stand, { obj.sprite.getPosition().x - 60, obj.sprite.getPosition().y - 20 }, 3.5, 0.25f * time);
                }
                else if (stand.barrage == false) {
                    moveTo(stand, { obj.sprite.getPosition().x + 60, obj.sprite.getPosition().y - 50 }, 3.5, 0.11f * time);
                }
                else if (stand.barrage == true) {
                    moveTo(stand, { obj.sprite.getPosition().x - 60, obj.sprite.getPosition().y - 20 }, 3.5, 0.25f * time);
                }

            }
            if (obj.left == false) {
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
                    stand.texture.loadFromFile("sprites\\stands\\HGRightMove.png"); // TwRightMove.png
                }
                else {
                    stand.texture.loadFromFile("sprites\\stands\\HG.png");
                }
                if (isEmeraldSplash == true) {
                    moveTo(stand, { obj.sprite.getPosition().x + 60, obj.sprite.getPosition().y - 20 }, 3.5, 0.25f * time);
                }
                
                else  if (stand.barrage == false) {
                    moveTo(stand, { obj.sprite.getPosition().x - 60, obj.sprite.getPosition().y - 50 }, 3.5, 0.11f * time);
                }
                else if (stand.barrage == true) {
                    moveTo(stand, { obj.sprite.getPosition().x + 60, obj.sprite.getPosition().y - 20 }, 3.5, 0.25f * time);
                }


            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::H)) {
                if (isEmeraldSplash == false && EmeraldSplashTm.getElapsedTime().asSeconds() > 45.f && stand.barrage == false)
                {
                    isEmeraldSplash = true;
                    EmeraldSplashTm.restart();
			}
                }
            
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::R) && Barrageplayer.getElapsedTime().asSeconds() > 20.f && isEmeraldSplash == false) {
                if (stand.barrage == false)
                {
                    Barrageplayer.restart();
                    stand.barrage = true;
                }
            }
        }
        if (obj.stand == 5) {



            if (obj.left == true) {
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
                    stand.texture.loadFromFile("sprites\\stands\\SAWLeftMove.png"); //  TwLeftMove.png
                }
                else {
                    stand.texture.loadFromFile("sprites\\stands\\SAW.png");
                }

              
                if (stand.barrage == false) {
                    moveTo(stand, { obj.sprite.getPosition().x + 60, obj.sprite.getPosition().y - 50 }, 3.5, 0.11f * time);
                }
                else if (stand.barrage == true) {
                    moveTo(stand, { obj.sprite.getPosition().x - 60, obj.sprite.getPosition().y - 20 }, 3.5, 0.25f * time);
                }

            }
            if (obj.left == false) {
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
                    stand.texture.loadFromFile("sprites\\stands\\SAWRightMove.png"); // TwRightMove.png
                }
                else {
                    stand.texture.loadFromFile("sprites\\stands\\SAW.png");
                }
                

                if (stand.barrage == false) {
                    moveTo(stand, { obj.sprite.getPosition().x - 60, obj.sprite.getPosition().y - 50 }, 3.5, 0.11f * time);
                }
                else if (stand.barrage == true) {
                    moveTo(stand, { obj.sprite.getPosition().x + 60, obj.sprite.getPosition().y - 20 }, 3.5, 0.25f * time);
                }


            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::H)) {
                if (SAWBublCreate == false && SAWBublTm.getElapsedTime().asSeconds() > 1.f && stand.barrage == false)
                {
                    SAWBublCreate = true;
                    SAWBublTm.restart();
                }
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::R) && Barrageplayer.getElapsedTime().asSeconds() > 20.f) {
                if (stand.barrage == false)
                {
                    Barrageplayer.restart();
                    stand.barrage = true;
                }
            }
        }
        if (obj.stand == 6) {



            if (obj.left == true) {
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
                    stand.texture.loadFromFile("sprites\\stands\\TwLeftMove.png");
                }
                else {
                    stand.texture.loadFromFile("sprites\\stands\\D4CLeft.png");
                }
                if (stand.barrage == false) {
                    moveTo(stand, { obj.sprite.getPosition().x + 60, obj.sprite.getPosition().y - 50 }, 3.5, 0.11f * time);
                }
                if (stand.barrage == true || D4CDimensionClones == true) {
                    moveTo(stand, { obj.sprite.getPosition().x - 60, obj.sprite.getPosition().y - 20 }, 3.5, 0.25f * time);
                }

            }
            if (obj.left == false) {
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
                    stand.texture.loadFromFile("sprites\\stands\\TwRightMove.png");
                }
                else {
                    stand.texture.loadFromFile("sprites\\stands\\D4CRight.png");
                }
                if (stand.barrage == false) {
                    moveTo(stand, { obj.sprite.getPosition().x - 60, obj.sprite.getPosition().y - 50 }, 3.5, 0.11f * time);
                }
                if (stand.barrage == true || D4CDimensionClones == true ) {
                    moveTo(stand, { obj.sprite.getPosition().x + 60, obj.sprite.getPosition().y - 20 }, 3.5, 0.25f * time);
                }


            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::G) && stand.barrage == false) {
                if (D4CDimension == false && Gbuttontime.getElapsedTime().asSeconds() > 30.f)
                {



                    D4CDimension = true;
                  
                    Gbuttontime.restart();
                }
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::H)) {
                if (D4CDimensionClones == false && Hbuttontime.getElapsedTime().asSeconds() >= 20.f)
                {


                    Hbuttontime.restart();
                    D4CDimensionClones = true;

                 
                }
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::R) && Barrageplayer.getElapsedTime().asSeconds() > 20.f && D4CDimension == false) {
                if (stand.barrage == false)
                {
                    Barrageplayer.restart();
                    stand.barrage = true;
                }
            }
        }
        if (obj.stand == 7) {



            if (obj.left == true) {
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
                    stand.texture.loadFromFile("sprites\\stands\\TwLeftMove.png");
                }
                else {
                    stand.texture.loadFromFile("sprites\\stands\\D4CLeft.png");
                }
                if (stand.barrage == false) {
                    moveTo(stand, { obj.sprite.getPosition().x + 60, obj.sprite.getPosition().y - 50 }, 3.5, 0.11f * time);
                }
                if (stand.barrage == true || D4CDimensionClones == true) {
                    moveTo(stand, { obj.sprite.getPosition().x - 60, obj.sprite.getPosition().y - 20 }, 3.5, 0.25f * time);
                }

            }
            if (obj.left == false) {
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
                    stand.texture.loadFromFile("sprites\\stands\\TwRightMove.png");
                }
                else {
                    stand.texture.loadFromFile("sprites\\stands\\D4CRight.png");
                }
                if (stand.barrage == false) {
                    moveTo(stand, { obj.sprite.getPosition().x - 60, obj.sprite.getPosition().y - 50 }, 3.5, 0.11f * time);
                }
                if (stand.barrage == true || D4CDimensionClones == true) {
                    moveTo(stand, { obj.sprite.getPosition().x + 60, obj.sprite.getPosition().y - 20 }, 3.5, 0.25f * time);
                }


            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::G) && stand.barrage == false) {
                if (D4CDimension == false && Gbuttontime.getElapsedTime().asSeconds() > 30.f)
                {



                    D4CDimension = true;

                    Gbuttontime.restart();
                }
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::H)) {
                if (D4CDimensionClones == false && Hbuttontime.getElapsedTime().asSeconds() >= 20.f)
                {


                    Hbuttontime.restart();
                    D4CDimensionClones = true;


                }
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::R) && Barrageplayer.getElapsedTime().asSeconds() > 20.f && D4CDimension == false) {
                if (stand.barrage == false)
                {
                    Barrageplayer.restart();
                    stand.barrage = true;
                }
            }
        }
    }
}


void StandSummon(Player& player1, Stand& playerstand) {

    if (player1.left == true) {
        if (player1.stand == 1) {
            playerstand.sprite.setPosition(player1.sprite.getPosition().x + 60, player1.sprite.getPosition().y - 50);
        }
        if (player1.stand == 2) {
            playerstand.sprite.setPosition(player1.sprite.getPosition().x + 50, player1.sprite.getPosition().y);
        }

        if (player1.stand == 3) {
            playerstand.sprite.setPosition(player1.sprite.getPosition().x + 60, player1.sprite.getPosition().y - 50);
        }
        if (player1.stand == 4) {
            playerstand.sprite.setPosition(player1.sprite.getPosition().x + 60, player1.sprite.getPosition().y - 50);
        }
        if (player1.stand == 5) {
            playerstand.sprite.setPosition(player1.sprite.getPosition().x + 60, player1.sprite.getPosition().y - 50);
        }
        if (player1.stand == 6) {
            playerstand.sprite.setPosition(player1.sprite.getPosition().x + 60, player1.sprite.getPosition().y - 50);
        }
    }
    if (player1.left == false) {
        if (player1.stand == 1) {
            playerstand.sprite.setPosition(player1.sprite.getPosition().x - 60, player1.sprite.getPosition().y - 50);
        }


        if (player1.stand == 2) {
            playerstand.sprite.setPosition(player1.sprite.getPosition().x - 20, player1.sprite.getPosition().y);
        }

        if (player1.stand == 3) {
            playerstand.sprite.setPosition(player1.sprite.getPosition().x - 60, player1.sprite.getPosition().y - 50);
        }
        if (player1.stand == 4) {
            playerstand.sprite.setPosition(player1.sprite.getPosition().x - 60, player1.sprite.getPosition().y - 50);
        }
        if (player1.stand == 5) {
            playerstand.sprite.setPosition(player1.sprite.getPosition().x - 60, player1.sprite.getPosition().y - 50);
        }
        if (player1.stand == 6) {
            playerstand.sprite.setPosition(player1.sprite.getPosition().x - 60, player1.sprite.getPosition().y - 50);
        }
    }
}



struct Aura {
    sf::Texture texture;
    sf::Sprite sprite;
    bool visible = false;
    float Frame = 0.f;
    int CurrentFrame = 1;
};
void AuraInit(Aura& obj, std::string fileName) {
    obj.texture.loadFromFile(fileName);
    obj.sprite.setTexture(obj.texture);
}

void AuraUpdate(Aura& obj, Player& pl, Stand& st, float time) {
    obj.sprite.setPosition(pl.sprite.getPosition().x - 4.f, pl.sprite.getPosition().y - 2.f);
    if (st.visible == true) {
        obj.visible = true;
        obj.Frame += 0.01f * time;
    }
    else obj.visible = false;
    
    if (obj.CurrentFrame == 1 && obj.Frame >= 1.5) {
        obj.CurrentFrame = 2;
        obj.Frame = 0.f;
    }
    if (obj.CurrentFrame == 2 && obj.Frame >= 1.5) {
        obj.CurrentFrame = 1;
        obj.Frame = 0.f;
    }
   
    if (pl.stand == 1) {
        if (obj.CurrentFrame == 1) {
            obj.texture.loadFromFile("sprites\\stands\\auras\\TwAuraFrame1.png");
        }
        if (obj.CurrentFrame == 2) {
            obj.texture.loadFromFile("sprites\\stands\\auras\\TwAuraFrame2.png");
        }
    }
    if (pl.stand == 2) {
        if (obj.CurrentFrame == 1) {
            obj.texture.loadFromFile("sprites\\stands\\auras\\MmAuraFrame1.png");
        }
        if (obj.CurrentFrame == 2) {
            obj.texture.loadFromFile("sprites\\stands\\auras\\MmAuraFrame2.png");
        }
    }
    if (pl.stand == 3) {
        if (obj.CurrentFrame == 1) {
            obj.texture.loadFromFile("sprites\\stands\\auras\\WRAuraFrame1.png");
        }
        if (obj.CurrentFrame == 2) {
            obj.texture.loadFromFile("sprites\\stands\\auras\\WRAuraFrame2.png");
        }
    }
    if (pl.stand == 4) {
        if (obj.CurrentFrame == 1) {
            obj.texture.loadFromFile("sprites\\stands\\auras\\HGAuraFrame1.png");
        }
        if (obj.CurrentFrame == 2) {
            obj.texture.loadFromFile("sprites\\stands\\auras\\HGAuraFrame2.png");
        }
    }
    if (pl.stand == 5) {
        if (obj.CurrentFrame == 1) {
            obj.texture.loadFromFile("sprites\\stands\\auras\\SAWAuraFrame1.png");
        }
        if (obj.CurrentFrame == 2) {
            obj.texture.loadFromFile("sprites\\stands\\auras\\SAWAuraFrame2.png");
        }
    }
}
void AuraDraw(sf::RenderWindow& window, Aura& obj) {
    if (obj.visible == true) {
        window.draw(obj.sprite);
    }
}



class PlayerHealth {

private:
    sf::Sprite sprite;
    sf::Texture texture;
    bool visible;
public:
    PlayerHealth() {
        texture.loadFromFile("sprites\\hud\\PlHp100.png");
        sprite.setTexture(texture);
        visible = true;

    }
   

    void update(sf::Vector2f pos, Player& pl, bool a) {
        if (a == true) {
            sprite.setPosition(pos.x - 420.f, pos.y - 250.f);
        }
        else {
            sprite.setPosition(pos.x - 936.f, pos.y - 500.f);
        }
        if (pl.health > 180){ texture.loadFromFile("sprites\\hud\\PlHp100.png"); }
        else   if (pl.health > 160) { texture.loadFromFile("sprites\\hud\\PlHp90.png"); }
        else   if (pl.health > 140) { texture.loadFromFile("sprites\\hud\\PlHp80.png"); }
        else   if (pl.health > 120) { texture.loadFromFile("sprites\\hud\\PlHp70.png"); }
        else   if (pl.health > 100) { texture.loadFromFile("sprites\\hud\\PlHp60.png"); }
        else   if (pl.health > 80) { texture.loadFromFile("sprites\\hud\\PlHp50.png"); }
        else   if (pl.health > 60) { texture.loadFromFile("sprites\\hud\\PlHp40.png"); }
        else   if (pl.health > 40) { texture.loadFromFile("sprites\\hud\\PlHp30.png"); }
        else   if (pl.health > 20) { texture.loadFromFile("sprites\\hud\\PlHp20.png"); }
        else   if (pl.health > 0) { texture.loadFromFile("sprites\\hud\\PlHp10.png"); }
    }
   
    void Draw(sf::RenderWindow& window) {
        if (visible == true) {
            window.draw(sprite);
        }
    }
};