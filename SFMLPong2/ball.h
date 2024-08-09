#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <random>
#include "vec2.h"


class ball
{
private:
	vec2 _sizeVec2;
	vec2 _positionVec2;
	vec2 _velocity;
	sf::RectangleShape _ballShape;

	float _directionX = 1.0f;
	float _directionY = 1.0f;


public:
	ball(float startX, float startY, float sizeX, float sizeY);//Constructor
	sf::FloatRect getPosition();
	sf::RectangleShape getShape();

	vec2 acceleration; //public so it can be editted in main to define speed

	float getXVelocity();


	void bounceSided();

	void bounceTop();

	void hitBottomVoid();

	void hitBall();

	void update(sf::Time deltaTime);
};

