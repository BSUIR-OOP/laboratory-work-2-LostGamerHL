#include "rectangle.h"
#include <GL/gl.h>
#include <GLES3/gl32.h>
#include <QDragLeaveEvent>
#include "entity_list.h"
#include <math.h>
#include "baseentity.h"

Rectangle::Rectangle(  float flSizeX, float flSizeY  ) : BaseEntity()
{
	m_flSizeX = flSizeX;
	m_flSizeY = flSizeY;
}

void Rectangle::render()
{
	vector2D vecReal1 = origin;
	vector2D vecReal2 = vector2D( m_flSizeX + origin.x, m_flSizeY + origin.y );
	
	float verts[] = {
		vecReal1.x, vecReal1.y,
		vecReal1.x, vecReal2.y,
		vecReal2.x, vecReal2.y,
		vecReal2.x, vecReal1.y
	};

	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_COLOR_ARRAY);
	glVertexPointer(2, GL_FLOAT, 0, verts);
	glColorPointer(2, GL_FLOAT, 0, verts);
	glDrawArrays(GL_TRIANGLE_FAN, 0, 4);
	glDisableClientState(GL_VERTEX_ARRAY);
	glDisableClientState(GL_COLOR_ARRAY);
}
