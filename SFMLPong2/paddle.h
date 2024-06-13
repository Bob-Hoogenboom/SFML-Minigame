#pragma once
#include <SFML/Graphics.hpp>
#include "vec2.h"

class paddle
{
private:
	vec2 _sizeVec2;//# Change later to own Vector2 math utility class
	vec2 _positionVec2;
	sf::RectangleShape _paddleShape; 

	float _speed = 1000.0f;

	bool _moveLeft = false;
	bool _moveRight = false;

public:
	paddle(float startX, float starty, float sizeX, float sizeY);

	sf::RectangleShape getShape();
	sf::FloatRect getPosition();

	void moveLeft();
	void moveRight();

	void stopLeft();
	void stopRight();

	void update(sf::Time deltaTime);

};

