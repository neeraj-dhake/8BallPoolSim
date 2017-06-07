#include "Vector3D.h"
#include <math.h>
#pragma once
class PhysicsEngine
{
public:
	PhysicsEngine();
	~PhysicsEngine();

	bool DetectCollision(Vector3D v1,Vector3D v2,Vector3D dim1, Vector3D dim2);	// cuboid with cuboid
	void CollisionResponse(Vector3D vel1, Vector3D vel2); 

	void impulseX(Vector3D &v,float vel);	// used by collision reponse
	void impulseY(Vector3D &v, float vel);	// used by collision reponse
	void impulseZ(Vector3D &v, float vel);	// used by collision reponse
};

