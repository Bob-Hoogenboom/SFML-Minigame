#include "paddle.h"

paddle::paddle(float startX, float startY, float sizeX, float sizeY)
{
	_positionVec2.setX(startX);
	_positionVec2.setY(startY);

	_sizeVec2.setX(sizeX);
	_sizeVec2.setY(sizeY);

	_paddleShape.setSize(sf::Vector2f(_sizeVec2.getX(), _sizeVec2.getY()));
	_paddleShape.setFillColor(sf::Color(15, 56, 15)); //Darkest gameboy color
	_paddleShape.setOutlineColor(sf::Color(15, 56, 15));
	_paddleShape.setOutlineThickness(3);

	_paddleShape.setPosition(sf::Vector2f(_positionVec2.getX(), _positionVec2.getY()));
}

sf::FloatRect paddle::getPosition() 
{
	return _paddleShape.getGlobalBounds();
}

sf::RectangleShape paddle::getShape() 
{
	return _paddleShape;
}

void paddle::moveLeft() 
{
	_moveLeft = true;
}

void paddle::moveRight() 
{
	_moveRight = true;
}

void paddle::stopLeft() 
{
	_moveLeft = false;
	if (_moveRight == false)
	{
		_velocity = vec2(0, 0);
	}
}

void paddle::stopRight() 
{
	_moveRight = false;
	if (_moveLeft == false)
	{
		_velocity = vec2(0, 0);
	}
}

void paddle::update(sf::Time deltaTime) 
{
	if (_moveLeft) {
		
		_velocity += _acceleration * deltaTime.asSeconds();
		_positionVec2.setX( _positionVec2.getX() -  _velocity.getX() * deltaTime.asSeconds());
	}

	if (_moveRight)
	{
		_velocity += _acceleration * deltaTime.asSeconds();
		_positionVec2.setX( _positionVec2.getX() + _velocity.getX() * deltaTime.asSeconds());
	}

	_paddleShape.setPosition(sf::Vector2f(_positionVec2.getX(), _positionVec2.getY()));
}