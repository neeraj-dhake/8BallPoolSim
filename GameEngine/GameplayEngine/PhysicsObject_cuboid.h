#pragma once
#include "IPhysicsObject.h"
class PhysicsObject_cuboid : public IPhysicsObject
{
public:
	PhysicsObject_cuboid();
	~PhysicsObject_cuboid();

	virtual void Update();

private:
	float width, length, height;
};

