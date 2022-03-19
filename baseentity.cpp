#include "baseentity.h"

void BaseEntity::step()
{
	vector2D accel = this->acceleration;
	accel.y -= mass * gravity;

	velocity += accel;
	origin += velocity;
}

void BaseEntity::setOrigin( vector2D origin )
{
	this->origin = origin;
}

void BaseEntity::setMass(float flMass)
{
	this->mass = flMass;
}

void BaseEntity::setVelocity(vector2D vecVelocity)
{
	this->velocity = vecVelocity;
}

void BaseEntity::setAngle(float flAngle)
{
	this->angle = flAngle;	
}

void BaseEntity::setAngleVelocity(float flAngleVelocity)
{
	this->angleVelocity = flAngleVelocity;
}

void BaseEntity::setGravity(float flGravity)
{
	this->gravity = flGravity;
}
