#include "mainMenu.h"

mainMenu::mainMenu(float width, float height) 
{
	if (!font.loadFromFile("Fonts/PixelEmulator.ttf")) {
		std::cout << "FontNotFound";
	}

	//play button
	mainMenuTabs[0].setFont(font);
	mainMenuTabs[0].setFillColor(sf::Color(139, 172, 15));
	mainMenuTabs[0].setString("StartGame");
	mainMenuTabs[0].setCharacterSize(70);
	mainMenuTabs[0].setPosition(400, 200);

	//high score button
	mainMenuTabs[1].setFont(font);
	mainMenuTabs[1].setFillColor(sf::Color(139, 172, 15));
	mainMenuTabs[1].setString("HighScore");
	mainMenuTabs[1].setCharacterSize(70);
	mainMenuTabs[1].setPosition(400, 300);

	//quit button
	mainMenuTabs[2].setFont(font);
	mainMenuTabs[2].setFillColor(sf::Color(139, 172, 15));
	mainMenuTabs[2].setString("Quit");
	mainMenuTabs[2].setCharacterSize(70);
	mainMenuTabs[2].setPosition(400, 400);

	mainMenuSelected = 0;
}

mainMenu::~mainMenu()
{
	std::cout << "mainMenu destructor called" << std::endl;
}


void mainMenu::draw(sf::RenderWindow& window) 
{
	for (int i = 0; i < MaxMainMenu; i++)
	{
		window.draw(mainMenuTabs[i]);
	}
}

void mainMenu::moveUp() 
{
	if (mainMenuSelected - 1 > -1)
	{
		mainMenuTabs[mainMenuSelected].setFillColor(sf::Color(139, 172, 15));

		mainMenuSelected--;
		mainMenuTabs[mainMenuSelected].setFillColor(sf::Color(15, 56, 15));
	}
}

void mainMenu::moveDown()
{
	if (mainMenuSelected + 1 < MaxMainMenu)
	{
		mainMenuTabs[mainMenuSelected].setFillColor(sf::Color(139, 172, 15));

		mainMenuSelected++;
		mainMenuTabs[mainMenuSelected].setFillColor(sf::Color(15, 56, 15));
	}
}