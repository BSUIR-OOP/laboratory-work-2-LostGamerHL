#include "baseentity.h"

void BaseEntity::step()
{
	vector2D accel = this->acceleration;
	accel.y -= mass * gravity;

	velocity += accel;
	origin += velocity;
}

void BaseEntity::setOrigin( vector2D vecOrigin )
{
	this->origin = vecOrigin;
}

void BaseEntity::setMass(float flMass)
{
	this->mass = flMass;
	this->inv_mass = 1.f/flMass;
}

void BaseEntity::setVelocity(vector2D vecVelocity)
{
	this->velocity = vecVelocity;
}

void BaseEntity::setAngle(float flAngle)
{
	this->angle = flAngle;
}

void BaseEntity::setAngularVelocity(float flAngularVelocity)
{
	this->angularVelocity = flAngularVelocity;
}

void BaseEntity::setGravity(float flGravity)
{
	this->gravity = flGravity;
}

void BaseEntity::ApplyImpulse(vector2D vecImpulse)
{
	this->impulse = vecImpulse;
	velocity += impulse * inv_mass;
}

void BaseEntity::setStatic( bool flag )
{
	is_static = flag;
	if( flag == true )
		this->inv_mass = 0.f;
	else
		this->inv_mass = 1.f/mass;
}
