#include <cmath> //sqrt*
#include "vec2.h"

vec2::vec2() : _x(0), _y() 
{
	
}

vec2::vec2(float x, float y) 
	: _x(x), _y(y)
{}

vec2::~vec2() 
{

}

//Get the current X and Y of the vector2 anytime
float vec2::getX() const  
{
	return _x;
}

float vec2::getY() const 
{
	return _y;
}

float vec2::magnitude() const {
	return std::sqrt(_x * _x + _y * _y);
}

//Set a new X and Y on the Vector2 anytime
void vec2::setX( float x)
{
	_x = x;
}

void vec2::setY( float y) 
{
	_y = y;
}

vec2 vec2::operator+(const vec2& other) const {
	return vec2(_x + other._x, _y + other._y);
}

vec2& vec2::operator+=(const vec2& other) {
	_x += other._x;
	_y += other._y;
	return *this;
}

vec2 vec2::operator*(float scalar) const {
	return vec2(_x * scalar, _y * scalar);
}

bool vec2::operator>(const vec2& other) const {
	return this->magnitude() > other.magnitude();
}

bool vec2::operator<(const vec2& other) const {
	return this->magnitude() < other.magnitude();
}
