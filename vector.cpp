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
	return vector2D(x+other.x, y+other.y);
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

vector2D vector2D::operator -()
{
	return vector2D( -x, -y );
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

// 3 dimensions

vector3D::vector3D(float x, float y, float z)
{
	this->x = x;
	this->y = y;
	this->z = z;
}

// sum

vector3D vector3D::operator +(const vector3D &other)
{
	return vector3D(x+other.x, y+other.y);
}

void vector3D::operator +=(const vector3D &other)
{
	x += other.x;
	y += other.y;
	z += other.z;
}

// diff

vector3D vector3D::operator -(const vector3D &other)
{
	return vector3D(x-other.x, y-other.y, z-other.z);
}

vector3D vector3D::operator -()
{
	return vector3D( -x, -y, -z );
}

void vector3D::operator -=(const vector3D &other)
{
	x -= other.x;
	y -= other.y;
	z -= other.z;
}

// mult

void vector3D::operator *=(const float num)
{
	x *= num;
	y *= num;
	z *= num;
}

vector3D vector3D::operator *(const float num)
{
	return vector3D(this->x*num, this->y*num, this->z*num);
}

// div

void vector3D::operator /=(const float num)
{
	x /= num;
	y /= num;
	z /= num;
}

vector3D vector3D::operator /(const float num)
{
	return vector3D(this->x/num, this->y/num, this->z/num);
}

float vector3D::length()
{
	return sqrt(x*x+y*y+z*z);
}

vector3D vector3D::normalize()
{
	return (*this)/length();
}

void vector3D::setZero()
{
	x = 0.f;
	y = 0.f;
	z = 0.f;
}

float vector3D::scalar(const vector3D &other)
{
	return x*other.x+y*other.y+z*other.z;
}

float vector3D::dist(const vector3D &other)
{
	return sqrt(pow(x-other.x,2)+pow(y-other.y, 2)+pow(z-other.z, 2));
}
