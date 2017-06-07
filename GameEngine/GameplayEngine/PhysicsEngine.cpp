#include "PhysicsEngine.h"



PhysicsEngine::PhysicsEngine()
{
}


PhysicsEngine::~PhysicsEngine()
{
}

void PhysicsEngine::CollisionResponse(BodyData &obj1, BodyData &obj2)
{
	Vector3D rv = obj1.velocity - obj1.velocity;

	Vector3D normal = Vector3D::Normal(obj1.position - obj2.position);

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
	obj2.velocity += impulse* obj1.invMass;

}
inline float max(float x, float y) {
	return (x > y) ? x : y;
}

// to be used ------
void PositionalCorrection(BodyData obj1, BodyData obj2)
{
	Vector3D normal = Vector3D::Normal(obj1.position - obj2.position);
	const float percent = 0.2; // usually 20% to 80%
	const float slop = 0.01; // usually 0.01 to 0.1
	Vector3D correction = normal *  max(percent - slop, 0.0f) / (obj1.invMass + obj2.invMass) * percent ;
	obj1.position -= correction*obj1.invMass;
	obj2.position += correction*obj2.invMass;
}

bool PhysicsEngine::DetectCollision(Vector3D v1, Vector3D v2, Vector3D dim1, Vector3D dim2)
{
	if ((fabs(v1.x - v2.x) <= dim1.x + dim2.x) && (fabs(v1.y - v2.y) <= dim1.y + dim2.y) && (fabs(v1.z - v2.z) <= dim1.z + dim2.z))
		return true;

	return false;
}

bool PhysicsEngine::DetectCollision(AABB a, AABB b)
{
	if (a.max.x < b.min.x or a.min.x > b.max.x) return false;
	if (a.max.y < b.min.y or a.min.y > b.max.y) return false;

			// No separating axis found, therefor there is at least one overlapping axis
	return true;
}

void PhysicsEngine::impulseX(Vector3D & v, float vel)
{
	v.x += vel;
}

void PhysicsEngine::impulseY(Vector3D & v, float vel)
{
	v.y += vel;
}

void PhysicsEngine::impulseZ(Vector3D & v, float vel)
{
	v.z += vel;
}



