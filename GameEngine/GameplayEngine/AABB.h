#include "Vector3D.h"
#pragma once
struct AABB {
	Vector3D min;
	Vector3D max;
	Vector3D center;
	Vector3D dimensions;
	Vector3D GetIntersection_Ray_Plane(Vector3D, Vector3D) const;
	float nearest_distance(Vector3D) const;
};
