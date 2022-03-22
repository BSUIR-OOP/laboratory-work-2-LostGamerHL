#include "physics.h"
#include "entity_list.h"
#include <math.h>

void Physics::Process( EntityList *entities )
{
	contacts.clear();

	for( int i = 0; i < entities->getCount(); i++ )
	{
		for( int j = i+1; j < entities->getCount(); j++ )
		{
			BaseEntity *a = (*entities)[i];
			BaseEntity *b = (*entities)[j];
			PhysCallback callback = PhysicsCallbacks[a->getShape()][b->getShape()];
			(this->*callback)(a, b);
		}
	}

	for( int i = 0; i < contacts.length(); i++ )
	{
		PhysicsContact *contact = contacts[i];		
		BaseEntity *a = contact->a;
		BaseEntity *b = contact->b;
		
		vector2D rv = b->velocity - a->velocity;
	  
		float projVelocity = contact->normal.scalar(rv);
		
		if( projVelocity > 0 ) continue;
		
		float j = -1.8f*projVelocity;
		j /= a->inv_mass + b->inv_mass;
		vector2D impulse = contact->normal * j;
		a->ApplyImpulse(-impulse);
		b->ApplyImpulse(impulse);
	}

	for( int i = 0; i < entities->getCount(); i++ )
	{
		BaseEntity *a = (*entities)[i];
		a->origin += a->velocity;
		vector2D accel( a->acceleration.x, a->acceleration.y - a->gravity*a->mass );
		a->velocity += accel;
	}
	
	for( int i = 0; i < contacts.length(); i++ )
	{
		PhysicsContact *contact = contacts[i];
		BaseEntity *a = contact->a;
		BaseEntity *b = contact->b;
		
		const float k_slop = 0.01f; // Penetration allowance
		const float percent = 0.7f;
		
		vector2D correction = contact->normal*percent*(std::max(contact->penetration-k_slop, 0.0f) / (a->inv_mass+b->inv_mass));

		a->origin -= correction * a->inv_mass;
		b->origin += correction * b->inv_mass;
	}
}

void Physics::CircleWithCircle( Circle *a, Circle *b )
{
	vector2D dist = b->origin - a->origin;
	if( a->radius + b->radius < dist.length() )
		return;

	vector2D normal = dist.normalize();

	PhysicsContact *contact = new PhysicsContact( a, b );
	contact->normal = normal;
	contact->penetration = a->radius + b->radius - dist.length();
	contacts.enqueue(contact);
}

bool isInAABB( vector2D point, AABB box )
{
	if( point.x < box.min.x || point.x > box.max.x ) return false;
	if( point.y < box.min.y || point.y > box.max.y ) return false;

	return true;
}

#define clamp( val, min, max ) ( ((val) > (max)) ? (max) : ( ((val) < (min)) ? (min) : (val) ) )

void Physics::CircleWithRectangle( Circle *a, RectAngle *b )
{
	AABB box = b->getAABB();
	
	vector2D aabb_half( b->m_flSizeX/2.f, b->m_flSizeY/2.f );
	vector2D aabb_center((box.min.x + box.max.x)/2, (box.min.y + box.max.y)/2);
	vector2D diff = a->origin - aabb_center;

	vector2D clamped( clamp( diff.x, -aabb_half.x, aabb_half.x ), clamp( diff.y, -aabb_half.y, aabb_half.y ) );
	vector2D closest = aabb_center + clamped;

	diff = closest - a->origin;

	if( diff.length() < a->radius )
	{
		PhysicsContact *contact = new PhysicsContact( a, b );
		contact->normal = diff.normalize();
		contact->penetration = a->radius - diff.length();
		contacts.enqueue(contact);
	}
}

void Physics::RectangleWithCircle( RectAngle *a, Circle *b )
{
	CircleWithRectangle( b, a );
}

void Physics::RectangleWithRectangle( RectAngle *a, RectAngle *b )
{

}
