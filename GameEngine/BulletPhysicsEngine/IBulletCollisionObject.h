#pragma once
#include "../BulletPhysicsEngine/Vector3D.h"
struct IBulletCollisionObject {
	Vector3D center;
	virtual float GetNearestDistance(Vector3D*) const = 0;
};

