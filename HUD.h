#pragma once
#include "settings.h"
struct HUD {
    sf::Texture texture;
    sf::Sprite sprite;
    bool visible = true;
};
void HudInit(HUD& obj, std::string fileName) {
    obj.texture.loadFromFile(fileName);
    obj.sprite.setTexture(obj.texture);
}

void HUDobjupdate(HUD& obj, sf::Vector2f pos,int a) {
    if (a == 1) {
        obj.sprite.setPosition(pos);
    }
}
void HudDraw(sf::RenderWindow& window, HUD& obj) {

    if (obj.visible == true) {
        window.draw(obj.sprite);
    }
}

class CursorArrow {
private:
    sf::Sprite sprite;
    sf::Texture texture;
    bool visible;
public:
    CursorArrow() {
        texture.loadFromFile("sprites\\hud\\Cursor.png");
        sprite.setTexture(texture);
        visible = true;

    }
  
    void update(sf::Vector2f pos) {
        sprite.setPosition(pos);

    }
  
    void draw(sf::RenderWindow& window) {
        if (visible == true) {
            window.draw(sprite);
        }
    }
};

class InventoryPreview {
private:
    sf::Texture texture;
    sf::Sprite sprite;
    bool IsOpen;
public:
    InventoryPreview() {
        texture.loadFromFile("sprites\\hud\\inventory\\inventoryPR.png");
        sprite.setTexture(texture);
        IsOpen = false;
    }
  
    void update(sf::Vector2f pos) {
        sprite.setPosition(pos);
        /*if (sprite.getGlobalBounds().contains(mouspos.x, mouspos.y)) {
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {

            }
        }*/
    }
    void draw(sf::RenderWindow& window) {
            window.draw(sprite);
 }
    
    sf::FloatRect getHitbox() { return sprite.getGlobalBounds(); }
   
};
class Item {
private:
    sf::Texture texture;
    sf::Sprite sprite;
    sf::Text weight;
    int weigt;
    bool IsMove;
    int ID;
public:
    
    Item() {
        texture.loadFromFile("sprites\\hud\\inventory\\testitem.png");
        sprite.setTexture(texture);
        IsMove = false;
        weigt = 0;
        ID = 0;
        // 0 - none
        // 1 - arrow
        // 2 - rokaka
        // 3 - dio diary
        // 4 - havchik
    }
    void updatedva() {
        if (ID == 0) {
            texture.loadFromFile("sprites\\hud\\inventory\\none.png");
            weigt = 0;
        }
        else if (ID == 1) {
            texture.loadFromFile("sprites\\hud\\inventory\\arrowitem.png");
            weigt = 2;
        }
        else if (ID == 2) {
            texture.loadFromFile("sprites\\hud\\inventory\\rokakaitem.png");
            weigt = 1;
        }
        else if (ID == 3) {
            texture.loadFromFile("sprites\\hud\\inventory\\rokakaitem.png");
            weigt = 1;
        }
        else if (ID == 4) {
            texture.loadFromFile("sprites\\hud\\inventory\\FoodPomidori.png");
            weigt = 3;
        }
    }
    void update(sf::Vector2f pos, sf::Vector2f mouspos, Player& pl) {
        sprite.setPosition(pos);
        
        

        if (sprite.getGlobalBounds().contains(mouspos.x, mouspos.y)) {
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                if (ID == 1 && pl.stand == 0) {
                    ID = 0;
                    pl.stand = rand() % 6 + 1;

                    // ѕровер€ем, совпадает ли новое число со старым значением
                    while (pl.stand == pl.old_stand) {
                        // ≈сли да, то генерируем новое случайное число
                        pl.stand = rand() % 6 + 1;
                    }
                }
                if (ID == 2 && pl.stand != 0) {
                    ID = 0;
                    pl.stand = 0;
                }
                if (ID == 4) {
                    ID = 0;
                    pl.health += 20.f;
                }
            }
        }
        if (sprite.getGlobalBounds().contains(mouspos.x, mouspos.y)) {
            if (sf::Mouse::isButtonPressed(sf::Mouse::Right)) {
                
                    ID = 0;

            
            }
        }
    }

    int getWeight() { return weigt; }
   
    int getID() { return ID; }
    void setID(int id) { ID = id; }
    sf::Sprite getSprite() { return sprite; }
};
class Inventory {
private:
    Item inventoryitems[16];
    sf::Texture texture;
    sf::Sprite sprite;
    bool IsOpen;
    int maxweight;
    int weight;
    sf::Text weighttext;
    sf::Text standtext;
    sf::Text healthtext;
    sf::Text speedtext;
    sf::Text moneytext;
  //  sf::Text maxweighttext;
    sf::Font font;
public:
    Inventory(){
        texture.loadFromFile("sprites\\hud\\inventory\\inventory.png");
        sprite.setTexture(texture);
        IsOpen = false; 
        maxweight = 24;
        weight = 0;
        font.loadFromFile("NjalBold.ttf");
        weighttext.setFont(font);
        weighttext.setCharacterSize(16);
       // maxweighttext.setFont(font);
    //    maxweighttext.setCharacterSize(16);

        standtext.setFont(font);
        standtext.setCharacterSize(16);

        moneytext.setFont(font);
        moneytext.setCharacterSize(16);

        speedtext.setFont(font);
        speedtext.setCharacterSize(16);

        healthtext.setFont(font);
        healthtext.setCharacterSize(16);
        
    }
    bool getOpen() { return IsOpen; }
    void setOpen(bool a) { IsOpen = a; }
   
   

    void update(sf::Vector2f pos, sf::Vector2f pos2, Player& pl, sf::Vector2f mouspos) {
        
        sprite.setPosition(pos2);
        if (IsOpen == true) {
            weighttext.setPosition(sprite.getPosition().x + 380.f, sprite.getPosition().y + 8.f);
            weighttext.setString( std::to_string(weight) + "/" + std::to_string(maxweight));

            //maxweighttext.setPosition(sprite.getPosition().x + 10.f, sprite.getPosition().y + + 5.f);
           // maxweighttext.setString("Max Weight: " + std::to_string(maxweight));

            standtext.setPosition(sprite.getPosition().x + 50.f, sprite.getPosition().y + 300.f);

            speedtext.setPosition(sprite.getPosition().x + 50.f, sprite.getPosition().y + 340.f);
            speedtext.setString("SPEED: " + std::to_string((int)(pl.speed * 10.f)));

            moneytext.setPosition(sprite.getPosition().x + 50.f, sprite.getPosition().y + 360.f);
            moneytext.setString("Money: " + std::to_string(pl.money) + "$");

            healthtext.setPosition(sprite.getPosition().x + 50.f, sprite.getPosition().y + 320.f);
            healthtext.setString("HEALTH: " + std::to_string((int)pl.health) + "/" + std::to_string((int)pl.maxhealth));
            if (pl.stand == 0) {
                standtext.setString("STAND: NONE");
            }
            else if (pl.stand == 1) {
                standtext.setString("STAND: The World");
            }
            else if (pl.stand == 2) {
                standtext.setString("STAND: Mandom");
            }
            else if (pl.stand == 3) {
                standtext.setString("STAND: Weather Report");
            }
            else if (pl.stand == 4) {
                standtext.setString("STAND: Hierophant Green");
            }
            else  if (pl.stand == 5) {
                standtext.setString("STAND: Soft And Wet");
            }
            else  if (pl.stand == 6) {
                standtext.setString("STAND: D4C");
            }
            if (D4CDimension == false) {
                for (int i = 0; i < 16; i++) {
                    if (i == 0) {
                        inventoryitems[i].update(pos, mouspos, pl);
                    }
                    else if (i < 4) {
                        inventoryitems[i].update({ inventoryitems[i - 1].getSprite().getPosition().x + inventoryitems[i - 1].getSprite().getGlobalBounds().width + 27.f, pos.y }, mouspos, pl);

                    }
                    else if (i == 4) {
                        inventoryitems[i].update({ pos.x,pos.y + inventoryitems[i].getSprite().getGlobalBounds().height + 24.f }, mouspos, pl);
                    }
                    else if (i < 8) {
                        inventoryitems[i].update({ inventoryitems[i - 1].getSprite().getPosition().x + inventoryitems[i - 1].getSprite().getGlobalBounds().width + 27.f, inventoryitems[i - 1].getSprite().getPosition().y }, mouspos, pl);

                    }
                    else if (i == 8) {
                        inventoryitems[i].update({ pos.x,inventoryitems[i - 1].getSprite().getPosition().y + inventoryitems[i].getSprite().getGlobalBounds().height + 21.f }, mouspos, pl);
                    }
                    else if (i < 12) {
                        inventoryitems[i].update({ inventoryitems[i - 1].getSprite().getPosition().x + inventoryitems[i - 1].getSprite().getGlobalBounds().width + 27.f, inventoryitems[i - 1].getSprite().getPosition().y }, mouspos, pl);

                    }
                    else if (i == 12) {
                        inventoryitems[i].update({ pos.x,inventoryitems[i - 1].getSprite().getPosition().y + inventoryitems[i].getSprite().getGlobalBounds().height + 24.f }, mouspos, pl);
                    }
                    else if (i < 16) {
                        inventoryitems[i].update({ inventoryitems[i - 1].getSprite().getPosition().x + inventoryitems[i - 1].getSprite().getGlobalBounds().width + 27.f, inventoryitems[i - 1].getSprite().getPosition().y }, mouspos, pl);

                    }

                }
            }
        }
        for (int i = 0; i < 16; i++) {

            inventoryitems[i].updatedva();
        }
        weight = 0;
        for (int i = 0; i < 16; i++) {
         
            weight += inventoryitems[i].getWeight();
        }

    }
    int getWeightID(int id) {
        if (id == 0) {
            return 0;
        }
        if (id == 1) {
            return 2;
        }
        if (id == 2) {
            return 1;
        }
        if (id == 3) {
            return 1;
        }
        if (id == 4) {
            return 3;
        }
    }

    void addItem(int ID) {
        
        if (getWeightID(ID) + weight <= maxweight) {
            for (int i = 0; i < 16; i++) {
                if (inventoryitems[i].getID() == 0) {
                    inventoryitems[i].setID(ID);
                    break;
                }
            }
        }
    }
    void draw(sf::RenderWindow& window) {
        if (IsOpen == true) {
            window.draw(sprite);
            //window.draw(maxweighttext);
            window.draw(moneytext);
            window.draw(standtext);
            window.draw(speedtext);
            window.draw(healthtext);
            window.draw(weighttext);
            for (int i = 0; i < 16; i++) {
                window.draw(inventoryitems[i].getSprite());
            }
        }
       
    }
    
};





void MandomClock(sf::Clock& MandomTime, HUD& MandomClockHUD) {
    if (MandomTime.getElapsedTime().asSeconds() > 0.f && MandomTime.getElapsedTime().asSeconds() < 1.f) {
        MandomClockHUD.texture.loadFromFile("sprites\\hud\\MandomClock1.png");
    }
    else if (MandomTime.getElapsedTime().asSeconds() > 1.f && MandomTime.getElapsedTime().asSeconds() < 2.f) {
        MandomClockHUD.texture.loadFromFile("sprites\\hud\\MandomClock2.png");
    }
    else if (MandomTime.getElapsedTime().asSeconds() > 2.f && MandomTime.getElapsedTime().asSeconds() < 3.f) {
        MandomClockHUD.texture.loadFromFile("sprites\\hud\\MandomClock3.png");
    }
    else if (MandomTime.getElapsedTime().asSeconds() > 3.f && MandomTime.getElapsedTime().asSeconds() < 4.f) {
        MandomClockHUD.texture.loadFromFile("sprites\\hud\\MandomClock4.png");
    }
    else if (MandomTime.getElapsedTime().asSeconds() > 4.f && MandomTime.getElapsedTime().asSeconds() < 5.f) {
        MandomClockHUD.texture.loadFromFile("sprites\\hud\\MandomClock5.png");
    }
    else if (MandomTime.getElapsedTime().asSeconds() > 5.f && MandomTime.getElapsedTime().asSeconds() < 6.f) {
        MandomClockHUD.texture.loadFromFile("sprites\\hud\\MandomClock6.png");
    }
}