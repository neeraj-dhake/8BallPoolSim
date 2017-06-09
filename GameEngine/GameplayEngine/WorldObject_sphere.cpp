#include "WorldObject_sphere.h"
#include "PhysicsObject_sphere.h"


WorldObject_sphere::WorldObject_sphere() {
}


WorldObject_sphere::~WorldObject_sphere() {
}

float WorldObject_sphere::GetRadius() {
	return radius;
}

void WorldObject_sphere::SetRadius(float r) {
	radius = r;
}

Sphere WorldObject_sphere::GetSphere() {
	return ((PhysicsObject_sphere*)(pObject))->GetSphere();
}