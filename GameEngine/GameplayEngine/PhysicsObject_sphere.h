#pragma once
#include "IPhysicsObject.h"
#include "Sphere.h"
class WorldObject_sphere;
class PhysicsObject_sphere : public IPhysicsObject {
	float radius;
	Sphere sphere;
public:
	PhysicsObject_sphere(WorldObject_sphere*);
	void Update(float dt);
	float GetRadius();
	void SetSphere();
	Sphere& GetSphere();
	~PhysicsObject_sphere();
};

