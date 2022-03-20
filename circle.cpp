#include "circle.h"
#include <math.h>
#include "baseentity.h"
#include <QOpenGLContext>
#include <QOpenGLFunctions_2_1>

#define N_TRIANGLES 15

Circle::Circle( float radius ) : BaseEntity()
{
	this->radius = radius;
}

void Circle::render()
{
	QOpenGLFunctions_2_1 *qGL = QOpenGLContext::currentContext()->versionFunctions<QOpenGLFunctions_2_1>();
	
	float verts[6*N_TRIANGLES];	
	
	for(int i = 0; i < N_TRIANGLES; i++)
	{
		float t = float(i)/N_TRIANGLES*2*M_PI;
	
		verts[i*6] = sin(t)*radius+origin.x;
		verts[i*6+1] = cos(t)*radius+origin.y;

		verts[i*6+2] = cos(t)*0.5f+0.5f;
		verts[i*6+3] = cos(t+2)*0.5f+0.5f;
		verts[i*6+4] = cos(t+4)*0.5f+0.5f;
		verts[i*6+5] = 1;
	}

	qGL->glEnableClientState(GL_VERTEX_ARRAY);
	qGL->glEnableClientState(GL_COLOR_ARRAY);
	qGL->glVertexPointer(2, GL_FLOAT, 6*4, verts);
	qGL->glColorPointer(4, GL_FLOAT, 6*4, &verts[2]);
	qGL->glDrawArrays(GL_TRIANGLE_FAN, 0, N_TRIANGLES);
	qGL->glDisableClientState(GL_VERTEX_ARRAY);
	qGL->glDisableClientState(GL_COLOR_ARRAY);
}
