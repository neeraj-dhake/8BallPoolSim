#include "IWorldObject.h"
#include "IBulletPhysicsObject.h"
IBulletPhysicsObject::IBulletPhysicsObject() {

}

IBulletPhysicsObject::~IBulletPhysicsObject()
{}

void IBulletPhysicsObject::SetVelocity(Vector3D _velocity) {
}

void IBulletPhysicsObject::SetFriction(Vector3D _friction) {
}

void IBulletPhysicsObject::SetPosition(Vector3D _position) {
}

void IBulletPhysicsObject::SetAccelera(Vector3D _acc) {
}

void IBulletPhysicsObject::AddVelocity(Vector3D _velocity) {
}

void IBulletPhysicsObject::AddPosition(Vector3D _pos) {
}

void IBulletPhysicsObject::AddAccelera(Vector3D _acc) {
}

void IBulletPhysicsObject::SetAngularVelocity(Vector3D _angv) {
}

void IBulletPhysicsObject::SetAngularAccelera(Vector3D _angacc) {
}

void IBulletPhysicsObject::SetTheta(Vector3D _theta) {
}

void IBulletPhysicsObject::AddTheta(Vector3D _theta) {
}

void IBulletPhysicsObject::AddAngularVelocity(Vector3D _angv) {
}

void IBulletPhysicsObject::AddAngularAccelera(Vector3D _angacc) {
}


Vector3D IBulletPhysicsObject::getPos() {
	return Vector3D();
}

Vector3D IBulletPhysicsObject::getVel() {
	return Vector3D();
}

Vector3D IBulletPhysicsObject::getAcc() {
	return Vector3D();
}

Vector3D IBulletPhysicsObject::getTheta() {
	return Vector3D();
}

Vector3D IBulletPhysicsObject::getOmega() {
	return Vector3D();
}

Vector3D IBulletPhysicsObject::getAlpha() {
	return Vector3D();
}



void IBulletPhysicsObject::Update(float dt) {
	
}
