#include "WorldObject_sphere.h"
#include "BulletPhysicsObject_sphere.h"
#include "../RenderingEngine/GraphicsObject_sphere.h"


WorldObject_sphere::WorldObject_sphere(property property_) {
	gObject = new GraphicsObject_sphere(this);
	prp = property_;
}


WorldObject_sphere::~WorldObject_sphere() {
}

float WorldObject_sphere::GetRadius() {
	return radius;
}

void WorldObject_sphere::SetRadius(float r) {
	radius = r;
}

void WorldObject_sphere::CreateObject(BulletWorld* PhyWorld_) {
	pObject = PhyWorld_->AddObject(Sphere, prp, this);
}
