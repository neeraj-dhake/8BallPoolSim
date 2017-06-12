#include "PhysicsObject_cuboid.h"
#include "WorldObject_cuboid.h"
#include "../InputLib_Win/InputHandler.h"


PhysicsObject_cuboid::PhysicsObject_cuboid(WorldObject_cuboid* par) {
	parent = par;
	collision_object = new AABB();
}

PhysicsObject_cuboid::~PhysicsObject_cuboid() {}

Vector3D PhysicsObject_cuboid::GetDim() {
	return dim;
}

void PhysicsObject_cuboid::SetDim(float width, float length, float height) {
	dim.x = width, dim.y = length, dim.z = height;
}

void PhysicsObject_cuboid::SetCollisionObject() {
	((AABB*)collision_object)->center = data.position;
	((AABB*)collision_object)->dimensions = dim;
}
