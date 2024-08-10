#pragma once
#include <SFML/Graphics.hpp>
#include "vec2.h"

class paddle
{
private:
	vec2 _velocity;

	sf::RectangleShape _paddleShape; 

	float _speed = 1000.0f;

	bool _moveLeft = false;
	bool _moveRight = false;

public:
	paddle(float startX, float starty, float sizeX, float sizeY);

	vec2 sizeVec2;
	vec2 positionVec2;

	sf::RectangleShape getShape();
	sf::FloatRect getPosition();
	
	vec2 _acceleration; //public so it can be editted in main to define speed

	void moveLeft();
	void moveRight();

	void stopLeft();
	void stopRight();

	void update(sf::Time deltaTime);

};

