#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <random>
#include "vec2.h"


class ball
{
private:
	float _speedCap = 500.0f;

	sf::RectangleShape _ballShape;

	float _directionX = 1.0f;
	float _directionY = 1.0f;


public:
	ball(float startX, float startY, float sizeX, float sizeY); //Constructor
	
	vec2 sizeVec2;
	vec2 positionVec2;

	sf::FloatRect getPosition();
	sf::RectangleShape getShape();

	vec2 acceleration; //public so it can be editted in main to define speed
	vec2 velocity;

	float getXVelocity();


	void bounceSided();

	void bounceTop();

	void hitBottomVoid();

	void hitBall();

	void update(sf::Time deltaTime);
};

