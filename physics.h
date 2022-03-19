#ifndef PHYSICS_H
#define PHYSICS_H

#include "baseentity.h"
#include "circle.h"
#include "rectangle.h"

class Physics;
typedef void (Physics::*PhysCallback)( BaseEntity *a, BaseEntity *b ); // Member function pointer

#define CB(a) (PhysCallback)&Physics::a

struct PhysicsContacts
{
	PhysicsContacts( BaseEntity *a, BaseEntity *b )
	{
		this->a = a; this->b = b;
	}
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

	void Process( BaseEntity *a, BaseEntity *b )
	{
		PhysCallback callback = PhysicsCallbacks[a->getShape()][b->getShape()];
		(this->*callback)(a, b);
	}
	
	PhysCallback PhysicsCallbacks[2][2];
};

#endif // PHYSICS_H
