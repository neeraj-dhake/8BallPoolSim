#include "IWorldObject.h"
#include "IPhysicsObject.h"
IPhysicsObject::IPhysicsObject()
{
	data.dt = 0.016f;
	data.position.x = 0.0f, data.position.y = 0.0f, data.position.z = 0.0f;
	data.friction.x = 0.98f, data.friction.y = 0.98f, data.friction.z = 0.98f;
	data.velocity.x = 0.0f, data.velocity.y = 0.0f, data.velocity.z = 0.0f;
	data.accelera.x = 0.0f, data.accelera.y = 0.0f, data.accelera.z = 0.0f;
	data.onGroundX = false; data.onGroundY = false; data.onGroundZ = false;
	data.restitution = 0.9999999f, data.invMass = 1.0f;

}

IPhysicsObject::~IPhysicsObject()
{}

void IPhysicsObject::SetVelocity(float vx, float vy, float vz)
{
	data.velocity.x = vx;	data.velocity.y = vy;	data.velocity.z = vz;
}

void IPhysicsObject::SetFriction(float fx, float fy, float fz)
{
	data.friction.x = fx;	data.friction.y = fy;	data.friction.z = fz;
}

void IPhysicsObject::SetPosition(float x, float y, float z)
{
	data.position.x = x;	data.position.y = y;	data.position.z = z;
}

void IPhysicsObject::SetAccelera(float ax, float ay, float az)
{
	data.accelera.x = ax;data.accelera.y = ay;data.accelera.z = az;
}

void IPhysicsObject::AddVelocity(float vx, float vy, float vz)
{
	data.velocity.x += vx;	data.velocity.y += vy;	data.velocity.z += vz;
}

void IPhysicsObject::AddPosition(float x, float y, float z)
{
	data.position.x += x;	data.position.y += y;	data.position.z += z;
}

void IPhysicsObject::AddAccelera(float ax, float ay, float az)
{
	data.accelera.x += ax;data.accelera.y += ay;data.accelera.z += az;
}


Vector3D IPhysicsObject::getPos()
{
	return data.position;
}

Vector3D IPhysicsObject::getVel()
{
	return data.velocity;
}

Vector3D IPhysicsObject::getAcc()
{
	return data.accelera;
}

BodyData& IPhysicsObject::GetData()
{
	return data;
}
