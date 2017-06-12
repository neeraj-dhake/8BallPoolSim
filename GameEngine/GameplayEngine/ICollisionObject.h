#pragma once
#include "Vector3D.h"
struct ICollisionObject {
	Vector3D center;
	virtual float GetNearestDistance(Vector3D*) const = 0;
};

