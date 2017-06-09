#pragma once
#include "IWorldObject.h"
class WorldObject_sphere : public IWorldObject {
protected:
	float radius;
public:
	WorldObject_sphere();
	float GetRadius();
	~WorldObject_sphere();
};

