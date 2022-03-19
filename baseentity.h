#ifndef BASEENTITY_H
#define BASEENTITY_H

#include "vector.h"
#include <stdio.h>

#define SHAPE_COUNT 2

enum PhysicsShapeType
{
	SHAPE_NONE = -1,
	SHAPE_CIRCLE = 0,
	SHAPE_RECTANGLE = 1,
};

class BaseEntity
{
public:
	BaseEntity() {
		gravity = 1.f;
		impulse = 0;
		mass = 0.f;
		inv_mass = 0.f;
		velocity = vector2D(0, 0);
		origin = vector2D(0, 0);
		angle = vector2D(0, 0);
		acceleration = vector2D(0, 0);
		normal = vector2D(0, 0);
		angleVelocity = 0.f;
	}
	
	virtual ~BaseEntity() {};

	virtual void render() = 0;
	virtual void step();

	void setOrigin(vector2D vecOorigin);
	void setMass(float flMass);
	void setVelocity(vector2D vecVelocity);
	void setGravity(float flGravity);
	
	void setAngle(float flAngle);
	
	virtual int getShape() { return SHAPE_NONE; }

	void setAngleVelocity(float flAngleVelocity);

	vector2D origin, angle, velocity, acceleration, normal;
	float inv_mass, mass, angleVelocity;
	
	float impulse, gravity;

};

#endif // BASEENTITY_H
