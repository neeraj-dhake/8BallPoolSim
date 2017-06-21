#include "BulletPhysicsObject_pool.h"
#include "WorldObject_pool.h"


BulletPhysicsObject_pool::BulletPhysicsObject_pool(WorldObject_pool* parent_) {
	parent = parent_;
}

void BulletPhysicsObject_pool::SetCollisionObject() {
}


BulletPhysicsObject_pool::~BulletPhysicsObject_pool() {
}
