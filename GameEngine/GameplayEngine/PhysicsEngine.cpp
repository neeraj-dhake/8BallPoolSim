#include "PhysicsEngine.h"



PhysicsEngine::PhysicsEngine() {
}


PhysicsEngine::~PhysicsEngine() {
}

void PhysicsEngine::CollisionResponse(BodyData &obj1, BodyData &obj2) {
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
	int x = 1;


}
inline float max(float x, float y) {
	return (x > y) ? x : y;
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

bool PhysicsEngine::DetectCollision(const AABB &a,const AABB &b) {	// pass it by reference if you wantmaxX to avoid writing copy constructor
	if ((a.min.x <= b.max.x && a.max.x >= b.min.x) &&
		(a.min.y <= b.max.y && a.max.y >= b.min.y) &&
		(a.min.z <= b.max.z && a.max.z >= b.min.z))
		return true;
	else return false;
}

bool PhysicsEngine::DetectCollision(const AABB &a, const Sphere &b) {
	Vector3D a_center = (a.max + a.min) / 2;
	Vector3D ray = b.center - a_center;
	ray = ray / Vector3D::Magnitude(ray);
	if (Vector3D::Magnitude(a_center - b.center) <= (a.nearest_distance(ray) + b.radius)) {
		return true;
	}
	return false;
}

bool PhysicsEngine::DetectCollision(const Sphere &a, const Sphere &b) {
	if (Vector3D::Magnitude(a.center - b.center) <= (a.radius + b. radius)) {
		return true;
	}
	else return false;
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



