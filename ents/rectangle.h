#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "baseentity.h"

class RectAngle : public BaseEntity
{
public:
	RectAngle( float flSizeX, float flSizeY );
	void render();

	int m_flSizeX,m_flSizeY;
};

#endif // RECTANGLE_H
