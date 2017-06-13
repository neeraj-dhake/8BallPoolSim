#pragma once
#include "IPhysicsObject.h"
#include "Sphere.h"
class WorldObject_sphere;
class PhysicsObject_sphere : public IPhysicsObject {
	float radius;
public:
	PhysicsObject_sphere(WorldObject_sphere*);
	float GetRadius();
	void SetRadius(float);
	void SetCollisionObject();
	~PhysicsObject_sphere();
};

