#pragma once
#include "IBulletPhysicsObject.h"
class BulletPhysicsObject_plane : public IBulletPhysicsObject {
public:
	BulletPhysicsObject_plane();
	void SetCollisionObject();
	~BulletPhysicsObject_plane();
};

