#include "Vector3D.h"
#include <math.h>
#pragma once
class PhysicsEngine
{
public:
	PhysicsEngine();
	~PhysicsEngine();

	bool DetectCollision(Vector3D v1,Vector3D v2,Vector3D dim1, Vector3D dim2);	// cuboid with cuboid
	bool CollisionResponse(); // to be corrected
};

