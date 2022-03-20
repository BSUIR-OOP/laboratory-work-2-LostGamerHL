#include "rectangle.h"
#include <QOpenGLContext>
#include "baseentity.h"
#include <QOpenGLFunctions_2_1>

RectAngle::RectAngle(  float flSizeX, float flSizeY  ) : BaseEntity()
{
	m_flSizeX = flSizeX;
	m_flSizeY = flSizeY;
}

void RectAngle::render()
{
	QOpenGLFunctions_2_1 *qGL = QOpenGLContext::currentContext()->versionFunctions<QOpenGLFunctions_2_1>();
	
	vector2D vecReal1 = origin;
	vector2D vecReal2 = vector2D( m_flSizeX + origin.x, m_flSizeY + origin.y );
	
	float verts[] = {
		vecReal1.x, vecReal1.y,
		vecReal1.x, vecReal2.y,
		vecReal2.x, vecReal2.y,
		vecReal2.x, vecReal1.y
	};

	qGL->glEnableClientState(GL_VERTEX_ARRAY);
	qGL->glEnableClientState(GL_COLOR_ARRAY);
	qGL->glVertexPointer(2, GL_FLOAT, 0, verts);
	qGL->glColorPointer(2, GL_FLOAT, 0, verts);
	qGL->glDrawArrays(GL_TRIANGLE_FAN, 0, 4);
	qGL->glDisableClientState(GL_VERTEX_ARRAY);
	qGL->glDisableClientState(GL_COLOR_ARRAY);
}
