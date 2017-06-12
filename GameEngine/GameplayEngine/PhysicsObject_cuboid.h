#pragma once
#include "AABB.h"
#include "IPhysicsObject.h"
class WorldObject_cuboid;
class PhysicsObject_cuboid : public IPhysicsObject {
	Vector3D dim;
public:
	PhysicsObject_cuboid(WorldObject_cuboid*);
	~PhysicsObject_cuboid();

	virtual void Update(float dt);
	Vector3D GetDim();
	void SetDim(float width, float length,float height);
	void SetCollisionObject();
};
