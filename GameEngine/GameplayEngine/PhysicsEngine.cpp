#include "PhysicsEngine.h"



PhysicsEngine::PhysicsEngine()
{
}


PhysicsEngine::~PhysicsEngine()
{
}

bool PhysicsEngine::DetectCollision(Vector3D v1, Vector3D v2, Vector3D dim1, Vector3D dim2)
{
	if ((fabs(v1.x - v2.x) <= dim1.x + dim2.x) && (fabs(v1.y - v2.y) <= dim1.y + dim2.y) && (fabs(v1.z - v2.z) <= dim1.z + dim2.z))
		return true;

	return false;
}

void PhysicsEngine::CollisionResponse(Vector3D vel1, Vector3D vel2)
{


}

void PhysicsEngine::impulseX(Vector3D & v, float vel)
{
	v.x += vel;
}

void PhysicsEngine::impulseY(Vector3D & v, float vel)
{
	v.y += vel;
}

void PhysicsEngine::impulseZ(Vector3D & v, float vel)
{
	v.z += vel;
}



