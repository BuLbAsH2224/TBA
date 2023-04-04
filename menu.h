#pragma once
#include "settings.h"
struct backgrounds {
	sf::Texture texture;
	sf::Sprite sprite;
	bool visible = false;
};

struct buttons {
	sf::Texture texture;
	sf::Sprite sprite;
	bool pressed = false;
	bool visible = false;
};
buttons Play;
buttons Exit;
buttons Settings;
buttons Saves;
buttons Back;


backgrounds background1;
bool MenuOn = true;
bool textureLoaded = false;
void menu(sf::RenderWindow& window, sf::Vector2f mouspos) {

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



