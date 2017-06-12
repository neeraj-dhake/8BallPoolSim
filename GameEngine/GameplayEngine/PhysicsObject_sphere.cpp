#include "PhysicsObject_sphere.h"
#include "WorldObject_sphere.h"


PhysicsObject_sphere::PhysicsObject_sphere(WorldObject_sphere* par) {
	parent = par;
}

void PhysicsObject_sphere::Update(float dt) {
	if (!data.isFixed)
	{
		AddVelocity(getAcc().x*data.dt, getAcc().y*data.dt, getAcc().z*data.dt);
		SetVelocity(getVel().x*data.friction.x, getVel().y*data.friction.y, getVel().z*data.friction.z);
		AddPosition(getVel().x*data.dt, getVel().y*data.dt, getVel().z*data.dt);
	}
	parent->SetCoordinates(data.position.x, data.position.y, data.position.z);
	((PhysicsObject_sphere*)parent->GetpObject())->SetSphere();
}

void PhysicsObject_sphere::SetSphere() {
	sphere.center = data.position;
	sphere.radius = radius;
}

Sphere& PhysicsObject_sphere::GetSphere() {
	return sphere;
}

float PhysicsObject_sphere::GetRadius() {
	return radius;
}

PhysicsObject_sphere::~PhysicsObject_sphere() {
}
