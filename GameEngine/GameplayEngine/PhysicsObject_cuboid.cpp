#include "PhysicsObject_cuboid.h"



PhysicsObject_cuboid::PhysicsObject_cuboid()
{
}


PhysicsObject_cuboid::~PhysicsObject_cuboid()
{
}

void PhysicsObject_cuboid::Update()
{
	// write the handlers condition over here and for the other conditions of reading input or taking decisions from AI

	if (!data.isFixed)
	{
		SetVelocity(getAcc().x*data.dt, getAcc().y*data.dt, getAcc().z*data.dt);
		SetPosition(getVel().x*data.dt, getVel().y*data.dt, getVel().z*data.dt);
	}
	// can be improved as we progress ------- deoending on the features needed

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
	aabb.min.x = data.position.x - dim.x, aabb.min.y = data.position.y - dim.y, aabb.min.z = data.position.z - dim.z;
	aabb.max.x = data.position.x + dim.x, aabb.max.y = data.position.y + dim.y, aabb.max.z = data.position.z + dim.z;
}


AABB PhysicsObject_cuboid::GetAABB()
{
	return aabb;
}
