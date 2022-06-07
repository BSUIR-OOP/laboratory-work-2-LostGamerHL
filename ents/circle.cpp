#include "circle.h"
#include <math.h>
#include "baseentity.h"
#include <QOpenGLContext>
#include <QOpenGLFunctions_2_1>

Circle::Circle( float radius ) : BaseEntity()
{
	printf("Hello, i am circle!\n");
	this->radius = radius;
	renderInfo.count = N_TRIANGLES;
	renderInfo.stride = 24;
	renderInfo.vertBase = verts;	
}

void Circle::updateVerts()
{
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
}
