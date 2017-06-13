#include "PhysicsEngine.h"
inline float max(float x, float y) {
	return (x > y) ? x : y;
}

PhysicsEngine::PhysicsEngine() {}


PhysicsEngine::~PhysicsEngine() {}

void PhysicsEngine::CollisionResponse(BodyData &obj1, BodyData &obj2) {	/// need to change to use for rotation
	Vector3D rv = obj2.velocity - obj1.velocity;

	Vector3D normal = Vector3D::Normal(obj1.velocity - obj2.velocity);

	float velAlongNormal = Vector3D::DotProduct(normal, rv);

	if (velAlongNormal > 0)
		return;
	float e;
	if (obj1.restitution < obj2.restitution)
		e = obj1.restitution;
	else
		e = obj2.restitution;

	float j = -(1 + e) * velAlongNormal;
	j /= obj1.invMass + obj2.invMass;

	Vector3D impulse = normal*j;
	obj1.velocity -= impulse* obj1.invMass;
	obj2.velocity += impulse* obj2.invMass;


}


// to be used ------
void PositionalCorrection(BodyData obj1, BodyData obj2) {
	Vector3D normal = Vector3D::Normal(obj1.position - obj2.position);
	const float percent = 0.2f; // usually 20% to 80%
	const float slop = 0.01f; // usually 0.01 to 0.1
	Vector3D correction = normal *  max(percent - slop, 0.0f) / (obj1.invMass + obj2.invMass) * percent ;
	obj1.position -= correction*obj1.invMass;
	obj2.position += correction*obj2.invMass;
}

bool PhysicsEngine::DetectCollision(const ICollisionObject* a, const ICollisionObject* b) {
	Vector3D ray = b->center - a->center;
	ray = ray / Vector3D::Magnitude(ray);
	if (Vector3D::Magnitude(a->center - b->center) <= (a->GetNearestDistance(&ray) + b->GetNearestDistance(&(ray*(-1))))) {
		return true;
	}
	return false;
}

void PhysicsEngine::impulseX(Vector3D & v, float vel) {
	v.x += vel;
}

void PhysicsEngine::impulseY(Vector3D & v, float vel) {
	v.y += vel;
}

void PhysicsEngine::impulseZ(Vector3D & v, float vel) {
	v.z += vel;
}



