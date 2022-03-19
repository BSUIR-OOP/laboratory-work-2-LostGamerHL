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
		angularVelocity = 0.f;
		is_static = false;
	}

	virtual ~BaseEntity() {};

	virtual void render() = 0;
	virtual void step();

	void setOrigin(vector2D vecOorigin); // set entity position
	void setMass(float flMass); // set entity mass
	void setVelocity(vector2D vecVelocity); // set entity speed
	void setGravity(float flGravity); // set entity mass
	void ApplyImpulse( vector2D vecImpulse ); // apply impulse to entity
	void setStatic( bool flag ); // Makes entity unmovable(static)


	void setAngle(float flAngle);

	virtual int getShape() { return SHAPE_NONE; } // get physics shape

	void setAngularVelocity(float flAngularVelocity);

	vector2D origin, angle, velocity, acceleration, normal;
	float inv_mass, mass, angularVelocity;

	vector2D impulse;

	float gravity;
	bool is_static;
};

#endif // BASEENTITY_H
