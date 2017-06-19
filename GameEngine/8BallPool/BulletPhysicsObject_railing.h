#pragma once
#include "../BulletPhysicsEngine/IBulletPhysicsObject.h"
class WorldObject_railing;
class BulletPhysicsObject_railing :	public IBulletPhysicsObject {
public:
	BulletPhysicsObject_railing(WorldObject_railing*);
	void SetCollisionObject();
	~BulletPhysicsObject_railing();
};

