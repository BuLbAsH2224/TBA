#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <fstream>
#include <list>

#include "standIplayer.h"
#include "arrow.h"
#include "map.h"
#include "Playerpowers.h"
#include "vragi.h"
#include "HUD.h"
#include "NPC.h"
#include "quests.h"
#include "menu.h"
const float WINDOW_X = 1920;
const float WINDOW_Y = 1080;
 float hsh = 0.f;



const std::string GRASS1_FILE_NAME{ "sprites\\map\\grass1.jpg" };
const std::string ARROW_FILE_NAME{ "sprites\\objects\\arrow.png" };
const std::string VERSION_NAME{ "alpha 0.5" };
const std::string PLAYER1LEFT_FILE_NAME{ "sprites\\player\\player1left.png" };
const std::string PLAYER1RIGHT_FILE_NAME{ "sprites\\player\\player1right.png" };
int ArrowInv = 0;

 float PlSpeedX = 3.f;
 float PlSpeedY = 3.f;

 void saveGame(Player& obj, Quests& quest1, Quests& quest2,float posx, float posy) {
     std::ofstream file("saved_game.txt");
     if (file.is_open()) {
         file << obj.stand << "\n";
         file << quest1.done << "\n";
         file << quest1.active << "\n";
         file << quest2.done << "\n";
         file << quest2.active << "\n";
         file << posx  << "\n";
         file << posy << "\n";
        
         file.close();
         std::cout << "Игровые данные сохранены в файл." << std::endl;
     }
     else {
         std::cout << "Не удалось открыть файл." << std::endl;
     }
 }
 

 void loadGame(Player& obj, Quests& quest1, Quests& quest2, float posx, float posy) {
     std::ifstream file("saved_game.txt");
     if (file.is_open()) {
         file >> obj.stand;
         file >> quest1.done;
         file >> quest1.active;
         file >> quest2.done;
         file >> quest2.active;
         file >> posx  ;
         file >> posy ;
        
         
         obj.stand = obj.stand;
         quest1.done = quest1.done;
         quest1.active = quest1.active;
         quest2.done = quest2.done;
         quest2.active = quest2.active;
         obj.sprite.setPosition(posx, posy);
         
         file.close();
         std::cout << "Игровые данные загружены из файла." << std::endl;
     }
     else {
         std::cout << "Не удалось открыть файл." << std::endl;
     }
 }
