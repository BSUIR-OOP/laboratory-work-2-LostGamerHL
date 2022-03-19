#ifndef CCIRCLE_H
#define CCIRCLE_H

#include "baseentity.h"
#include "vector.h"

class Circle : public BaseEntity
{
public:
	Circle( float radius = 10.f );
	
	void render();
	void collide();
	int getShape() { return SHAPE_CIRCLE; }
	
	float radius;
};

#endif // CCIRCLE_H
