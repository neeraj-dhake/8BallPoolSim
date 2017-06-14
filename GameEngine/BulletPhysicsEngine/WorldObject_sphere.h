#pragma once
#include "IWorldObject.h"

class WorldObject_sphere : public IWorldObject {
protected:
	float radius;
public:
	WorldObject_sphere();
	float GetRadius();
	void SetRadius(float x);
	void Create(BulletWorld*);

	~WorldObject_sphere();
};

