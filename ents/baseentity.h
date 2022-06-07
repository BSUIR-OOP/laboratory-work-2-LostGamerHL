#ifndef BASEENTITY_H
#define BASEENTITY_H

#include "math/vector.h"
#include <stdio.h>


struct RenderInfo
{
	float *vertBase;
	int stride;
	int count;
};

class BaseEntity
{
public:
	BaseEntity() {
		origin = vector2D(0, 0);
		renderInfo.vertBase = NULL;
		renderInfo.count = 0;
		renderInfo.stride = 0;
	}

	virtual ~BaseEntity() {};
	virtual void updateVerts() = 0;
	virtual void updateDrawInfo( vector2D *points ) = 0;

	// set entity position
	void setOrigin(vector2D vecOrigin)
	{
		this->origin = vecOrigin;
		updateVerts();
	}
	
	RenderInfo renderInfo;
	vector2D origin;
};

#endif // BASEENTITY_H
