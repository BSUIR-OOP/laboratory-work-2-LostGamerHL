#include "physics.h"
#include <math.h>


void Physics::CircleWithCircle( Circle *body, Circle *body2 )
{
	vector2D dist = body->origin - body2->origin;
	if( body->radius + body2->radius < dist.length() )
		return;

	vector2D normal = dist.normalize();
		
	vector2D rv = body->velocity - body2->velocity;
  
	float velAlongNormal = normal.scalar(rv);
	
	if(velAlongNormal > 0)
	  return;

	float j = -velAlongNormal;
	j /= 1 / body->mass + 1 / body2->mass;
	
	vector2D impulse = normal * j;
	body->velocity += impulse * 1 / body->mass;
	body2->velocity -= impulse * 1 / body2->mass;
}

bool isInAABB( vector2D point, AABB box )
{
	if( point.x < box.min.x || point.x > box.max.x ) return false;
	if( point.y < box.min.y || point.y > box.max.y ) return false;

	return true;
}

void Physics::CircleWithRectangle( Circle *body, Rectangle *body2 )
{
	AABB box = body2->getAABB();
	
	vector2D center = vector2D( (box.min.x + box.max.x)/2, (box.min.y + box.max.y)/2 );
	
	vector2D dist = body->origin - center;
		
	if( isInAABB(body->origin, box) )
	{
		body->setOrigin(vector2D(0,700));
	}
}

void Physics::RectangleWithCircle( Rectangle *body, Circle *body2 )
{
	CircleWithRectangle( body2, body );
}

void Physics::RectangleWithRectangle( Rectangle *body, Rectangle *body2 )
{
	
}
