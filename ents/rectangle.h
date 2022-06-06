#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "baseentity.h"

class RectAngle : public BaseEntity
{
public:
	RectAngle( float flSizeX, float flSizeY );
	void updateVerts();	

	int m_flSizeX,m_flSizeY;

	float verts[8];
};

#endif // RECTANGLE_H
