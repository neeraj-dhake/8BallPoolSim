#include "PhysicsObject_sphere.h"
#include "WorldObject_sphere.h"


PhysicsObject_sphere::PhysicsObject_sphere(WorldObject_sphere* par) {
	parent = par;
	collision_object = new Sphere();
}

void PhysicsObject_sphere::Update(float dt) {
	if (!data.isFixed)
	{
		AddVelocity(getAcc().x*data.dt, getAcc().y*data.dt, getAcc().z*data.dt);
		SetVelocity(getVel().x*data.friction.x, getVel().y*data.friction.y, getVel().z*data.friction.z);
		AddPosition(getVel().x*data.dt, getVel().y*data.dt, getVel().z*data.dt);

		AddAngularVelocity(getAlpha().x*data.dt, getAlpha().y*data.dt, getAlpha().z*data.dt);
		AddTheta(getOmega().x*data.dt, getOmega().y*data.dt, getOmega().z*data.dt);
	}
	parent->SetCoordinates(data.position.x, data.position.y, data.position.z);
	SetCollisionObject();
}

void PhysicsObject_sphere::SetRadius(float _radius) {
	radius = _radius;
}

void PhysicsObject_sphere::SetCollisionObject() {
	((Sphere*)collision_object)->center = data.position;
	((Sphere*)collision_object)->radius = radius;
}

float PhysicsObject_sphere::GetRadius() {
	return radius;
}

PhysicsObject_sphere::~PhysicsObject_sphere() {
}
