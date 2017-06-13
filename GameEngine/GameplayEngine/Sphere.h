#pragma once
#include "Vector3D.h"
#include "ICollisionObject.h"
struct Sphere : public ICollisionObject {
	float radius;
	float GetNearestDistance(Vector3D*) const;
};