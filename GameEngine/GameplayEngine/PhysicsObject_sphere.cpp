#include "PhysicsObject_sphere.h"
#include "WorldObject_sphere.h"


PhysicsObject_sphere::PhysicsObject_sphere(WorldObject_sphere* par) {
	parent = par;
	collision_object = new Sphere();
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
