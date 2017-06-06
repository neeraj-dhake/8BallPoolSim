#pragma once
#include "IWorldObject.h"
class WorldObject_cuboid : public IWorldObject {
protected:
	float width, height, depth;
public:
	WorldObject_cuboid();
	Vector3D GetDim();
	void SetDim(float, float, float);
	~WorldObject_cuboid();
};

