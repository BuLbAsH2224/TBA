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
class SaveManager {
private:
	std::string filename;
	Player* pl;
	Inventory* inv;
	
public:


	SaveManager(std::string filename2, Player& gl, Inventory& inv2) {
		filename = filename2;
		pl = &gl;
		inv = &inv2;
		
	}


	void saveData() {
		std::ofstream file(filename);

		if (file.is_open()) {
			file << pl->sprite.getPosition().x << " ";
			file << pl->sprite.getPosition().y << " ";
			file << pl->stand << " ";
			file << pl->money << " ";
			file << pl->FightTech << " ";
			file << pl->health << " ";
			for (int i = 0; i < 16; i++) {
				file << inv->getItems()[i].getID() << " ";
			}
			for (int i = 0; i < 9; i++) {
				file << inv->getCorpses()[i].getActive() << " ";
			}
		
		}

		file.close();
	}





	std::string loadData() {
		std::ifstream file(filename);
		std::string line;

		if (file.is_open()) {
			while (getline(file, line)) {
				std::istringstream iss(line);

				float x, y;
				int stand, money, FightTech;
				float health;
				bool saintcorpse;
				std::vector<int> ids;

				if (iss >> x >> y >> stand >> money >> FightTech >> health) {
					pl->sprite.setPosition(x, y);
					pl->stand = stand;
					pl->money = money;
					pl->FightTech = FightTech;
					pl->health = health;

					int id;
					for (int i = 0; i < 16; i++) {
						iss >> id;
						ids.push_back(id);
					}
					inv->setItemsFromIDs(ids);
					for (int i = 0; i < 9; i++) {
						iss >> id;
						inv->getCorpses()[i].setActive(id);
					}
				}
			}
		}

		file.close();
	}
	

};
	class Menu {
	private:
		Languages& language;
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
	
		std::string CREDITS{ "Credits:\nBuLbAsH - programmer, creator\nMainBladee - beta tester\ncret - designer\nVS - designer, beta tester" };
		std::wstring CREDITS_RU{ L"Разработчики:\nBuLbAsH - программист, создатель\nVS - дизайнер, бета-тестер\nMainBladee - бета-тестер\ncret - дизайнер" };

	    sf::Sprite Exitsprite;
		sf::Texture Exittexture;
		sf::Sprite Settingssprite;
		sf::Texture Settingstexture;
		sf::Sprite Savessprite;
		sf::Texture Savestexture;
		sf::Sprite Creditssprite;
		sf::Texture Creditstexture;
		
		
		sf::Texture Savetexture;
		sf::Sprite Save1sprite;
		sf::Sprite Save2sprite;
		sf::Sprite Save3sprite;
		sf::Sprite Save4sprite;
		sf::Text Save1Text;
		sf::Text Save1TimeText;
		sf::Text Load1Text;
		sf::Text Save2Text;
		sf::Text Load2Text;
		sf::Text Save3Text;
		sf::Text Load3Text;
		sf::Text Save4Text;
		sf::Text Load4Text;
		bool ButtonIsNotPress;
		bool SavesPress;
		SaveManager save1;
		SaveManager save2;
		SaveManager save3;
		SaveManager save4;
		bool SettingsPress;
		bool Close;
		bool CreditsPress;
		float viewpositionx;
		float viewpositiony;
		bool MenuView;
		tm* Time1;
	public:
		Menu(Languages& lang, Player& pl, Inventory& inv)
			: language(lang), save1("saves\\save1.txt", pl, inv), save2("saves\\save2.txt", pl, inv),
			save3("saves\\save3.txt", pl, inv), save4("saves\\save4.txt", pl, inv) {
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

			Savetexture.loadFromFile("sprites\\menu\\SaveButton.png");
			Save1sprite.setTexture(Savetexture);
			Save1sprite.setPosition({ 200.f,200.f });
			Save2sprite.setTexture(Savetexture);
			Save2sprite.setPosition({ 200.f ,Save1sprite.getPosition().y + 10.f + Save1sprite.getGlobalBounds().height});
			Save3sprite.setTexture(Savetexture);
			Save3sprite.setPosition({ 200.f,Save2sprite.getPosition().y + 10.f +  Save1sprite.getGlobalBounds().height });
			Save4sprite.setTexture(Savetexture);
			Save4sprite.setPosition({ 200.f,Save3sprite.getPosition().y + 10.f +  Save1sprite.getGlobalBounds().height });
			PlayText.setFont(font);
			PlayText.setCharacterSize(64);
			PlayText.setPosition(Playsprite.getPosition().x + 30, Playsprite.getPosition().y + 50);

			if (lang.EnglishText == true) {
				PlayText.setString("Play");
			}
			else if (lang.RussiaText == true) {
				PlayText.setString(L"Играть");
			}
			

			SettingsText.setFont(font);
			SettingsText.setCharacterSize(64);
			SettingsText.setPosition(Settingssprite.getPosition().x + 30, Settingssprite.getPosition().y + 50);
			if (lang.EnglishText == true) {
				SettingsText.setString("Settings");
			}
			else if (lang.RussiaText == true) {
				SettingsText.setString(L"Настройки");
			}
			

			ExitText.setFont(font);
			ExitText.setCharacterSize(64);
			ExitText.setPosition(Exitsprite.getPosition().x + 30, Exitsprite.getPosition().y + 50);
			if (lang.EnglishText == true) {
				ExitText.setString("Exit");
			}
			else if (lang.RussiaText == true) {
				ExitText.setString(L"Выйти");
			}
			

			CreditsText.setFont(font);
			CreditsText.setCharacterSize(64);
			CreditsText.setPosition(Creditssprite.getPosition().x + 30, Creditssprite.getPosition().y + 50);
			if (lang.EnglishText == true) {
				CreditsText.setString("Credits");
			}
			else if (lang.RussiaText == true) {
				CreditsText.setString(L"Создатели");
			}
			

			SupportText.setFont(font);
			SupportText.setCharacterSize(24);
			SupportText.setPosition(Exitsprite.getPosition().x  + 20, Exitsprite.getPosition().y + 20 + Exitsprite.getGlobalBounds().height);
			
			if (lang.EnglishText == true) {
				SupportText.setString("Support the author");
			}
			else if (lang.RussiaText == true) {
				SupportText.setString(L"Поддержать автора");
			}


		
			
			Save1Text.setFont(font);
			Save1Text.setCharacterSize(40);
			Save1Text.setPosition(Save1sprite.getPosition().x + 35.f, Save1sprite.getPosition().y + 40.f);

			Save1TimeText.setFont(font);
			Save1TimeText.setCharacterSize(40);
			Save1TimeText.setPosition(Save1sprite.getPosition().x, Save1sprite.getPosition().y + 40.f);

			Load1Text.setFont(font);
			Load1Text.setCharacterSize(40);
			Load1Text.setPosition(Save1sprite.getPosition().x + 405.f, Save1sprite.getPosition().y + 40.f);
			if (lang.EnglishText == true) {
				Save1Text.setString("Save Game");
				Load1Text.setString(L"Load Save");
			}
			else if (lang.RussiaText == true) {
				Save1Text.setString(L"сохранить игру");
				Load1Text.setString(L"Загрузить сохранение");
			}

			Save2Text.setFont(font);
			Save2Text.setCharacterSize(40);
			Save2Text.setPosition(Save2sprite.getPosition().x + 35.f, Save2sprite.getPosition().y + 40.f);
			Load2Text.setFont(font);
			Load2Text.setCharacterSize(40);
			Load2Text.setPosition(Save2sprite.getPosition().x + 405.f, Save2sprite.getPosition().y + 40.f);
			if (lang.EnglishText == true) {
				Save2Text.setString("Save Game");
				Load2Text.setString(L"Load Save");
			}
			else if (lang.RussiaText == true) {
				Save2Text.setString(L"сохранить игру");
				Load2Text.setString(L"Загрузить сохранение");
			}

			Save3Text.setFont(font);
			Save3Text.setCharacterSize(40);
			Save3Text.setPosition(Save3sprite.getPosition().x + 35.f, Save3sprite.getPosition().y + 40.f);
			Load3Text.setFont(font);
			Load3Text.setCharacterSize(40);
			Load3Text.setPosition(Save3sprite.getPosition().x + 405.f, Save3sprite.getPosition().y + 40.f);
			if (lang.EnglishText == true) {
				Save3Text.setString("Save Game");
				Load3Text.setString(L"Load Save");
			}
			else if (lang.RussiaText == true) {
				Save3Text.setString(L"сохранить игру");
				Load3Text.setString(L"Загрузить сохранение");
			}
			Save4Text.setFont(font);
			Save4Text.setCharacterSize(40);
			Save4Text.setPosition(Save4sprite.getPosition().x + 35.f, Save4sprite.getPosition().y + 40.f);
			Load4Text.setFont(font);
			Load4Text.setCharacterSize(40);
			Load4Text.setPosition(Save4sprite.getPosition().x + 405.f, Save4sprite.getPosition().y + 40.f);
			if (lang.EnglishText == true) {
				Save4Text.setString("Save Game");
				Load4Text.setString(L"Load Save");
			}
			else if (lang.RussiaText == true) {
				Save4Text.setString(L"сохранить игру");
				Load4Text.setString(L"Загрузить сохранение");
			}

			CReditsText.setFont(font);
			CReditsText.setCharacterSize(64);
			CReditsText.setPosition(0, 200);
			if (lang.EnglishText == true) {
				CReditsText.setString(CREDITS);
			}
			else if (lang.RussiaText == true) {
				CReditsText.setString(CREDITS_RU);
			}
			

			ButtonIsNotPress = true;
			SavesPress = false;
			CreditsPress = false;
			SettingsPress = false;
			 viewpositionx = 124673712485187.f;
			 viewpositiony = 124673712485187.f;
		}
		
		


		void setViewMenu(bool q) { MenuView = q; }
		bool getViewMenu() { return MenuView; }
		sf::Vector2f getViewPos() { return { viewpositionx,viewpositiony }; }
		void update(sf::Vector2f mouspos, sf::RenderWindow& window) {
			
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
					//system("start https://www.donationalerts.com/r/bulbashh");
				
					system("start https://www.youtube.com/watch?v=dQw4w9WgXcQ");
				}
			}
			else { SupportText.setFillColor(sf::Color::White);}
			
			if (Save1Text.getGlobalBounds().contains(mouspos.x, mouspos.y) && ButtonIsNotPress == false && SavesPress == true) {

				Save1Text.setFillColor(sf::Color::Black);
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
					save1.saveData();
				}
			}
			else{ Save1Text.setFillColor(sf::Color::White); }
			if (Load1Text.getGlobalBounds().contains(mouspos.x, mouspos.y) && ButtonIsNotPress == false && SavesPress == true) {

				Load1Text.setFillColor(sf::Color::Black);
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
					save1.loadData();
				}
			}
			else { Load1Text.setFillColor(sf::Color::White); }
			if (Save2Text.getGlobalBounds().contains(mouspos.x, mouspos.y) && ButtonIsNotPress == false && SavesPress == true) {

				Save2Text.setFillColor(sf::Color::Black);
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
					save2.saveData();
				}
			}
			else { Save2Text.setFillColor(sf::Color::White); }
			if (Load2Text.getGlobalBounds().contains(mouspos.x, mouspos.y) && ButtonIsNotPress == false && SavesPress == true) {

				Load2Text.setFillColor(sf::Color::Black);
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
					save2.loadData();
				}
			}
			else { Load2Text.setFillColor(sf::Color::White); }
			if (Save3Text.getGlobalBounds().contains(mouspos.x, mouspos.y) && ButtonIsNotPress == false && SavesPress == true) {

				Save3Text.setFillColor(sf::Color::Black);
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
					save3.saveData();
				}
			}
			else { Save3Text.setFillColor(sf::Color::White); }
			if (Load3Text.getGlobalBounds().contains(mouspos.x, mouspos.y) && ButtonIsNotPress == false && SavesPress == true) {

				Load3Text.setFillColor(sf::Color::Black);
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
					save3.loadData();
				}
			}
			else { Load3Text.setFillColor(sf::Color::White); }
			if (Save4Text.getGlobalBounds().contains(mouspos.x, mouspos.y) && ButtonIsNotPress == false && SavesPress == true) {

				Save4Text.setFillColor(sf::Color::Black);
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
					save4.saveData();
				}
			}
			else { Save4Text.setFillColor(sf::Color::White); }
			if (Load4Text.getGlobalBounds().contains(mouspos.x, mouspos.y) && ButtonIsNotPress == false && SavesPress == true) {

				Load4Text.setFillColor(sf::Color::Black);
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
					save4.loadData();
				}
			}
			else { Load4Text.setFillColor(sf::Color::White); }
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
			  
				window.draw(Save1sprite);
				window.draw(Save2sprite);
				window.draw(Save3sprite);
				window.draw(Save4sprite);
				window.draw(Save1Text);
				window.draw(Load1Text);
				window.draw(Save2Text);
				window.draw(Load2Text);
				window.draw(Save3Text);
				window.draw(Load3Text);
				window.draw(Save4Text);
				window.draw(Load4Text);
				
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

	
		
		void setViewMenu(bool q) { MenuView = q; }
		bool getViewMenu() { return MenuView; }
	
		void update(sf::Vector2f mouspos) {
			if (Retrysprite.getGlobalBounds().contains(mouspos.x, mouspos.y)) {

			
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {					
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