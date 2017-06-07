#include "BodyData.h"
#include <math.h>
#pragma once
class PhysicsEngine
{
public:
	PhysicsEngine();
	~PhysicsEngine();

	bool DetectCollision(Vector3D v1,Vector3D v2,Vector3D dim1, Vector3D dim2);	// cuboid with cuboid
	void CollisionResponse(BodyData &obj1, BodyData &obj2);

	void impulseX(Vector3D &v,float vel);	// used by collision reponse
	void impulseY(Vector3D &v, float vel);	// used by collision reponse
	void impulseZ(Vector3D &v, float vel);	// used by collision reponse
};

