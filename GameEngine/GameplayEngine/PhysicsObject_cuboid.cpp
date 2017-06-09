#include "PhysicsObject_cuboid.h"
#include "WorldObject_cuboid.h"
#include "../InputLib_Win/InputHandler.h"


PhysicsObject_cuboid::PhysicsObject_cuboid(WorldObject_cuboid* par)
{
	parent = par;
}


PhysicsObject_cuboid::~PhysicsObject_cuboid()
{}

void PhysicsObject_cuboid::Update(float dt)
{
	if (!data.isFixed)
	{
		AddVelocity(getAcc().x*data.dt, getAcc().y*data.dt, getAcc().z*data.dt);
		SetVelocity(getVel().x*data.friction.x, getVel().y*data.friction.y, getVel().z*data.friction.z);
		AddPosition(getVel().x*data.dt, getVel().y*data.dt, getVel().z*data.dt);
	}
	// can be improved as we progress ------- deoending on the features needed


	// set parent -> coordinates
	parent->SetCoordinates(data.position.x,data.position.y,data.position.z);
	((PhysicsObject_cuboid*)parent->GetpObject())->SetAABB();

}

Vector3D PhysicsObject_cuboid::GetDim()
{
	return dim;
}

void PhysicsObject_cuboid::SetDim(float width, float length, float height)
{
	dim.x = width, dim.y = length, dim.z = height;
}

void PhysicsObject_cuboid::SetAABB()
{
	aabb.min.x = data.position.x - dim.x/2, aabb.min.y = data.position.y - dim.y/2, aabb.min.z = data.position.z - dim.z/2;
	aabb.max.x = data.position.x + dim.x/2, aabb.max.y = data.position.y + dim.y/2, aabb.max.z = data.position.z + dim.z/2;
}


AABB PhysicsObject_cuboid::GetAABB()
{
	return aabb;
}
