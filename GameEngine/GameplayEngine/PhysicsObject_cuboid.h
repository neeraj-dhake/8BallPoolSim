#pragma once
#include "AABB.h"
#include "IPhysicsObject.h"
class PhysicsObject_cuboid : public IPhysicsObject
{
public:
	PhysicsObject_cuboid();
	~PhysicsObject_cuboid();

	virtual void Update();
	Vector3D GetDim();
	void SetDim(float width, float length,float height);
	void SetAABB();
	AABB GetAABB();

private:
	Vector3D dim;
	AABB aabb;
};

