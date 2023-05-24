#pragma once



#include <iostream>

#include <fstream>
#include <list>

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <windows.h>
#include <locale>
#include <codecvt>


#include "standIplayer.h"
#include "arrow.h"
#include "map.h"
#include "Playerpowers.h"
#include "vragi.h"
#include "HUD.h"
#include "NPC.h"
#include "quests.h"
#include "menu.h"
#include "CheckCollisions.h"
#include "FIGHTS.h"
const float WINDOW_X = 1920;
const float WINDOW_Y = 1080;
 float hsh = 0.f;



const std::string GRASS1_FILE_NAME{ "sprites\\map\\grass1.jpg" };

const std::string ARROW_FILE_NAME{ "sprites\\objects\\arrow.png" };
const std::string VERSION_NAME{ "alpha 0.9.5" };
const std::string PLAYER1LEFT_FILE_NAME{ "sprites\\player\\player1left.png" };
const std::string PLAYER1RIGHT_FILE_NAME{ "sprites\\player\\player1right.png" };

 float PlSpeedX = 0.2f;
 float PlSpeedY = 0.2f;
 /*class Data {
 private:
     Player* pla;
     float plposx;
     float plposy;
     int plstand;
     std::string filename;
 public:
     void setStructures(std::string FileName, Player& pl) {
         filename = FileName;
         pla = &pl;

     }
     void SaveGame() {
         std::ofstream file(filename + ".txt");
         if (file.is_open()) {
             file << pla->stand << "\n";
             file << pla->sprite.getPosition().x << "\n";
             file << pla->sprite.getPosition().y << "\n";

             file.close();
            
         }
         else {
            
         }
     }
     void LoadGame() {
         std::ifstream file(filename + ".txt");
         if (file.is_open()) {
             file >> plstand;
             file >> plposx;
             file >> plposy;
            
             pla->stand = plstand;
             pla->sprite.setPosition(plposx, plposy);

             file.close();
          
         }
         else {
          
         }

     }
 };*/


 struct LanguageFlags {
     sf::Texture texture;
     sf::Sprite sprite;
 };

 void LanguageFlagsInit(LanguageFlags& obj,sf::Vector2f pos,std::string filename){
     obj.texture.loadFromFile(filename);
     obj.sprite.setTexture(obj.texture);
     obj.sprite.setPosition(pos);
 }


