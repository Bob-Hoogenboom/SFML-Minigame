#include "ball.h"

//Constructor
//Sets the given start position to its current position and sets the size
ball::ball(float startX, float startY, float sizeX, float sizeY) 
{
	sizeVec2.setX(sizeX);
	sizeVec2.setY(sizeY);

	positionVec2.setX(startX);
	positionVec2.setY(startY);

	_ballShape.setSize(sf::Vector2f(sizeVec2.getX(), sizeVec2.getY()));
	_ballShape.setFillColor(sf::Color(15, 56, 15)); //Darkest gameboy color;
	_ballShape.setPosition(sf::Vector2f(1.0f, 400.0f));
}

//A Member Function to return the current position of the ball
sf::FloatRect ball::getPosition()
{
	return _ballShape.getGlobalBounds();
}

//A Member Function whic returns the shape of the ball
//# can this be replaced by a sprite to make the balla ppear different?
sf::RectangleShape ball::getShape()	
{
	return _ballShape;
}

//Mat not be used but is usefull Member Function for debugging the ball later on
float ball:: getXVelocity()  
{
	return _directionX;
}

//A Member Function that switches the direction of the X axis when one of either side is hit
void ball::bounceSided()
{
	_directionX = -_directionX;
}

//A Member Function that switches the direction of the Y axis when the top side is hit
void ball::bounceTop()
{
	_directionY = -_directionY;
}

void ball::hitBottomVoid()
{
	//Generate a random int for the X axis so the gameplay varies a little every time the ball hits the bottom
	std::random_device random;
	std::uniform_int_distribution<int> dist(10, 1270);
	
	positionVec2.setX(dist(random));
	positionVec2.setY(1);	
}

//Changes the direction of the ball upwards when the ball hits a paddle
void ball::hitBall() 
{
	_directionY = -_directionY;
}

//This Member Function calculates the new Ball position and sets it accordingly
void ball::update(sf::Time deltaTime) 
{
	if (velocity < vec2(_speedCap, _speedCap))
	{
		velocity += acceleration * deltaTime.asSeconds();
	}
	else {
		velocity = vec2(_speedCap, _speedCap);
	}
	positionVec2.setX( positionVec2.getX() + _directionX * velocity.getX() * deltaTime.asSeconds());
	positionVec2.setY(positionVec2.getY() + _directionY * velocity.getY() * deltaTime.asSeconds());

	_ballShape.setPosition(sf::Vector2f(positionVec2.getX(), positionVec2.getY()));
}


