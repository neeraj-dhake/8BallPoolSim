#pragma once
#include "IWorldObject.h"
#include "Sphere.h"
class WorldObject_sphere : public IWorldObject {
protected:
	float radius;
public:
	WorldObject_sphere();
	float GetRadius();
	void SetRadius(float x);
	Sphere GetSphere();
	~WorldObject_sphere();
};

