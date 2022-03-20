#ifndef ENTITY_LIST_H
#define ENTITY_LIST_H

#include "baseentity.h"
#include "physics.h"
#include <malloc.h>

struct EntityList
{
	EntityList( int iMaxEntityNumber = 1024 )
	{
		maxEntityNumber = iMaxEntityNumber;
		entityCount = 0;
		if( maxEntityNumber > 0 )
			entities = new BaseEntity*[iMaxEntityNumber];
		physicsController = new Physics;
	}
	
	~EntityList()
	{
		if( maxEntityNumber > 0 )
			delete entities;
		if( physicsController )
			delete physicsController;
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
			entities[i]->render();
	}
	
	void processPhysics()
	{
		physicsController->Process(this);
	}

	int entityCount;
	int maxEntityNumber;
	BaseEntity **entities;
	
	Physics *physicsController;
};

#endif // ENTITY_LIST_H
