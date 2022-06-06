#ifndef ENTITY_LIST_H
#define ENTITY_LIST_H

#include "ents/baseentity.h"
#include <malloc.h>
#include <QOpenGLContext>
#include <QOpenGLFunctions_2_1>

struct EntityList
{
	EntityList( int iMaxEntityNumber = 1024 )
	{
		maxEntityNumber = iMaxEntityNumber;
		entityCount = 0;
		if( maxEntityNumber > 0 )
			entities = new BaseEntity*[iMaxEntityNumber];
	}
	
	~EntityList()
	{
		if( maxEntityNumber > 0 )
			delete entities;
//		if( physicsController )
//			delete physicsController;
	}
	
	int getCount() { return entityCount; }
	
	BaseEntity* operator[]( int n )
	{
		if( n > entityCount )
			return nullptr;
		return entities[n];
	}

	bool addEntity(BaseEntity *entity)
	{
		if( entityCount < maxEntityNumber && maxEntityNumber > 0 )
		{
			entities[entityCount++] = entity;
			return true;
		}
		
		return false;
	}

	void render( void )
	{
		for( int i = 0; i < getCount(); i++)
		{
			RenderInfo *inf = &entities[i]->renderInfo;
			QOpenGLFunctions_2_1 *qGL = QOpenGLContext::currentContext()->versionFunctions<QOpenGLFunctions_2_1>();
		
			qGL->glEnableClientState(GL_VERTEX_ARRAY);
			qGL->glVertexPointer(2, GL_FLOAT, inf->stride, inf->vertBase);
			qGL->glDrawArrays(GL_TRIANGLE_FAN, 0, inf->count);
			qGL->glDisableClientState(GL_VERTEX_ARRAY);
		}
	}
	
	void processPhysics()
	{
		//physicsController->Process(this);
	}

	int entityCount;
	int maxEntityNumber;
	BaseEntity **entities;
};

#endif // ENTITY_LIST_H
