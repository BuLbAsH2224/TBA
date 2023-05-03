#pragma once
#include "settings.h"

bool MenuOn = true;
bool GameOverOn = false;



/*void menu(sf::RenderWindow& window, sf::Vector2f mouspos) {

	if (textureLoaded == false) {
	
		background1.texture.loadFromFile("sprites\\menu\\background1.png");
		background1.sprite.setTexture(background1.texture);
		background1.sprite.setPosition(0, 0);

		Back.texture.loadFromFile("sprites\\menu\\Back.png");
		Back.sprite.setTexture(Back.texture);
		Back.sprite.setPosition(0, 0);

		Play.texture.loadFromFile("sprites\\menu\\Buttons.png");
		Play.sprite.setTexture(Play.texture);
		Play.sprite.setPosition(1000 - 230, 500);

		Exit.texture.loadFromFile("sprites\\menu\\Buttons.png");
		Exit.sprite.setTexture(Exit.texture);
		Exit.sprite.setPosition(0, 0);

		Settings.texture.loadFromFile("sprites\\menu\\Buttons.png");
		Settings.sprite.setTexture(Settings.texture);
		Settings.sprite.setPosition(0, 0);

		Saves.texture.loadFromFile("sprites\\menu\\Saves.png");
		Saves.sprite.setTexture(Saves.texture);
		Saves.sprite.setPosition(50, 1080 - 149);
		textureLoaded = true;

	}
	if (Saves.pressed == false) {
		background1.visible = true;
		Play.visible = true;
		Exit.visible = true;
		Settings.visible = true;
		Saves.visible = true;
		Back.visible = false;
	}
	if (Saves.pressed == true) {
		background1.visible = false;
		Play.visible = false;
		Exit.visible = false;
		Settings.visible = false;
		Saves.visible = false;
		Back.visible = true;
	}
	Play.sprite.setTexture(Play.texture);
	if (Play.sprite.getGlobalBounds().contains(mouspos.x, mouspos.y) && Play.visible == true) {
		Play.texture.loadFromFile("sprites\\menu\\ButtonsCont.png");
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
			MenuOn = false;
		}
	}
	else {
		Play.texture.loadFromFile("sprites\\menu\\Buttons.png");
	}
	if (Saves.sprite.getGlobalBounds().contains(mouspos.x, mouspos.y) && Saves.visible == true) {
		Saves.texture.loadFromFile("sprites\\menu\\SavesCont.png");
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
			Saves.pressed = true;
		}
	}
	else {
		Saves.texture.loadFromFile("sprites\\menu\\Saves.png");
	}
	if (Back.sprite.getGlobalBounds().contains(mouspos.x, mouspos.y) && Back.visible == true) {
		Back.texture.loadFromFile("sprites\\menu\\BackCont.png");
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
			if (Saves.pressed == true) {
				Saves.pressed = false;

			}
		}
	}
	else {
		Back.texture.loadFromFile("sprites\\menu\\Back.png");
	}
		
		
		window.clear();
		if (background1.visible == true) {
			window.draw(background1.sprite);
		}
		if (Play.visible == true) {
			window.draw(Play.sprite);
		}
		if (Exit.visible == true) {
			window.draw(Exit.sprite);
		}
		if (Settings.visible == true) {
			window.draw(Settings.sprite);
		}
		if (Saves.visible == true) {
			window.draw(Saves.sprite);
		}
		if (Back.visible == true) {
			window.draw(Back.sprite);
		}
	
		
		
		window.display();
	}
	*/

	class Menu {
	private:
		sf::Sprite background1sprite;
		sf::Texture background1texture;
		sf::Sprite Backsprite;
		sf::Texture Backtexture;
		sf::Sprite Playsprite;
		sf::Texture Playtexture;
		
		sf::Font font;
		sf::Text PlayText;
		sf::Text SettingsText;
		sf::Text ExitText;
		sf::Text CreditsText;
		sf::Text SupportText;
		sf::Text CReditsText;
		sf::Text SavesText;
		std::string CREDITS{"Credits:\nBuLbAsH - programmer, creator\nMainBladee - beta tester\ncret - designer\nVS - designer, beta tester"};

	    sf::Sprite Exitsprite;
		sf::Texture Exittexture;
		sf::Sprite Settingssprite;
		sf::Texture Settingstexture;
		sf::Sprite Savessprite;
		sf::Texture Savestexture;
		sf::Sprite Creditssprite;
		sf::Texture Creditstexture;
		
		bool ButtonIsNotPress;
		bool SavesPress;
	
		bool SettingsPress;
		bool Close;
		bool CreditsPress;
		float viewpositionx;
		float viewpositiony;
		bool MenuView;
	public:
		Menu() {
			MenuView = true;
			Close = false;
			font.loadFromFile("NjalBold.ttf");
			background1texture.loadFromFile("sprites\\menu\\background1.png");
			background1sprite.setTexture(background1texture);
			background1sprite.setPosition(0, 0);

			Backtexture.loadFromFile("sprites\\menu\\Back.png");
			Backsprite.setTexture(Backtexture);
			Backsprite.setPosition(1920 - 149, 0);

			Playtexture.loadFromFile("sprites\\menu\\Buttons.png");
			Playsprite.setTexture(Playtexture);
			Playsprite.setPosition(0, 200);

			Exittexture.loadFromFile("sprites\\menu\\Buttons.png");
			Exitsprite.setTexture(Exittexture);
			Exitsprite.setPosition(0, 800);

			Settingstexture.loadFromFile("sprites\\menu\\Buttons.png");
			Settingssprite.setTexture(Settingstexture);
			Settingssprite.setPosition(0, 400);

			Creditstexture.loadFromFile("sprites\\menu\\Buttons.png");
			Creditssprite.setTexture(Creditstexture);
			Creditssprite.setPosition(0, 600);

		
			Savestexture.loadFromFile("sprites\\menu\\Saves.png");
			Savessprite.setTexture(Savestexture);
			Savessprite.setPosition(1920 - 149, 1080 - 149);

			PlayText.setFont(font);
			PlayText.setCharacterSize(64);
			PlayText.setPosition(Playsprite.getPosition().x + 50, Playsprite.getPosition().y + 50);
			PlayText.setString("Play");

			SettingsText.setFont(font);
			SettingsText.setCharacterSize(64);
			SettingsText.setPosition(Settingssprite.getPosition().x + 50, Settingssprite.getPosition().y + 50);
			SettingsText.setString("Settings");

			ExitText.setFont(font);
			ExitText.setCharacterSize(64);
			ExitText.setPosition(Exitsprite.getPosition().x + 50, Exitsprite.getPosition().y + 50);
			ExitText.setString("Exit");

			CreditsText.setFont(font);
			CreditsText.setCharacterSize(64);
			CreditsText.setPosition(Creditssprite.getPosition().x + 50, Creditssprite.getPosition().y + 50);
			CreditsText.setString("Credits");

			SupportText.setFont(font);
			SupportText.setCharacterSize(24);
			SupportText.setPosition(Exitsprite.getPosition().x  + 20, Exitsprite.getPosition().y + 20 + Exitsprite.getGlobalBounds().height);
			SupportText.setString("Support the author");


			SavesText.setFont(font);
			SavesText.setCharacterSize(64);
			SavesText.setPosition(50,200);
			SavesText.setString("Load Auto Save");


			CReditsText.setFont(font);
			CReditsText.setCharacterSize(64);
			CReditsText.setPosition(0, 200);
			CReditsText.setString(CREDITS);

			ButtonIsNotPress = true;
			SavesPress = false;
			CreditsPress = false;
			SettingsPress = false;
			 viewpositionx = 124673712485187.f;
			 viewpositiony = 124673712485187.f;
		}
		
		void loadAutoSave(std::string filename, sf::View& view, Player& obj, Quests& quest1, Quests& quest2, float posx, float posy, float hp, float& viewposx, float& viewposy) {
			std::ifstream file(filename);
			if (file.is_open()) {
				
				file >> obj.stand;
				file >> quest1.done;
				file >> quest1.active;
				file >> quest2.done;
				file >> quest2.active;
				file >> posx;
				file >> posy;
				file >> obj.health;;
				file >> viewposy;
				file >> viewposx;
				viewposx = viewposx;
				
				viewposy = viewposy;

				obj.stand = obj.stand;
				obj.health = obj.health;
				quest1.done = quest1.done;
				quest1.active = quest1.active;
				quest2.done = quest2.done;
				quest2.active = quest2.active;
				obj.sprite.setPosition(posx, posy);
				file.close();
			}
			else {

			}
		}


		void setViewMenu(bool q) { MenuView = q; }
		bool getViewMenu() { return MenuView; }
		sf::Vector2f getViewPos() { return { viewpositionx,viewpositiony }; }
		void update( sf::Vector2f mouspos, sf::RenderWindow& window, std::string filename, sf::View& view, Player& obj, Quests& quest1, Quests& quest2, float posx, float posy, float hp) {
			if (Playsprite.getGlobalBounds().contains(mouspos.x, mouspos.y) && ButtonIsNotPress == true) {
				
			    Playtexture.loadFromFile("sprites\\menu\\ButtonsCont.png");
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
					MenuOn = false;
				}
			}
			else{ Playtexture.loadFromFile("sprites\\menu\\Buttons.png"); }
			if (Creditssprite.getGlobalBounds().contains(mouspos.x, mouspos.y) && ButtonIsNotPress == true) {

				Creditstexture.loadFromFile("sprites\\menu\\ButtonsCont.png");
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
					ButtonIsNotPress = false;
					CreditsPress = true;
				}
			}
			else { Creditstexture.loadFromFile("sprites\\menu\\Buttons.png"); }
			if (Exitsprite.getGlobalBounds().contains(mouspos.x, mouspos.y) && ButtonIsNotPress == true) {

				Exittexture.loadFromFile("sprites\\menu\\ButtonsCont.png");
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
					window.close();
					Close = true;
				}
			}
			else { Exittexture.loadFromFile("sprites\\menu\\Buttons.png"); }
			if (Settingssprite.getGlobalBounds().contains(mouspos.x, mouspos.y) && ButtonIsNotPress == true) {

				Settingstexture.loadFromFile("sprites\\menu\\ButtonsCont.png");
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
					
				}
			}
			else { Settingstexture.loadFromFile("sprites\\menu\\Buttons.png"); }
			if (Backsprite.getGlobalBounds().contains(mouspos.x, mouspos.y) && ButtonIsNotPress == false) {

			
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
					ButtonIsNotPress = true;
					SavesPress = false;
					CreditsPress = false;
					SettingsPress = false;
				}
			}
			if (SupportText.getGlobalBounds().contains(mouspos.x, mouspos.y) && ButtonIsNotPress == true) {

				SupportText.setFillColor(sf::Color::Black);
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
					system("start https://www.donationalerts.com/r/bulbashh");
				}
			}
			else { SupportText.setFillColor(sf::Color::White);}
			if (SavesText.getGlobalBounds().contains(mouspos.x, mouspos.y) && ButtonIsNotPress == false && SavesPress == true) {

				SavesText.setFillColor(sf::Color::Black);
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
					loadAutoSave(filename, view, obj, quest1, quest2, posx, posy, hp, viewpositionx, viewpositiony);
				}
			}
			else{ SavesText.setFillColor(sf::Color::White); }
			if (Savessprite.getGlobalBounds().contains(mouspos.x, mouspos.y) && ButtonIsNotPress == true) {
				
				
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
					SavesPress = true;
					ButtonIsNotPress = false;
				}
			}
		}
		void draw(sf::Text& vers,CursorArrow& curs, sf::RenderWindow& window) {
			window.clear();
			window.draw(background1sprite);
			vers.setPosition(0.f, 1060.f - vers.getGlobalBounds().height);
			if (SavesPress == true) {
				window.draw(Backsprite);
			    window.draw(SavesText);
			}
			if (CreditsPress == true) {
				window.draw(CReditsText);
				window.draw(Backsprite);
			}
			if (ButtonIsNotPress == true) {
				
				window.draw(Savessprite);
				window.draw(Settingssprite);
				window.draw(Exitsprite);
				window.draw(Playsprite);
				window.draw(Creditssprite);
				window.draw(Creditssprite);
				window.draw(PlayText);
				window.draw(SettingsText);
				window.draw(ExitText);
				window.draw(CreditsText);
				window.draw(SupportText);
				
			}
			window.draw(vers);
			curs.draw(window);

			window.display();
		}

		bool getClose() { return Close; }
	};


	class GameOver {
	private:
		sf::Sprite background1sprite;
		sf::Texture background1texture;
		sf::Sprite Retrysprite;
		sf::Texture Retrytexture;
		bool MenuView;
		float viewpositionx;
		float viewpositiony;
	public:
		GameOver() {
			viewpositionx = 0.f;
			viewpositiony = 0.f;
			background1texture.loadFromFile("sprites\\menu\\GameOverScreen.png");
			background1sprite.setTexture(background1texture);
			background1sprite.setPosition(0, 0);
			MenuView = false;
			Retrytexture.loadFromFile("sprites\\menu\\ReplayMenu.png");
			Retrysprite.setTexture(Retrytexture);
			Retrysprite.setPosition(background1sprite.getPosition().x + 798, background1sprite.getPosition().y + 906);
			
			
		}

		void loadAutoSave(sf::RenderWindow& window,std::string filename, sf::View& view, Player& obj, Quests& quest1, Quests& quest2, float posx, float posy, float hp, float& viewposx, float& viewposy) {
			std::ifstream file(filename);
			if (file.is_open()) {

				file >> obj.stand;
				file >> quest1.done;
				file >> quest1.active;
				file >> quest2.done;
				file >> quest2.active;
				file >> posx;
				file >> posy;
				file >> obj.health;
				file >> viewposx;
				file >> viewposy;
				viewpositionx = viewposy;
				viewpositiony = viewposy;
			
				obj.stand = obj.stand;
				obj.health = obj.health;
				quest1.done = quest1.done;
				quest1.active = quest1.active;
				quest2.done = quest2.done;
				quest2.active = quest2.active;
				obj.sprite.setPosition(posx, posy);
				file.close();
			}
			else {
				
			}
		}
		
		void setViewMenu(bool q) { MenuView = q; }
		bool getViewMenu() { return MenuView; }
	
		void update(sf::RenderWindow& window, sf::Vector2f mouspos, std::string filename, sf::View& view, Player& obj, Quests& quest1, Quests& quest2, float posx, float posy, float hp) {
			if (Retrysprite.getGlobalBounds().contains(mouspos.x, mouspos.y)) {

			
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
					loadAutoSave(window,filename, view, obj, quest1, quest2, posx, posy, hp, viewpositionx, viewpositiony);
					GameOverOn = false;
					MenuOn = true;
				}
			}
			else { Retrytexture.loadFromFile("sprites\\menu\\ReplayMenu.png"); }
		
			
		}
		sf::Vector2f getViewPos() { return { viewpositionx,viewpositiony }; }

		void draw(CursorArrow& curs, sf::RenderWindow& window) {
			window.clear();
			window.draw(background1sprite);
			window.draw(Retrysprite);
			curs.draw(window);

			window.display();
		}
	};