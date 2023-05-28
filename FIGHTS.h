#pragma once
#include "settings.h"
std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> converter;
struct Languages {
    bool RussiaText = false;
    bool EnglishText = false;
};

void PlayerUpdateInFight(Player& obj, std::string LeftSpriteFileNAME, std::string RightSpriteMOVEFileNAME, std::string LeftSpriteMoveFileNAME, std::string RightSpriteFileNAME, Stand& stands, float time) {
    if (obj.health > obj.maxhealth) {
        obj.health = obj.maxhealth;
    }
    if (obj.stoi == false) {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && obj.sprite.getPosition().x <= 1920.f - obj.sprite.getGlobalBounds().width) {
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
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && obj.sprite.getPosition().x >= 0.f) {
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
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::T) && AttackTm.getElapsedTime().asSeconds() > 3 && obj.attacking == false) {
            AttackTm.restart();
            obj.attacking = true;
        }
    }

}

class FightBackButton {
private:
    sf::Sprite sprite;
    sf::Texture texture;
    sf::Clock valid;
    bool close;
public:
    FightBackButton() {
        texture.loadFromFile("sprites\\hud\\FightBackButton.png");
        sprite.setTexture(texture);
        close = false;
    }
    void update(sf::Vector2f pos,sf::Vector2f mouspos) {
        sprite.setPosition(pos);
       
            if (sprite.getGlobalBounds().contains(mouspos.x, mouspos.y)) {
                texture.loadFromFile("sprites\\hud\\FightBackButtonContour.png");
                if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                    close = true;
                }
            }
            else if (valid.getElapsedTime().asSeconds() <= 10.f){
                texture.loadFromFile("sprites\\hud\\FightBackButton.png");
            }
            else  {
                texture.loadFromFile("sprites\\hud\\FightSurrenderButton.png");
            }
    
    }
    void draw(sf::RenderWindow& window) {
       
        window.draw(sprite);
    }
    bool getClose() { return close; }
    void setClose(bool a) { close = a; }
    void restartClock() {   valid.restart();}
    bool getValidSur() { return valid.getElapsedTime().asSeconds() <= 10.f; }
    sf::Sprite getSprite() { return sprite; }
};



class Fights {
private:
    sf::Texture menutexture;
    sf::Sprite menu;
    sf::Texture Accepttexture;
    sf::Sprite Acceptbutton;
    sf::Texture Icontexture;
    sf::Sprite Icon;
    sf::Texture Rejecttexture;
    sf::Sprite Rejectbutton;
    bool IsOpen;
    Vragi* VragBitv;
    sf::Text textvizova;
    sf::Text Accepttext;
    sf::Text RewardText;
    sf::Text Rejecttext;
    sf::Font font;
    bool InFight;
    sf::Vector2f Pos;
public:
    Fights() {
       
        menutexture.loadFromFile("sprites\\hud\\FightMenu.png");
        Accepttexture.loadFromFile("sprites\\hud\\AcceptButton.png");
        Acceptbutton.setTexture(Accepttexture);
        Rejecttexture.loadFromFile("sprites\\hud\\RejectButton.png");
        Rejectbutton.setTexture(Rejecttexture);
        Icontexture.loadFromFile("sprites\\NPC\\icons\\PlohoiParenIcon.png");
        Icon.setTexture(Icontexture);
        menu.setTexture(menutexture);
        font.loadFromFile("NjalBold.ttf");
        textvizova.setFont(font);
        textvizova.setCharacterSize(16);

        RewardText.setFont(font);
        RewardText.setCharacterSize(24);


        Accepttext.setFont(font);
        Accepttext.setCharacterSize(24);
        Rejecttext.setFont(font);
        Rejecttext.setCharacterSize(24);
        InFight = false;
       
        IsOpen = false; //false
       
    }

    void OpenMenu(Vragi& vrag) {
        if (IsOpen == false) {
            VragBitv = &vrag;
            IsOpen = true;
        }
    }
    sf::Vector2f getPos() { return Pos; }
    bool getOpen() { return IsOpen; }
    bool getFight() { return InFight; } 
    void setFight(bool a) { InFight = a; }
    auto getVrag() { return VragBitv; }
    auto setVrag(Vragi& vrag) { VragBitv = &vrag; }
    void update( sf::Vector2f pos, sf::Vector2f mouspos, Player& pl, Stand& stpl, Stand& vragpl, sf::Vector2f plpos, Languages& language) {
     
        if (IsOpen == true) {
            if (language.EnglishText == true) {
                Accepttext.setString("Accept");
            }
            else if (language.RussiaText == true) {
                Accepttext.setString(L" Принять");

            }
            if (language.EnglishText == true) {

                Rejecttext.setString("Reject");
            }
            else if (language.RussiaText == true) {

                Rejecttext.setString(L"Отказ");

            }
          
            if (VragBitv->Name == "Bad Guy") {
                Icontexture.loadFromFile("sprites\\NPC\\icons\\PlohoiParenIcon.png");
            }
            if (language.EnglishText == true) {
                RewardText.setString("Reward: " + std::to_string(VragBitv->Reward) + "$");
           }
            else if (language.RussiaText == true) {
                RewardText.setString(L"Награда: " + std::to_wstring(VragBitv->Reward) + L"$");
            
            }
            menu.setPosition(pos);
            Icon.setPosition({ menu.getPosition().x + 156.f, menu.getPosition().y + 155.f });
            textvizova.setPosition({ menu.getPosition().x + 90.f, menu.getPosition().y + 300.f });
            if (language.EnglishText == true) {
                textvizova.setString(VragBitv->Name + " wants to fight you,\naccept?");
            }
            else if (language.RussiaText == true) {
                textvizova.setString(converter.from_bytes(VragBitv->Name) + L" хочет сразиться с тобой,\nпринять?");

            }
            
            RewardText.setPosition({ Icon.getPosition().x - 30.f, Icon.getPosition().y - 30.f });
            Acceptbutton.setPosition({ menu.getPosition().x + 10.f, menu.getPosition().y + menu.getGlobalBounds().height - 100.f });
            Rejectbutton.setPosition({ menu.getPosition().x + menu.getGlobalBounds().width - Rejectbutton.getGlobalBounds().width - 10.f, menu.getPosition().y + menu.getGlobalBounds().height - 100.f });
            Accepttext.setPosition({ Acceptbutton.getPosition().x + 30.f, Acceptbutton.getPosition().y + 5.f });
           Rejecttext.setPosition({ Rejectbutton.getPosition().x + 30.f,Rejectbutton.getPosition().y + 5.f });
            if (Rejectbutton.getGlobalBounds().contains(mouspos.x, mouspos.y)) {
                if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                    IsOpen = false;
                    pl.stoi = false;
                }
            }
            if (Acceptbutton.getGlobalBounds().contains(mouspos.x, mouspos.y)) {
                if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                    IsOpen = false;
                    InFight = true;
                    pl.stoi = false;
                    VragBitv->health = 100.f;
                    pl.sprite.setPosition({ 900.f,840.f - pl.sprite.getGlobalBounds().height });
                    stpl.visible = false;
                    VragBitv->sprite.setPosition({ 1300.f,840.f - VragBitv->sprite.getGlobalBounds().height });
                    vragpl.sprite.setPosition({ VragBitv->sprite.getPosition() });
                    Pos = plpos;
                    
                }
            }
        }
    }
   

    void draw(sf::RenderWindow& window) {
        if (IsOpen == true) {
            window.draw(menu);
            window.draw(Icon);
            window.draw(Acceptbutton);
            window.draw(Rejectbutton);
            window.draw(Accepttext);
            window.draw(Rejecttext);
            window.draw(RewardText);
            window.draw(textvizova);
        }
    }
};