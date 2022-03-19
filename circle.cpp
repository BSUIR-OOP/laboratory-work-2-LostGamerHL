#include "circle.h"
#include <GL/gl.h>
#include <GLES3/gl32.h>
#include <QDragLeaveEvent>
#include "entity_list.h"
#include <math.h>
#include "baseentity.h"

#define N_TRIANGLES 32

Circle::Circle( float radius ) : BaseEntity()
{
	this->radius = radius;
}

void Circle::render()
{
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

	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_COLOR_ARRAY);
	glVertexPointer(2, GL_FLOAT, 6*4, verts);
	glColorPointer(4, GL_FLOAT, 6*4, &verts[2]);
	glDrawArrays(GL_TRIANGLE_FAN, 0, N_TRIANGLES);
	glDisableClientState(GL_VERTEX_ARRAY);
	glDisableClientState(GL_COLOR_ARRAY);
}
