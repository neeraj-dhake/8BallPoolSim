#include "PhysicsObject_cuboid.h"
#include "WorldObject_cuboid.h"
#include "../InputLib_Win/InputHandler.h"


PhysicsObject_cuboid::PhysicsObject_cuboid(WorldObject_cuboid* par) {
	parent = par;
	collision_object = new AABB();
}

PhysicsObject_cuboid::~PhysicsObject_cuboid() {}

void PhysicsObject_cuboid::Update(float dt) {
	if (!data.isFixed) 	{
		AddVelocity(getAcc().x*data.dt, getAcc().y*data.dt, getAcc().z*data.dt);
		SetVelocity(getVel().x*data.friction.x, getVel().y*data.friction.y, getVel().z*data.friction.z);
		AddPosition(getVel().x*data.dt, getVel().y*data.dt, getVel().z*data.dt);

		AddAngularVelocity(getAlpha().x*data.dt, getAlpha().y*data.dt, getAlpha().z*data.dt);
		AddTheta(getOmega().x*data.dt, getOmega().y*data.dt, getOmega().z*data.dt);
	}

	parent->SetCoordinates(data.position);
	SetCollisionObject();

}

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
