#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "baseentity.h"

struct AABB
{
	vector2D min, max;
};

class Rectangle : public BaseEntity
{
public:
	Rectangle( float flSizeX, float flSizeY );
	void render();

	int getShape() { return SHAPE_RECTANGLE; }	
	AABB getAABB()
	{
		return {vector2D(origin.x, origin.y), vector2D(origin.x+m_flSizeX, origin.y+m_flSizeY)};
	}
	
	int m_flSizeX,m_flSizeY;
};

#endif // RECTANGLE_H
