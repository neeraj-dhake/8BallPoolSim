#pragma once
#include "IWorldObject.h"

class WorldObject_cuboid : public IWorldObject {
protected:
	float width, height, depth;
public:
	WorldObject_cuboid(property, bool need_graphics = true);
	Vector3D GetDim();
	void CreateObject(BulletWorld*);
	void SetDim(float, float, float);
	~WorldObject_cuboid();
};

