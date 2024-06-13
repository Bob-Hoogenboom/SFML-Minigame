#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <random>
#include "vec2.h"


class ball
{
private:
	vec2 _sizeVec2;
	vec2 _positionVec2;  //# Change later to own Vector2 math utility class
	sf::RectangleShape _ballShape;

	float _speed = 300.0f;
	float _directionX = 1.0f;
	float _directionY = 1.0f;


public:
	ball(float startX, float startY, float sizeX, float sizeY);//Constructor
	sf::FloatRect getPosition();
	sf::RectangleShape getShape();

	float getXVelocity();


	void bounceSided();

	void bounceTop();

	void hitBottomVoid();

	void hitBall();

	void update(sf::Time deltaTime);
};

