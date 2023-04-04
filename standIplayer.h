#pragma once
#include "settings.h"





bool isTimeStopped = false;
bool isEmeraldSplash = false;
bool isWrOxy = false;
bool isMandomTime = false;
bool PlayerAttack = false;
bool SAWBublCreate = false;


sf::Clock EmeraldSplashTm;
sf::Clock timestop;
sf::Clock AttackTm;
sf::Clock MandomTime;
sf::Clock MandomTimeTimeout;
sf::Clock Barrageplayer;
sf::Clock WROxy;
sf::Clock SAWBublTm;


struct Stand {
    sf::Texture texture;
    sf::Sprite sprite;
    bool visible = false;
    bool barrage = false;
    
    // добавьте поля, методы и конструкторы по необходимости
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
    float health = 200;
    int FighTech = 1;
    bool attacking;

    // добавьте поля, методы и конструкторы по необходимости
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

void PlayerUpdate(Player& obj,float speedx, float speedy, std::string LeftSpriteFileNAME, std::string RightSpriteMOVEFileNAME, std::string LeftSpriteMoveFileNAME, std::string RightSpriteFileNAME, Stand& stands) {
    
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && obj.sprite.getPosition().y >= 0) {
        obj.sprite.move(0, -speedy);
        obj.up = true;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && obj.sprite.getPosition().y + 96 <= 2160) {
        obj.sprite.move(0, speedy);
        obj.up = false;
    }
  
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && obj.sprite.getPosition().x + 44 <= 3840) {
        if (obj.attacking == true) {
            obj.texture.loadFromFile("sprites\\player\\player1rightAttacking.png");
        }
        else {
            obj.texture.loadFromFile(RightSpriteMOVEFileNAME);
        }
        obj.sprite.move(speedx, 0);
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
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)&& obj.sprite.getPosition().x >= 0) {
        obj.left = true;
        if (obj.attacking == true) {
            obj.texture.loadFromFile("sprites\\player\\player1leftAttacking.png");
        }
        else {
            obj.texture.loadFromFile(LeftSpriteMoveFileNAME);
        }
       
        obj.sprite.move(-speedx, 0);
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

void StandUpdate(Stand& stand, Player& obj) {
 if (stand.visible == true) {
       /*1 - the world
       2 - Mandom
       3 - Weather Report
       4 - Hierophat Green
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
                    moveTo(stand, { obj.sprite.getPosition().x + 60, obj.sprite.getPosition().y - 50 }, 3.5, 1.1f);
                }
                if (stand.barrage == true) {
                    moveTo(stand, { obj.sprite.getPosition().x - 60, obj.sprite.getPosition().y - 20 }, 3.5, 2.5f);
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
                    moveTo(stand, { obj.sprite.getPosition().x - 60, obj.sprite.getPosition().y - 50 }, 3.5, 1.1f);
                }
                if (stand.barrage == true) {
                    moveTo(stand, { obj.sprite.getPosition().x + 60, obj.sprite.getPosition().y - 20 }, 3.5, 2.5f);
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
               
                moveTo(stand, { obj.sprite.getPosition().x + 50, obj.sprite.getPosition().y  }, 3.5, 1.5f);

            }
            if (obj.left == false) {
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
                    stand.texture.loadFromFile("sprites\\stands\\MandomRightMove.png");
                }
                else {
                    stand.texture.loadFromFile("sprites\\stands\\Mandom1Right.png");
                }
                
                moveTo(stand, { obj.sprite.getPosition().x - 20, obj.sprite.getPosition().y  }, 3.5, 1.5f);

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
                    moveTo(stand, { obj.sprite.getPosition().x - 60, obj.sprite.getPosition().y - 20 }, 3.5, 2.5f);
                }
                else if (stand.barrage == false) {
                    moveTo(stand, { obj.sprite.getPosition().x + 60, obj.sprite.getPosition().y - 50 }, 3.5, 1.1f);
                }
                else if (stand.barrage == true) {
                    moveTo(stand, { obj.sprite.getPosition().x - 60, obj.sprite.getPosition().y - 20 }, 3.5, 2.5f);
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
                    moveTo(stand, { obj.sprite.getPosition().x + 60, obj.sprite.getPosition().y - 20 }, 3.5, 2.5f);
                }
                else if (stand.barrage == false) {
                    moveTo(stand, { obj.sprite.getPosition().x - 60, obj.sprite.getPosition().y - 50 }, 3.5, 1.1f);
                }
                else if (stand.barrage == true) {
                    moveTo(stand, { obj.sprite.getPosition().x + 60, obj.sprite.getPosition().y - 20 }, 3.5, 2.5f);
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
                    stand.texture.loadFromFile("sprites\\stands\\HGLeft.png"); //  TwLeftMove.png
                }
                else {
                    stand.texture.loadFromFile("sprites\\stands\\HGLeft.png");
                }
                
                if (isEmeraldSplash == true) {
                    moveTo(stand, { obj.sprite.getPosition().x - 60, obj.sprite.getPosition().y - 20 }, 3.5, 2.5f);
                }
                else if (stand.barrage == false) {
                    moveTo(stand, { obj.sprite.getPosition().x + 60, obj.sprite.getPosition().y - 50 }, 3.5, 1.1f);
                }
                else if (stand.barrage == true) {
                    moveTo(stand, { obj.sprite.getPosition().x - 60, obj.sprite.getPosition().y - 20 }, 3.5, 2.5f);
                }

            }
            if (obj.left == false) {
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
                    stand.texture.loadFromFile("sprites\\stands\\HGRight.png"); // TwRightMove.png
                }
                else {
                    stand.texture.loadFromFile("sprites\\stands\\HGRight.png");
                }
                if (isEmeraldSplash == true) {
                    moveTo(stand, { obj.sprite.getPosition().x + 60, obj.sprite.getPosition().y - 20 }, 3.5, 2.5f);
                }
                
                else  if (stand.barrage == false) {
                    moveTo(stand, { obj.sprite.getPosition().x - 60, obj.sprite.getPosition().y - 50 }, 3.5, 1.1f);
                }
                else if (stand.barrage == true) {
                    moveTo(stand, { obj.sprite.getPosition().x + 60, obj.sprite.getPosition().y - 20 }, 3.5, 2.5f);
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
                    stand.texture.loadFromFile("sprites\\stands\\SAWLeft.png"); //  TwLeftMove.png
                }
                else {
                    stand.texture.loadFromFile("sprites\\stands\\SAWLeft.png");
                }

              
                if (stand.barrage == false) {
                    moveTo(stand, { obj.sprite.getPosition().x + 60, obj.sprite.getPosition().y - 50 }, 3.5, 1.1f);
                }
                else if (stand.barrage == true) {
                    moveTo(stand, { obj.sprite.getPosition().x - 60, obj.sprite.getPosition().y - 20 }, 3.5, 2.5f);
                }

            }
            if (obj.left == false) {
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
                    stand.texture.loadFromFile("sprites\\stands\\SAWRight.png"); // TwRightMove.png
                }
                else {
                    stand.texture.loadFromFile("sprites\\stands\\SAWRight.png");
                }
                

                if (stand.barrage == false) {
                    moveTo(stand, { obj.sprite.getPosition().x - 60, obj.sprite.getPosition().y - 50 }, 3.5, 1.1f);
                }
                else if (stand.barrage == true) {
                    moveTo(stand, { obj.sprite.getPosition().x + 60, obj.sprite.getPosition().y - 20 }, 3.5, 2.5f);
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

void AuraUpdate(Aura& obj, Player& pl, Stand& st) {
    obj.sprite.setPosition(pl.sprite.getPosition().x - 4.f, pl.sprite.getPosition().y - 2.f);
    if (st.visible == true) {
        obj.visible = true;
        obj.Frame += 0.1;
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