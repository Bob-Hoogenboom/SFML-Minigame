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

//Returns the magnitude of a vector
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

//creates a new vector that contains the result of 2 vectors added.
vec2 vec2::operator+(const vec2& other) const {
	return vec2(_x + other._x, _y + other._y);
}

//Adds the value of the (other) vector to (this) vector and changes the current vector
vec2& vec2::operator+=(const vec2& other) {
	_x += other._x;
	_y += other._y;
	return *this;
}

//creates a new vector that contains the result of 2 vectors subtracted.
vec2 vec2::operator-(const vec2& other) const {
	return vec2(_x - other._x, _y - other._y);
}

//Subtracts the value of the (other) vector from (this) vector and changes the current vector
vec2& vec2::operator-=(const vec2& other) {
	_x -= other._x;
	_y -= other._y;
	return *this;
}

//Multiplies the vector by a scalar value, a scaar value of 2 makes the value 2 times as big
vec2 vec2::operator*(float scalar) const {
	return vec2(_x * scalar, _y * scalar);
}

//Checks if (this) vector is bigger then the (other) vector
bool vec2::operator>(const vec2& other) const {
	return this->magnitude() > other.magnitude();
}

//Checks if (this) vector is smaller then the (other) vector
bool vec2::operator<(const vec2& other) const {
	return this->magnitude() < other.magnitude();
}
