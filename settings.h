#pragma once



#include <iostream>
#include <sstream>
#include <fstream>
#include <list>

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <windows.h>
#include <locale>
#include <codecvt>


#include "standIplayer.h"
#include "map.h"

#include "Playerpowers.h"
#include "vragi.h"
#include "HUD.h"
#include "NPC.h"
#include "quests.h"
#include "menu.h"
#include "CheckCollisions.h"
#include "FIGHTS.h"
#include "VragPowers.h"

const float WINDOW_X = 1920;
const float WINDOW_Y = 1080;
 float hsh = 0.f;



const std::string GRASS1_FILE_NAME{ "sprites\\map\\grass1.jpg" };

const std::string ARROW_FILE_NAME{ "sprites\\objects\\arrow.png" };
const std::string VERSION_NAME{ "BETA 1.4" };
const std::string PLAYER1LEFT_FILE_NAME{ "sprites\\player\\player1left.png" };
const std::string PLAYER1RIGHT_FILE_NAME{ "sprites\\player\\player1right.png" };

 float PlSpeedX = 0.2f;
 float PlSpeedY = 0.2f;
 

 struct LanguageFlags {
     sf::Texture texture;
     sf::Sprite sprite;
 };

 void LanguageFlagsInit(LanguageFlags& obj,sf::Vector2f pos,std::string filename){
     obj.texture.loadFromFile(filename);
     obj.sprite.setTexture(obj.texture);
     obj.sprite.setPosition(pos);
 }


 class admincheats {

     
 public:
     
     void update(Player& pl) {
         
             if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1) && sf::Keyboard::isKeyPressed(sf::Keyboard::Num3) && sf::Keyboard::isKeyPressed(sf::Keyboard::Num4) && sf::Keyboard::isKeyPressed(sf::Keyboard::Num6)) {
                 
                 pl.money = 100000;
             }
             
         
        
     }
 };
 
 class DayAndNight {
 private:
     sf::Sprite sprite;
     sf::Texture texture;
     sf::Clock clock;
     bool night;
 public:
     DayAndNight() {
         texture.loadFromFile("sprites\\map\\NightOverlay.png");
         sprite.setTexture(texture);
         night = false;
     }
     void update(sf::Vector2f pos) {
         sprite.setPosition(pos);
         if (clock.getElapsedTime().asSeconds() > 180.f && night == false) {
             night = true;
             clock.restart();
         }
         else if (clock.getElapsedTime().asSeconds() > 180.f && night == true) {
             night = false;
             clock.restart();
         }
     }
     bool getNight() { return night; }
     void setNight(bool a) { night = a; }
     void draw(sf::RenderWindow& window) {
         if (night == true) {
             window.draw(sprite);
         }
     }
 };



