#include "BulletPhysicsObject_cuboid.h"
#include "WorldObject_cuboid.h"
#include "../InputLib_Win/InputHandler.h"


BulletPhysicsObject_cuboid::BulletPhysicsObject_cuboid(WorldObject_cuboid* par) {
	parent = par;
}

BulletPhysicsObject_cuboid::~BulletPhysicsObject_cuboid() {}

Vector3D BulletPhysicsObject_cuboid::GetDim() {
	return dim;
}

void BulletPhysicsObject_cuboid::SetDim(float width, float length, float height) {
	dim.x = width, dim.y = length, dim.z = height;
}

void BulletPhysicsObject_cuboid::SetCollisionObject() {
}
