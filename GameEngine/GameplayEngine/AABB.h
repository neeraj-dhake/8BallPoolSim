#include "Vector3D.h"
#include "ICollisionObject.h"
#pragma once
struct AABB : public ICollisionObject {
	Vector3D dimensions;
	float GetNearestDistance(Vector3D*) const;
};
