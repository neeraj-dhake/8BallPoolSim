#include "WorldObject_sphere.h"
#include "PhysicsObject_sphere.h"
#include "../RenderingEngine/GraphicsObject_sphere.h"


WorldObject_sphere::WorldObject_sphere() {
	pObject = new PhysicsObject_sphere(this);
	gObject = new GraphicsObject_sphere(this);
}


WorldObject_sphere::~WorldObject_sphere() {
}

float WorldObject_sphere::GetRadius() {
	return radius;
}

void WorldObject_sphere::SetRadius(float r) {
	radius = r;
	((PhysicsObject_sphere*)(pObject))->SetRadius(radius);
	((PhysicsObject_sphere*)(pObject))->SetCollisionObject();
}

Sphere* WorldObject_sphere::GetSphere() {
	return (Sphere*)((PhysicsObject_sphere*)(pObject))->GetCollisionObject();
}