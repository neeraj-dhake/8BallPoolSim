#pragma once
#include "IBulletPhysicsObject.h"
class WorldObject_sphere;
class BulletPhysicsObject_sphere : public IBulletPhysicsObject {
	float radius;
public:
	BulletPhysicsObject_sphere(WorldObject_sphere*);
	float GetRadius();
	void SetRadius(float);
	void SetCollisionObject();
	~BulletPhysicsObject_sphere();
};

