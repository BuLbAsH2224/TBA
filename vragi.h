#pragma once
#include "settings.h"
// ����������, ������� ����� ������� ���������� ������ � ��
float playerX, playerY, aiX, aiY;

// ����������, ������� ����� ������� �������� ��
float aiSpeed = 0.2f;

struct Vragi {
    bool left = false;
    sf::Texture texture;
    sf::Sprite sprite;
    int stand = 0;
    float health;
    float maxhealth;
    bool statics;
    std::string Name;
    int Reward;
    bool stoppedbytime = false;
};

void VragiInit(Vragi& obj, std::string fileName, int stand, float health, sf::Vector2f pos, bool tupoi, std::string name, int rewards) {
    obj.texture.loadFromFile(fileName);
    obj.sprite.setTexture(obj.texture);
    obj.stand = stand;
    obj.health = health;
    obj.sprite.setPosition(pos);
    obj.statics = tupoi;
    obj.Name = name;
    obj.Reward = rewards;
    obj.maxhealth = health;
}

void VragiAuraUpdate(Aura& obj, Vragi& pl, Stand& st, float time) {
    obj.sprite.setPosition(pl.sprite.getPosition().x - 4.f, pl.sprite.getPosition().y - 2.f);
    if (pl.stoppedbytime == false) {
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
}

void VragiUpdate(Vragi& obj, Stand& st, Player& pl1, float time) {
    if (obj.health > 0) {




        if (obj.statics == true) {
            // ���� ��������� �� �����
        }
        else if (D4CDimension == false){
            if(st.visible == false && rand() % 100 == 50){
                st.visible = true;
                 }
            // ���������� ����������� �������� �����
            if (obj.sprite.getPosition().x < pl1.sprite.getPosition().x && obj.stoppedbytime == false) {
                obj.sprite.move(0.1f * time, 0); // ���� �������� ������
                obj.left = false;
            }
            else if(obj.stoppedbytime == false){
                obj.sprite.move(-0.1f * time, 0); // ���� �������� �����
                obj.left = true;
            }
            if (obj.left == true) {
                obj.texture.loadFromFile("sprites\\npc\\PlohoiParenLeft.png");
            }
            else if (obj.left == false) {
                obj.texture.loadFromFile("sprites\\npc\\PlohoiParenRight.png");
            }
        }
    }
}

void VragiDraw(sf::RenderWindow& window, Vragi& obj) {
    if (obj.health > 0 && D4CDimension == false) {
        window.draw(obj.sprite);
    }
}

sf::Clock BarrageVrag;
sf::Clock VragPowerH;

bool VragIsTimeStopped;


void VragiStandUpdate(Stand& stand, Vragi& obj, float time) {
    if (obj.stand == 0) {
        stand.visible = false;
    }
    if (stand.visible == true && obj.stoppedbytime == false && D4CDimension == false) {

        /*1 - the world
        2 - Mandom
        3 - Weather Report
        4 - Hierophat Green
        5 - Soft And Wet
        6 - D4C
         */
        if (obj.stand == 1) {



            if (obj.left == true) {
                if (obj.left == true) {
                    stand.texture.loadFromFile("sprites\\stands\\TwLeftMove.png");
                }
            
                if (stand.barrage == false) {
                    moveTo(stand, { obj.sprite.getPosition().x + 60, obj.sprite.getPosition().y - 50 }, 3.5, 0.11f * time);
                }
                if (stand.barrage == true) {
                    moveTo(stand, { obj.sprite.getPosition().x - 60, obj.sprite.getPosition().y - 20 }, 3.5, 0.25f * time);
                }

            }
            if (obj.left == false) {
               
                    stand.texture.loadFromFile("sprites\\stands\\TwRightMove.png");
             
               
                if (stand.barrage == false) {
                    moveTo(stand, { obj.sprite.getPosition().x - 60, obj.sprite.getPosition().y - 50 }, 3.5, 0.11f * time);
                }
                if (stand.barrage == true) {
                    moveTo(stand, { obj.sprite.getPosition().x + 60, obj.sprite.getPosition().y - 20 }, 3.5, 0.25f * time);
                }


            }

            if (VragPowerH.getElapsedTime().asSeconds() >= 30 && VragIsTimeStopped == false && rand () % 100 == 50) {
               



                    VragIsTimeStopped = true;

                    VragPowerH.restart();
                
            }
            if (stand.barrage == true && BarrageVrag.getElapsedTime().asSeconds() >= 10.f) {
                stand.barrage = false;
            }
            if (rand() % 100 == 50 && BarrageVrag.getElapsedTime().asSeconds() >= 20.f || rand() % 70 == 50 && VragIsTimeStopped == true && BarrageVrag.getElapsedTime().asSeconds() >= 15.f) {
                if (stand.barrage == false)
                {
                    BarrageVrag.restart();
                    stand.barrage = true;
                }
            }
        }
       
    }
}

void VragiBarrageDamage(Player &vrag, float time, Vragi& pl, Stand& st) {
    if (pl.stoppedbytime == false && D4CDimension == false) {
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
}

class VragiHealth {

private:
    sf::Sprite sprite;
    sf::Texture texture;
    bool visible;
public:
    VragiHealth() {
        texture.loadFromFile("sprites\\hud\\angeloHealth10.png");
        sprite.setTexture(texture);
        visible = true;

    }


    void update(sf::Vector2f pos, Vragi& pl) {
        
        sprite.setPosition({pos});
        
        if (pl.health > 90.f) { texture.loadFromFile("sprites\\hud\\angeloHealth10.png"); }
        else   if (pl.health > 80.f) { texture.loadFromFile("sprites\\hud\\angeloHealth9.png"); }
        else   if (pl.health > 70.f) { texture.loadFromFile("sprites\\hud\\angeloHealth8.png"); }
        else   if (pl.health > 60.f) { texture.loadFromFile("sprites\\hud\\angeloHealth7.png"); }
        else   if (pl.health > 50.f) { texture.loadFromFile("sprites\\hud\\angeloHealth6.png"); }
        else   if (pl.health > 40.f) { texture.loadFromFile("sprites\\hud\\angeloHealth5.png"); }
        else   if (pl.health > 30.f) { texture.loadFromFile("sprites\\hud\\angeloHealth4.png"); }
        else   if (pl.health > 20.f) { texture.loadFromFile("sprites\\hud\\angeloHealth3.png"); }
        else   if (pl.health > 10.f) { texture.loadFromFile("sprites\\hud\\angeloHealth2.png"); }
        else   if (pl.health > 0.f) { texture.loadFromFile("sprites\\hud\\angeloHealth1.png"); }
    }
    sf::Sprite getSprite() { return sprite; }
    void Draw(sf::RenderWindow& window) {
        if (visible == true) {
            window.draw(sprite);
        }
    }
};