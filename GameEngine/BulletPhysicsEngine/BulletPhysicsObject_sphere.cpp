#include "BulletPhysicsObject_sphere.h"
#include "WorldObject_sphere.h"


BulletPhysicsObject_sphere::BulletPhysicsObject_sphere(WorldObject_sphere* par) {
	parent = par;
}

void BulletPhysicsObject_sphere::SetRadius(float _radius) {
	radius = _radius;
}

void BulletPhysicsObject_sphere::SetCollisionObject() {

}

float BulletPhysicsObject_sphere::GetRadius() {
	return radius;
}

BulletPhysicsObject_sphere::~BulletPhysicsObject_sphere() {
}
