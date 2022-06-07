#ifndef CCIRCLE_H
#define CCIRCLE_H

#include "baseentity.h"

#define N_TRIANGLES 32

class Circle : public BaseEntity
{
public:
	Circle( float radius = 10.f );
	
	void updateVerts();
	void updateDrawInfo( vector2D *points );
	
	float radius;
	float verts[6*N_TRIANGLES];		
};

#endif // CCIRCLE_H
