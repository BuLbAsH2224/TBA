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
#include "map.h"
#include "savesandloades.h"
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
const std::string VERSION_NAME{ "alpha 0.9.7" };
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


