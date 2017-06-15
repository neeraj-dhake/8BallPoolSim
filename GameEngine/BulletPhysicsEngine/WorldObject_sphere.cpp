#include "WorldObject_sphere.h"
#include "BulletPhysicsObject_sphere.h"
#include "../RenderingEngine/GraphicsObject_sphere.h"


WorldObject_sphere::WorldObject_sphere() {
	//pObject = new BulletPhysicsObject_sphere(this);
	gObject = new GraphicsObject_sphere(this);
}


WorldObject_sphere::~WorldObject_sphere() {
}

float WorldObject_sphere::GetRadius() {
	return radius;
}

void WorldObject_sphere::SetRadius(float r) {
	radius = r;
	//((BulletPhysicsObject_sphere*)(pObject))->SetRadius(radius);
	//((BulletPhysicsObject_sphere*)(pObject))->SetCollisionObject();
}

void WorldObject_sphere::CreateObject(BulletWorld* PhyWorld_)
{
	pObject = PhyWorld_->AddObject(Sphere, this);
}
