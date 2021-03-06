#pragma once
#include "IWorldObject.h"

class WorldObject_sphere : public IWorldObject {
protected:
	float radius;
public:
	WorldObject_sphere(property, std::string address_ = "PoolBall.blend_yellow.x");
	float GetRadius();
	void SetRadius(float x);
	void CreateObject(BulletWorld*);

	~WorldObject_sphere();
};

