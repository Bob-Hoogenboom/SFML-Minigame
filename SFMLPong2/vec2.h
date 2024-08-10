#ifndef VECTOR2
#define VECTOR2

#pragma once
class vec2
{
private:
	float _x;
	float _y;

public:
	vec2();
	vec2(float x, float y);
	~vec2();

	//Const so the data can not be changed as its constant
	float getX() const;
	float getY() const;

	float magnitude() const;

	//Methods where you can change the Const value
	void setX( float x);
	void setY( float y);

	// Operator overloading for vector arithmetic
	vec2 operator+(const vec2& other) const;
	vec2& operator+=(const vec2& other);
	vec2 operator*(float scalar) const;

	bool operator>(const vec2& other) const;
	bool operator<(const vec2& other) const;

};

#endif