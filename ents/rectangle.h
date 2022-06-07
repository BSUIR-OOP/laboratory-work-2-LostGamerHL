#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "baseentity.h"

class RectAngle : public BaseEntity
{
public:
	RectAngle( float flSizeX = 0.f, float flSizeY = 0.f );
	void updateVerts();	
	void updateDrawInfo( vector2D *points );

	int m_flSizeX,m_flSizeY;

	float verts[8];
};

#endif // RECTANGLE_H
