#include "rectangle.h"
#include <QOpenGLContext>
#include "baseentity.h"
#include <QOpenGLFunctions_2_1>

RectAngle::RectAngle(  float flSizeX, float flSizeY  ) : BaseEntity()
{
	m_flSizeX = flSizeX;
	m_flSizeY = flSizeY;
	
	renderInfo.count = 4;
	renderInfo.stride = 0;
	renderInfo.vertBase = verts;	
}

void RectAngle::updateVerts()
{
	vector2D vecReal1 = origin;
	vector2D vecReal2 = vector2D( m_flSizeX + origin.x, m_flSizeY + origin.y );

	verts[0] = vecReal1.x; verts[1] = vecReal1.y;
	verts[2] = vecReal1.x; verts[3] = vecReal2.y;
	verts[4] = vecReal2.x; verts[5] = vecReal2.y;
	verts[6] = vecReal2.x; verts[7] = vecReal1.y;
}
