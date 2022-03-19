#include "vector.h"
#include <math.h>
#include <stdio.h>

vector2D::vector2D(float x, float y)
{
	this->x = x;
	this->y = y;
}

// sum

vector2D vector2D::operator +(const vector2D &other)
{
	return vector2D(x+other.x, y+other.x);
}

void vector2D::operator +=(const vector2D &other)
{
	x += other.x;
	y += other.y;
}

// diff

vector2D vector2D::operator -(const vector2D &other)
{
	return vector2D(x-other.x, y-other.y);
}

void vector2D::operator -=(const vector2D &other)
{
	x -= other.x;
	y -= other.y;
}

// mult

void vector2D::operator *=(const float num)
{
	x *= num;
	y *= num;
}

vector2D vector2D::operator *(const float num)
{
	return vector2D(this->x*num, this->y*num);
}

// div

void vector2D::operator /=(const float num)
{
	x /= num;
	y /= num;
}

vector2D vector2D::operator /(const float num)
{
	return vector2D(this->x/num, this->y/num);
}

float vector2D::length()
{
	return sqrt(x*x+y*y);
}

vector2D vector2D::normalize()
{
	return (*this)/length();
}

void vector2D::setZero()
{
	x = 0.f;
	y = 0.f;
}

float vector2D::scalar(const vector2D &other)
{
	return x*other.x+y*other.y;
}

float vector2D::dist(const vector2D &other)
{
	return sqrt(pow(x-other.x,2)+pow(y-other.y, 2));
}
