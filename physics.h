#ifndef PHYSICS_H
#define PHYSICS_H

#include "baseentity.h"
#include "circle.h"
#include "rectangle.h"
#include <QQueue>


struct EntityList;
class Physics;

typedef void (Physics::*PhysCallback)( BaseEntity *a, BaseEntity *b ); // Member function pointer

#define CB(a) (PhysCallback)&Physics::a

struct PhysicsContact
{
	PhysicsContact( BaseEntity *a, BaseEntity *b )
	{
		this->a = a; this->b = b;
		penetration = 0.f;
	}

	float penetration;
	vector2D normal;
	BaseEntity *a, *b;
};

class Physics
{
public:
	
	Physics()
	{
		// Не самый лучший способ так заполнять таблицу, да
		PhysicsCallbacks[0][0] = CB(CircleWithCircle); PhysicsCallbacks[0][1] = CB(CircleWithRectangle);
		PhysicsCallbacks[1][0] = CB(RectangleWithCircle);  PhysicsCallbacks[1][1] = CB(CircleWithRectangle);
	}
	
	void CircleWithCircle( Circle *body, Circle *body2 );
	void CircleWithRectangle( Circle *body, Rectangle *body2 );
	void RectangleWithCircle( Rectangle *body, Circle *body2 );
	void RectangleWithRectangle( Rectangle *body, Rectangle *body2 ); // sus
	void Process( EntityList *entitites );

	void Frame( void );
	
	PhysCallback PhysicsCallbacks[2][2];
	QQueue<PhysicsContact*> contacts;
};

#endif // PHYSICS_H
