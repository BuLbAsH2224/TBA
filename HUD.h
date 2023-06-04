#pragma once
#include "settings.h"
#include "FIGHTS.h"













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
       //5 - heart
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
            texture.loadFromFile("sprites\\hud\\inventory\\DioDiary.png");
            weigt = 1;
        }
        else if (ID == 4) {
            texture.loadFromFile("sprites\\hud\\inventory\\FoodPomidori.png");
            weigt = 3;
        }
        else if (ID == 5) {
            texture.loadFromFile("sprites\\hud\\inventory\\HeartOfTheSaintsCorpse.png");
            weigt = 5;
        }
        else if (ID == 6) {
            texture.loadFromFile("sprites\\hud\\inventory\\RibCageOfTheSaintsCorpse.png");
            weigt = 5;
        }
        else if (ID == 7) {
            texture.loadFromFile("sprites\\hud\\inventory\\LegsOfTheSaintsCorpse.png");
            weigt = 5;
        }
        else if (ID == 8) {
            texture.loadFromFile("sprites\\hud\\inventory\\SteelBall.png");
            weigt = 4;
        }
    }
    void update(sf::Vector2f pos, sf::Vector2f mouspos, Player& pl) {
        sprite.setPosition(pos);
        
        

        /*  if (sprite.getGlobalBounds().contains(mouspos.x, mouspos.y)) {
          if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                if (ID == 1 && pl.stand == 0) {
                    ID = 0;
                    pl.stand = rand() % 6 + 1;

                    // Проверяем, совпадает ли новое число со старым значением
                    while (pl.stand == pl.old_stand) {
                        // Если да, то генерируем новое случайное число
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
        }*/
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
    sf::Texture getTexture() { return texture; }
};

class SaintsCorpse {
private:
    sf::Sprite sprite;
    sf::Texture texture;
    bool active;
public:
    SaintsCorpse() {
        active = false;
    }
    void setTexturaAndSprite(sf::String FileName) {
        texture.loadFromFile(FileName);
        sprite.setTexture(texture);
        
    }

    void draw(sf::RenderWindow& window) {
        if (active == true) {
            window.draw(sprite);
        }
    }
    void update(sf::Vector2f pos,sf::Vector2f mouspos) {
        sprite.setPosition(pos);
        if (active == true) {
            if (sprite.getGlobalBounds().contains(mouspos.x, mouspos.y)) {
                if (sf::Mouse::isButtonPressed(sf::Mouse::Right)) {

                    active = false;


                }
            }
        }
    }
    void setActive(bool a) {
        active = a;
    }
    bool getActive() { return active; }
};


class InventoryMenu {
private:
    Item* items;
    SaintsCorpse* corpses;
    sf::Texture InventoryMenuTexture;
    sf::Sprite InventoryMenuSprite;

    sf::Texture EquipButtonTexture;
    sf::Sprite EquipButtonSprite;
    sf::Text EquipText;
    sf::Text WeightText;
    bool EquipIsOn;

    sf::Texture CloseButtonTexture;
    sf::Sprite  CloseButtonSprite;
    sf::Texture UseButtonTexture;
    sf::Sprite  UseButtonSprite;
    sf::Texture DeleteButtonTexture;
    sf::Sprite  DeleteButtonSprite;
    sf::Sprite ItemSprite;
    sf::Texture ItemTexture;
    sf::Text Description;
    sf::Text NameText;
    sf::Text UseText;
    sf::Text DeleteText;
    sf::Font font;
    bool MenuIsOpen;
    int ItemMenu;
    int ItemMenuID;
public:
    InventoryMenu(Item* lang, SaintsCorpse* corpsesLang) : items(lang), corpses(corpsesLang) {

        InventoryMenuTexture.loadFromFile("sprites\\hud\\inventory\\InventoryMenu.png");
        ItemTexture.loadFromFile("sprites\\hud\\inventory\\none.png");
        ItemSprite.setTexture(ItemTexture);

        EquipButtonTexture.loadFromFile("sprites\\hud\\inventory\\EquipButton.png");
        EquipButtonSprite.setTexture(EquipButtonTexture);

        InventoryMenuSprite.setTexture(InventoryMenuTexture);
        ItemMenu = 0;
        EquipIsOn = false;
        MenuIsOpen = false;
        font.loadFromFile("NjalBold.ttf");
        Description.setFont(font);
        Description.setCharacterSize(16);
        NameText.setFont(font);
        NameText.setCharacterSize(18);
        UseText.setFont(font);
        UseText.setCharacterSize(12);
        DeleteText.setFont(font);
        DeleteText.setCharacterSize(12);
        WeightText.setFont(font);
        WeightText.setCharacterSize(12);
        EquipText.setFont(font);
        EquipText.setCharacterSize(12);

        CloseButtonTexture.loadFromFile("sprites\\hud\\inventory\\CloseButton.png");
        CloseButtonSprite.setTexture(CloseButtonTexture);
        UseButtonTexture.loadFromFile("sprites\\hud\\inventory\\UseButton.png");
        UseButtonSprite.setTexture(UseButtonTexture);
        DeleteButtonTexture.loadFromFile("sprites\\hud\\inventory\\DeleteButton.png");
        DeleteButtonSprite.setTexture(DeleteButtonTexture);
    }
    void setItem(int id) { ItemMenu = id; }
    bool getItem() { return ItemMenu; }
    void setItemID(int id) { ItemMenuID = id; }
    bool getItemID() { return ItemMenuID; }
    void setMenuOpen(bool a) { MenuIsOpen = a; }
    bool getMenuOpen() { return MenuIsOpen; }
    void draw(sf::RenderWindow& window) {
        window.draw(InventoryMenuSprite);
        window.draw(ItemSprite);
        window.draw(Description);
        window.draw(NameText);
        window.draw(CloseButtonSprite);
        window.draw(DeleteButtonSprite);
        window.draw(UseButtonSprite);
        window.draw(UseText);
        window.draw(DeleteText);
        window.draw(WeightText);
        if (EquipIsOn == true) {
            window.draw(EquipButtonSprite);
            window.draw(EquipText);
        }
    }
    void Descriptions(Languages& language) {
        if (ItemMenuID == 1) {
            if (language.EnglishText == true) {
                Description.setString(L"Mysterious arrow that\ngrants a Stand");
                NameText.setString(L"Arrow");
            }
            else if (language.RussiaText == true) {
                Description.setString(L"Загадочная стрела \nкоторая дает стенд");
                NameText.setString(L"Стрела");
            }
        }
        else if (ItemMenuID == 2) {
            if (language.EnglishText == true) {
                Description.setString(L"Mysterious fruit \nthat removes a Stand");
                NameText.setString(L"Rokaka");
            }
            else if (language.RussiaText == true) {
                Description.setString(L"Загадочный фрукт \nкоторый убирает стенд");
                NameText.setString(L"Рокака");
            }
        }
        else if (ItemMenuID == 3) {
            if (language.EnglishText == true) {
                Description.setString(L"in future updates");
                NameText.setString(L"Dio Diary");
            }
            else if (language.RussiaText == true) {
                Description.setString(L"в будующих обновлениях");
                NameText.setString(L"Дневник Дио");
            }
        }
        else if (ItemMenuID == 4) {
            if (language.EnglishText == true) {
                Description.setString(L"Delicious food \nfrom Tonio, \nrestores 20 \nhealth points");
                NameText.setString(L"Tonio Food");
            }
            else if (language.RussiaText == true) {
                Description.setString(L"Вкусная еда от Тонио, \nвосстанавливает  \n20 жизней");
                NameText.setString(L"Блюдо Тонио");
            }
        }
        else if (ItemMenuID == 5) {
            if (language.EnglishText == true) {
                Description.setString(L"When equipped, \nit increases \nhealth by 50. \nWhen used, changes \nthe stand to D4C");
                NameText.setString(L"Heart OTS Corpse");
            }
            else if (language.RussiaText == true) {
                Description.setString(L"При экипирировании \nувеличивает \nздоровье на 50. \nПри применении \nменяет стенд на D4C");
                NameText.setString(L"Сердце СТ");
            }
        }
        else if (ItemMenuID == 6) {
            if (language.EnglishText == true) {
                Description.setString(L"When equipped, \nit increases the \nmaximum weight \nof the backpack by 10");
                NameText.setString(L"RibCage OTS Corpse");
            }
            else if (language.RussiaText == true) {
                Description.setString(L"При экипирировании \nувеличивает \nмаксимальный вес \nрюказака на 10");
                NameText.setString(L"Ребро СТ");
            }
        }
        else if (ItemMenuID == 7) {
            if (language.EnglishText == true) {
                Description.setString(L"When equipped, \nit increases \nspeed by 1");
                NameText.setString(L"Legs OTS Corpse");
            }
            else if (language.RussiaText == true) {
                Description.setString(L"При экипирировании \nувеличивает \nскорость на 1");
                NameText.setString(L"Ноги СТ");
            }
        }
        else if (ItemMenuID == 8) {
            if (language.EnglishText == true) {
                Description.setString(L"When equipped, \nit increases \nspeed by 1");
                NameText.setString(L"Steel Ball");
            }
            else if (language.RussiaText == true) {
                Description.setString(L"РАСКУМАРЬТЕСЬ АБАЛДУИ \nувеличивает \nскорость на 1");
                NameText.setString(L"Стальной шар");
            }
        }
        else {
            Description.setString(L"???");
            NameText.setString(L"???");
        }
    }
    void ItemActions(Player& pl) {

        if (ItemMenuID == 1 && pl.stand == 0) {

            pl.stand = rand() % 8 + 1;
            OffPowers();
          
            while (pl.stand == pl.old_stand || pl.stand == 6) {
         
                pl.stand = rand() % 6 + 1;
            }
            items[ItemMenu].setID(0);
        }

        else if (ItemMenuID == 2 && pl.stand != 0) {
            OffPowers();
            pl.stand = 0;
            items[ItemMenu].setID(0);
        }

        else if (ItemMenuID == 4) {

            pl.health += 20.f;
            items[ItemMenu].setID(0);
        }
        if (ItemMenuID == 5 && pl.stand != 6 && pl.stand == 0) {
            pl.stand = 6;
            OffPowers();
            items[ItemMenu].setID(0);
        }
        else if (ItemMenuID == 8) {
            pl.FightTech = 1;
            items[ItemMenu].setID(0);
        }
    }

    void ItemEquipActions() {
          if (ItemMenuID == 5 && corpses[1].getActive() == false) {
            corpses[1].setActive(true);
            items[ItemMenu].setID(0);
        }
        else if (ItemMenuID == 6 && corpses[0].getActive() == false) {
            corpses[0].setActive(true);
            items[ItemMenu].setID(0);
        }
        else if (ItemMenuID == 7 && corpses[2].getActive() == false) {
            corpses[2].setActive(true);
            items[ItemMenu].setID(0);
        }
      
    }


    void update(sf::Vector2f pos, Languages& language, sf::Vector2f mouspos, Player& pl) {
        InventoryMenuSprite.setPosition(pos);
        UseButtonSprite.setPosition({ InventoryMenuSprite.getPosition().x + 7.f , InventoryMenuSprite.getPosition().y + 325.f });
        if (language.EnglishText == true) {
            UseText.setString(L"Use");
            DeleteText.setString(L"Delete");
            EquipText.setString(L"Equip");
            WeightText.setString(L"Weight: " + std::to_wstring(items[ItemMenu].getWeight()));
        }
        else if (language.RussiaText == true) {
            UseText.setString(L"Применить");
            DeleteText.setString(L"Удалить");
            EquipText.setString(L"Снарядить");
            WeightText.setString(L"Вес: " + std::to_wstring(items[ItemMenu].getWeight()));
        }
        DeleteButtonSprite.setPosition({ InventoryMenuSprite.getPosition().x + InventoryMenuSprite.getGlobalBounds().width - 7.f - DeleteButtonSprite.getGlobalBounds().width, InventoryMenuSprite.getPosition().y + 325.f });
        ItemSprite.setPosition({ InventoryMenuSprite.getPosition().x + 85.f, InventoryMenuSprite.getPosition().y + 102.f });
        UseText.setPosition({ UseButtonSprite.getPosition().x + 5.f,UseButtonSprite.getPosition().y + 2.f });
        DeleteText.setPosition({ DeleteButtonSprite.getPosition().x + 5.f,DeleteButtonSprite.getPosition().y + 2.f });
        Description.setPosition({ InventoryMenuSprite.getPosition().x + 10.f, InventoryMenuSprite.getPosition().y + 140.f });
        EquipButtonSprite.setPosition({ InventoryMenuSprite.getPosition().x + 66.f, InventoryMenuSprite.getPosition().y + 298.f });
        EquipText.setPosition({ EquipButtonSprite.getPosition().x + 5.f,EquipButtonSprite.getPosition().y + 2.f });
        NameText.setPosition({ InventoryMenuSprite.getPosition().x + 10.f , InventoryMenuSprite.getPosition().y + 50.f });
        CloseButtonSprite.setPosition({ InventoryMenuSprite.getPosition().x + 179.f , InventoryMenuSprite.getPosition().y - 12.f });
        WeightText.setPosition({ InventoryMenuSprite.getPosition().x + 10.f , InventoryMenuSprite.getPosition().y + 10.f });
        if (items[ItemMenu].getID() == 0) {
            MenuIsOpen = false;
        }
        if (MenuIsOpen == true) {
            if (ItemMenuID == 5 || ItemMenuID == 6 || ItemMenuID == 7) {
                EquipIsOn = true;
           }
            else {
                EquipIsOn = false;
            }
            if (CloseButtonSprite.getGlobalBounds().contains(mouspos.x, mouspos.y)) {
                if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                    MenuIsOpen = false;
                 }
            }
            else  if (DeleteButtonSprite.getGlobalBounds().contains(mouspos.x, mouspos.y)) {
                if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                    items[ItemMenu].setID(0);
                    MenuIsOpen = false;
                }
            }
            else if (EquipIsOn == true && EquipButtonSprite.getGlobalBounds().contains(mouspos.x, mouspos.y)) {
                if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                   
                    MenuIsOpen = false;
                    ItemEquipActions();
                }
            }
            else if (UseButtonSprite.getGlobalBounds().contains(mouspos.x, mouspos.y)) {
                if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                  
                    MenuIsOpen = false;
                    ItemActions(pl);
                }
            }
            if (ItemMenu >= 0 && ItemMenu < 16 && ItemMenuID != 0) {
                ItemTexture = items[ItemMenu].getTexture();
                Descriptions(language);
                
            }
        }
    }
};




class FightTechPreview {
private:
    sf::Sprite sprite;
    sf::Texture texture;
    int tech;
public:
    FightTechPreview() {
        texture.loadFromFile("sprites\\hud\\inventory\\SteelBall.png");
        sprite.setTexture(texture);
        tech = 0;
    }
    void update(sf::Vector2f SetPos,Player& pl, sf::Vector2f mouspos) {
        sprite.setPosition(SetPos);
        tech = pl.FightTech;
        if (pl.FightTech == 1) {
            texture.loadFromFile("sprites\\hud\\inventory\\SteelBall.png");
        }
        if (sprite.getGlobalBounds().contains(mouspos.x, mouspos.y)) {
            if (sf::Mouse::isButtonPressed(sf::Mouse::Right) && pl.FightTech != 0) {
                pl.FightTech = 0;
            }
        }
    }
    void draw(sf::RenderWindow& window){
        if (tech != 0) {
            window.draw(sprite);
        }
}
};
class Inventory {
private:
    Item inventoryitems[16];
    sf::Texture texture;
    sf::Sprite sprite;
 

    bool IsOpen;
    int maxweight;
    int weight;
    InventoryMenu Menu;
    FightTechPreview tech;
    sf::Text weighttext;
    sf::Text standtext;
    sf::Text healthtext;
    sf::Text speedtext;
    sf::Text moneytext;
    sf::Text FightTechtext;
  //  sf::Text maxweighttext;
    sf::Font font;
    SaintsCorpse saintscorpes[9];
  
public:
    Inventory() : Menu(inventoryitems,saintscorpes) {
        texture.loadFromFile("sprites\\hud\\inventory\\inventory.png");
        sprite.setTexture(texture);
        
        IsOpen = false; 
        maxweight = 24;
        weight = 0;
        font.loadFromFile("NjalBold.ttf");
        weighttext.setFont(font);
        weighttext.setCharacterSize(16);
        saintscorpes[2].setTexturaAndSprite("sprites\\hud\\inventory\\LegsOfTheSaintsCorpse.png");
        saintscorpes[1].setTexturaAndSprite("sprites\\hud\\inventory\\HeartOfTheSaintsCorpse.png");
        saintscorpes[0].setTexturaAndSprite("sprites\\hud\\inventory\\RibCageOfTheSaintsCorpse.png");
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

        FightTechtext.setFont(font);
        FightTechtext.setCharacterSize(16);
        
    }
    bool getOpen() { return IsOpen; }
    void setOpen(bool a) { IsOpen = a; }
   
   

    void update(sf::Vector2f pos, sf::Vector2f pos2, Player& pl, sf::Vector2f mouspos, Languages& language) {
        if (saintscorpes[2].getActive() == true) {
            pl.speed = 0.3;
        }
        else {
            pl.speed = 0.2;
        }
        if (saintscorpes[1].getActive() == true) {
            pl.maxhealth = 250.f;
        }
        else {
            pl.maxhealth = 200.f;
        }
        if (saintscorpes[0].getActive() == true) {
            maxweight = 34;
        }
        else {
            maxweight = 24;
        }
        sprite.setPosition(pos2);
        if (IsOpen == true) {
            tech.update({ sprite.getPosition().x + 177.f, sprite.getPosition().y + 240.f }, pl, mouspos);
            saintscorpes[2].update({ sprite.getPosition().x + 9.f, sprite.getPosition().y + 190.f }, mouspos);
            saintscorpes[1].update({ sprite.getPosition().x + 9.f, sprite.getPosition().y + 139.f },mouspos);
            saintscorpes[0].update({ sprite.getPosition().x + 177.f, sprite.getPosition().y + 139.f }, mouspos);
            Menu.update({ sprite.getPosition().x + sprite.getGlobalBounds().width, sprite.getPosition().y },language,mouspos,pl);







            
            weighttext.setPosition(sprite.getPosition().x + 380.f, sprite.getPosition().y + 8.f);
            weighttext.setString( std::to_string(weight) + "/" + std::to_string(maxweight));

            //maxweighttext.setPosition(sprite.getPosition().x + 10.f, sprite.getPosition().y + + 5.f);
           // maxweighttext.setString("Max Weight: " + std::to_string(maxweight));

            standtext.setPosition(sprite.getPosition().x + 50.f, sprite.getPosition().y + 300.f);

            speedtext.setPosition(sprite.getPosition().x + 50.f, sprite.getPosition().y + 340.f);
            if (language.EnglishText == true) {
                speedtext.setString("SPEED: " + std::to_string((int)(pl.speed * 10.f)));
            }
            else if (language.RussiaText == true) {
                speedtext.setString(L"СКОРОСТЬ: " + std::to_wstring((int)(pl.speed * 10.f)));

            }
            

            moneytext.setPosition(sprite.getPosition().x + 50.f, sprite.getPosition().y + 360.f);
            if (language.EnglishText == true) {
                moneytext.setString("MONEY: " + std::to_string(pl.money) + "$");
            }
            else if (language.RussiaText == true) {
                moneytext.setString(L"ДЕНЬГИ: " + std::to_wstring(pl.money) + L"$");

            }
           

            healthtext.setPosition(sprite.getPosition().x + 50.f, sprite.getPosition().y + 320.f);
            if (language.EnglishText == true) {
                healthtext.setString("HEALTH: " + std::to_string((int)pl.health) + "/" + std::to_string((int)pl.maxhealth));
            }
            else if (language.RussiaText == true) {
                healthtext.setString(L"ЗДОРОВЬЕ: " + std::to_wstring((int)pl.health) + L"/" + std::to_wstring((int)pl.maxhealth));

            }
                FightTechtext.setPosition(sprite.getPosition().x + 50.f, sprite.getPosition().y + 380.f);
            if (language.EnglishText == true) {
                if (pl.FightTech == 0) {
                    FightTechtext.setString("FIGHTING TECHNIQUE: NONE");
                }
                else if (pl.FightTech == 1) {
                    FightTechtext.setString("Fighting Technique: Steel Ball" );
                }
                else  {
                    FightTechtext.setString("Fighting Technique: ???");
                }
            }
            else if (language.RussiaText == true) {
                if (pl.FightTech == 0) {
                    FightTechtext.setString(L"Техника Боя: Нету");
                }
                else if (pl.FightTech == 1) {
                    FightTechtext.setString(L"Техника Боя: Стальной Шар");
                }
                else {
                    FightTechtext.setString(L"Техника Боя: ???");
                }
            }

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
            else  if (pl.stand == 7) {
                standtext.setString("STAND: Aerosmith");
            }
            else  if (pl.stand == 8) {
                standtext.setString("STAND: Killer Queen");
            }
            else   {
                standtext.setString("STAND: ???");
            }
            if (D4CDimension == false) {
                for (int i = 0; i < 16; i++) {
                    if (inventoryitems[i].getSprite().getGlobalBounds().contains(mouspos.x, mouspos.y)) {
                        if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && inventoryitems[i].getID() != 0) {
                            Menu.setItem(i);
                            Menu.setItemID(inventoryitems[i].getID());
                            Menu.setMenuOpen(true);
                        }
                    }
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
        else if (id == 1) {
            return 2;
        }
        else if (id == 2) {
            return 1;
        }
        else if (id == 3) {
            return 1;
        }
       
        else if (id == 4) {
            return 3;
        }
        else if (id == 5) {
            return 4;
        }
        else if (id == 6) {
            return 5;
        }
        else if (id == 7) {
            return 5;
        }
        else if (id == 8) {
            return 4;
        }
        else {
            return 0;
        }
    }
    bool ItemCanBeAdded(int ID) {
        if (getWeightID(ID) + weight <= maxweight) {
            for (int i = 0; i < 16; i++) {
                if (inventoryitems[i].getID() == 0) {
                  
                    return true; 
                }
            }
        }
        return false; 
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
            for (int i = 0; i < 9; i++) {
                saintscorpes[i].draw(window);
            }
            
            //window.draw(maxweighttext);
            if (Menu.getMenuOpen() == true) {
                Menu.draw(window);
            }
            tech.draw(window);
            window.draw(moneytext);
            window.draw(standtext);
            window.draw(speedtext);
            window.draw(healthtext);
            window.draw(weighttext);
            window.draw(FightTechtext);
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

class Notifications {
private:
    sf::Font font;
    sf::Text Text;
    sf::Clock die;
    float elapsed_time;
    int alpha;
public:
    Notifications(std::wstring  Notification) {
        font.loadFromFile("NjalBold.ttf");
        Text.setFont(font);  
        Text.setCharacterSize(32);
        Text.setString(Notification);
    } 
    void update(sf::Vector2f pos, float gap) {
        Text.setPosition({ pos.x, pos.y + gap });

         elapsed_time = die.getElapsedTime().asSeconds();
         if (elapsed_time < 1.f) { // если анимация еще не завершена
             int alpha = static_cast<int>(elapsed_time / 1.f * 255); // вычисляем значение альфа-канала
             sf::Color color = Text.getFillColor();
             color.a = static_cast<sf::Uint8>(alpha);
             Text.setFillColor(color);
         }
         else {
             if (elapsed_time > 5.f) {
                 alpha = static_cast<int>((1.f - elapsed_time / 8.f) * 255);
                 if (alpha < 0) alpha = 0; // ограничить минимальное значение альфа-канала
                 sf::Color color = Text.getFillColor();
                 color.a = static_cast<sf::Uint8>(alpha);
                 Text.setFillColor(color);
               
             }
         }
    } 
    void draw(sf::RenderWindow& window) {
        window.draw(Text);
    }
    bool getDie() { return die.getElapsedTime().asSeconds() >= 10.f; }
};

void NotificationsDie(Notifications& las, std::list<Notifications*>& lasers) {
    for (auto it = lasers.begin(); it != lasers.end(); /* без ++it здесь */) {
        if ((*it)->getDie() == true) {

            it = lasers.erase(it);
        }
        else {
            ++it;
        }
    }


}

/*class Quests {
private:
    sf::Sprite sprite;
    sf::Texture texture;
public:

};*/

class ItemsForShop {
private:
    sf::Sprite sprite;
    sf::Texture texture;
    sf::Sprite Backgroundsprite;
    sf::Texture Backgroundtexture;
    int ID;
    int price;
    sf::Text text;
    sf::Font font;
public:
    ItemsForShop() {
        font.loadFromFile("NjalBold.ttf");
        text.setFont(font);
        text.setCharacterSize(16);
        text.setString(L"");
       
        texture.loadFromFile("sprites\\hud\\inventory\\none.png");
        sprite.setTexture(texture);
        Backgroundtexture.loadFromFile("sprites\\hud\\inventory\\ItemBackground.png");
        Backgroundsprite.setTexture(Backgroundtexture);
        ID = 0;
        price = 0;
    }
    void setID(int id) { ID = id; }
    void update(sf::Vector2f pos, Languages& language) {
        sprite.setPosition(pos);
        Backgroundsprite.setPosition(pos);
        text.setPosition({ sprite.getPosition().x - 30.f, sprite.getPosition().y - 60.f  });
        if (language.EnglishText == true) {
            text.setString(L"Price: " + std::to_wstring(price) + L"$");
        }
        else if (language.RussiaText == true) {
            text.setString(L"Цена: " + std::to_wstring(price) + L"$");
            
        }
        if (ID == 1) {
            price = 2000;
            texture.loadFromFile("sprites\\hud\\inventory\\HeartOfTheSaintsCorpse.png");
        }
      
            if (ID == 2) {
                price = 4000;
                texture.loadFromFile("sprites\\hud\\inventory\\RibCageOfTheSaintsCorpse.png");
            }
            if (ID == 3) {
                price = 500;
                texture.loadFromFile("sprites\\hud\\inventory\\FoodPomidori.png");
            }
    }
    void draw(sf::RenderWindow& window) {
        if (ID != 0) {
            window.draw(Backgroundsprite);
            window.draw(sprite);
            window.draw(text);
        }
    }
    int getID() { return ID; }
    int getPrice() { return price; }
    sf::FloatRect getHitbox() { return sprite.getGlobalBounds(); }
    sf::Sprite getSprite() { return sprite; }
};

class Shops {
private:
    sf::Sprite backgroundsprite;
    sf::Texture backgroundtexture;
    sf::Sprite backbuttonsprite;
    sf::Texture backbuttontexture;
    bool MenuIsOpen;
    ItemsForShop item[3];
    sf::Text MoneyText;
    sf::Font font;

public:
    Shops() {
        backgroundtexture.loadFromFile("sprites\\hud\\ShopTutorial.png");
        backgroundsprite.setTexture(backgroundtexture);
        font.loadFromFile("NjalBold.ttf");
        MoneyText.setFont(font);
        MoneyText.setCharacterSize(64);
        MoneyText.setString(L"");
        MoneyText.setPosition({ 0.f,100.f });
        backbuttontexture.loadFromFile("sprites\\hud\\FightBackButton.png");
        MenuIsOpen = false;
        backbuttonsprite.setTexture(backbuttontexture);
        backbuttonsprite.setPosition({ 1280.f - backbuttonsprite.getGlobalBounds().width, backbuttonsprite.getGlobalBounds().height });
    }
    bool getOpen() { return MenuIsOpen; }
    void setOpen(bool a) { MenuIsOpen = a; }
    void SetShopItems(int id1, int id2, int id3) {
        item[0].setID(id1);
        item[1].setID(id2);
        item[2].setID(id3);

    }
     void update(Languages& language, sf::Vector2f mouspos, Player& pl) {
         if (language.EnglishText == true) {
             MoneyText.setString(L"Money: " + std::to_wstring(pl.money) + L"$");
         }
         else if (language.RussiaText == true) {
             MoneyText.setString(L"Денег: " + std::to_wstring(pl.money) + L"$");

         }
         for (int i = 0; i < 3; i++) {
             if (i == 0) {
                 item[i].update({500.f,1080.f / 2.f - 100.f }, language);
             }
             else {
                 item[i].update({ item[i - 1].getSprite().getPosition().x + 200.f, item[i - 1].getSprite().getPosition().y}, language);
             }
         }
         if (backbuttonsprite.getGlobalBounds().contains(mouspos.x, mouspos.y)) {
            
             backbuttontexture.loadFromFile("sprites\\hud\\FightBackButtonContour.png");
             if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                 MenuIsOpen = false;
             }
         }
         else{ backbuttontexture.loadFromFile("sprites\\hud\\FightBackButton.png"); }
         
     }
     void updatedva(Inventory& inv, Player& pl, sf::Vector2f mouspos) {
         for (int i = 0; i < 3; i++) {
             if (item[i].getHitbox().contains(mouspos.x, mouspos.y) && item[i].getID() != 0) {
                 if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                     if (item[i].getID() == 2) {
                         if (inv.ItemCanBeAdded(6) && pl.money >= item[i].getPrice()) {
                             inv.addItem(6);
                             pl.money -= item[i].getPrice();
                         }
                     }
                     else  if (item[i].getID() == 1) {
                         if (inv.ItemCanBeAdded(5) && pl.money >= item[i].getPrice()) {
                             inv.addItem(5);
                             pl.money -= item[i].getPrice();
                         }
                     }
                     else  if (item[i].getID() == 3) {
                         if (inv.ItemCanBeAdded(4) && pl.money >= item[i].getPrice()) {
                             inv.addItem(4);
                             pl.money -= item[i].getPrice();
                         }
                     }
                 }
             }
         }
     }
    void draw(sf::RenderWindow& window) {
        window.draw(backgroundsprite);
        window.draw(backbuttonsprite);
        for (int i = 0; i < 3; i++) {
            item[i].draw(window);
        }
        window.draw(MoneyText);
    }
};