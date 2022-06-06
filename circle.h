#ifndef CCIRCLE_H
#define CCIRCLE_H

#include "baseentity.h"

class Circle : public BaseEntity
{
public:
	Circle( float radius = 10.f );
	
	void render();
	void collide();
	
	float radius;
};

#endif // CCIRCLE_H
