#pragma once
#include "IWorldObject.h"
#include "AABB.h"
class WorldObject_cuboid : public IWorldObject {
protected:
	float width, height, depth;
public:
	WorldObject_cuboid();
	Vector3D GetDim();
	AABB GetAABB();
	void SetDim(float, float, float);
	~WorldObject_cuboid();
};

