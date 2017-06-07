#include "IWorldObject.h"
#include "IPhysicsObject.h"
IPhysicsObject::IPhysicsObject()
{
	dt = 0.016f;
	position.x = 0.0f, position.y = 0.0f, position.z = 0.0f;
	friction.x = 1.0f, friction.x = 1.0f, friction.x = 1.0f;
	velocity.x = 0.0f, velocity.y = 0.0f, velocity.z = 0.0f;
	accelera.x = 0.0f, accelera.y = 0.0f, accelera.z = 0.0f;
	onGroundX = false; onGroundY = false; onGroundZ = false;
	restitution = 0.9999999f, invMass = 1.0f;

}

IPhysicsObject::~IPhysicsObject()
{}

void IPhysicsObject::SetVelocity(float vx, float vy, float vz)
{
	velocity.x = vx;	velocity.y = vy;	velocity.z = vz;
}

void IPhysicsObject::SetFriction(float fx, float fy, float fz)
{
	friction.x = fx;	friction.y = fy;	friction.z = fz;
}

void IPhysicsObject::SetPosition(float x, float y, float z)
{
	position.x = x;	position.y = y;	position.z = z;
}

void IPhysicsObject::Setaccelera(float ax, float ay, float az)
{
	accelera.x = ax;accelera.y = ay;accelera.z = az;
}

Vector3D IPhysicsObject::getPos()
{
	return position;
}

Vector3D IPhysicsObject::getVel()
{
	return velocity;
}

Vector3D IPhysicsObject::getAcc()
{
	return accelera;
}
