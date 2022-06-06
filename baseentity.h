#ifndef BASEENTITY_H
#define BASEENTITY_H

#include "vector.h"
#include <stdio.h>

#define SHAPE_COUNT 2

class BaseEntity
{
public:
	BaseEntity() {
		origin = vector2D(0, 0);
	}

	virtual ~BaseEntity() {};

	virtual void render() = 0;

	// set entity position
	void setOrigin(vector2D vecOrigin)
	{
		this->origin = vecOrigin;
	}
	
	vector2D origin;
};

#endif // BASEENTITY_H
