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

	if (!isFixed)
	{
		SetVelocity(getAcc().x*dt, getAcc().y*dt, getAcc().z*dt);
		SetPosition(getVel().x*dt, getVel().y*dt, getVel().z*dt);
	}
	// can be improved as we progress ------- deoending on the features needed

}
