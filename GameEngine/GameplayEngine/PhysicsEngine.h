#include "BodyData.h"
#include "AABB.h"
#include "Sphere.h"
#include <math.h>
#pragma once
class PhysicsEngine
{
public:
	PhysicsEngine();
	~PhysicsEngine();
	bool DetectCollision(const AABB&,const AABB&);
	bool DetectCollision(const AABB&, const Sphere&);
	bool DetectCollision(const Sphere&, const Sphere&);
	void CollisionResponse(BodyData &obj1, BodyData &obj2);

	void impulseX(Vector3D &v,float vel);	// used by collision reponse
	void impulseY(Vector3D &v, float vel);	// used by collision reponse
	void impulseZ(Vector3D &v, float vel);	// used by collision reponse
};

