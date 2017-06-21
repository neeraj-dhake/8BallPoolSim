#pragma once
#include "../BulletPhysicsEngine/IBulletPhysicsObject.h"
class WorldObject_pool;
class BulletPhysicsObject_pool :	public IBulletPhysicsObject {
public:
	BulletPhysicsObject_pool(WorldObject_pool*);
	void SetCollisionObject();
	~BulletPhysicsObject_pool();
};

