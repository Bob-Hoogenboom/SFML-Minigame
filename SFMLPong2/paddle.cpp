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
}

void paddle::stopRight() 
{
	_moveRight = false;
}

void paddle::update(sf::Time deltaTime) 
{
	if (_moveLeft) {
		_positionVec2.setX( _positionVec2.getX() -  _speed * deltaTime.asSeconds());
	}

	if (_moveRight)
	{
		_positionVec2.setX( _positionVec2.getX() + _speed * deltaTime.asSeconds());
	}

	_paddleShape.setPosition(sf::Vector2f(_positionVec2.getX(), _positionVec2.getY()));
}