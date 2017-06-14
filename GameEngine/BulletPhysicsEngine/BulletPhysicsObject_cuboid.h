#pragma once
#include "IBulletPhysicsObject.h"
class WorldObject_cuboid;
class BulletPhysicsObject_cuboid : public IBulletPhysicsObject {
	Vector3D dim;
public:
	BulletPhysicsObject_cuboid(WorldObject_cuboid*);
	Vector3D GetDim();
	void SetDim(float width, float length,float height);
	void SetCollisionObject();
	~BulletPhysicsObject_cuboid();
};

