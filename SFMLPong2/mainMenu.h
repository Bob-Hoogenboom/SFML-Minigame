#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

#define MaxMainMenu 3 //3 options 'PlayGame', 'HighScore' and 'Quit'

class mainMenu
{
private:
	int mainMenuSelected;
	sf::Font font;
	sf::Text mainMenuTabs[MaxMainMenu];

public:
	mainMenu(float width, float height);

	void draw(sf::RenderWindow& window);
	void moveUp();
	void moveDown();

	int mainMenuPressed() {
		return mainMenuSelected;
	}

	~mainMenu();
};

