#include "IWorldObject.h"
#include "IPhysicsObject.h"
IPhysicsObject::IPhysicsObject() {
	data.dt = 0.016f;
	data.position = Vector3D(0, 0, 0);
	data.friction = Vector3D(0.98f, 0.98f, 0.98f);
	data.velocity = Vector3D(0, 0, 0);
	data.accelera = Vector3D(0, 0, 0);
	data.theta = Vector3D(0, 0, 0);
	data.angular_velocity = Vector3D(0, 0, 0);
	data.angular_accelera = Vector3D(0, 0, 0);


	data.onGroundX = false; data.onGroundY = false; data.onGroundZ = false;
	data.restitution = 0.9999999f, data.invMass = 1.0f;
}

IPhysicsObject::~IPhysicsObject()
{}

void IPhysicsObject::SetVelocity(Vector3D _velocity) {
	data.velocity = _velocity;
}

void IPhysicsObject::SetFriction(Vector3D _friction) {
	data.friction = _friction;
}

void IPhysicsObject::SetPosition(Vector3D _position) {
	data.position = _position;
}

void IPhysicsObject::SetAccelera(Vector3D _acc) {
	data.accelera = _acc;
}

void IPhysicsObject::AddVelocity(Vector3D _velocity) {
	data.velocity += _velocity;
}

void IPhysicsObject::AddPosition(Vector3D _pos) {
	data.position += _pos;
}

void IPhysicsObject::AddAccelera(Vector3D _acc) {
	data.accelera += _acc;
}

void IPhysicsObject::SetAngularVelocity(Vector3D _angv) {
	data.angular_velocity = _angv;
}

void IPhysicsObject::SetAngularAccelera(Vector3D _angacc) {
	data.angular_accelera = _angacc;
}

void IPhysicsObject::SetTheta(Vector3D _theta) {
	data.theta = _theta;
}

void IPhysicsObject::AddTheta(Vector3D _theta) {
	data.theta += _theta;
}

void IPhysicsObject::AddAngularVelocity(Vector3D _angv) {
	data.angular_velocity += _angv;
}

void IPhysicsObject::AddAngularAccelera(Vector3D _angacc) {
	data.angular_accelera += _angacc;
}


Vector3D IPhysicsObject::getPos() {
	return data.position;
}

Vector3D IPhysicsObject::getVel() {
	return data.velocity;
}

Vector3D IPhysicsObject::getAcc() {
	return data.accelera;
}

Vector3D IPhysicsObject::getTheta() {
	return data.theta;
}

Vector3D IPhysicsObject::getOmega() {
	return data.angular_velocity;
}

Vector3D IPhysicsObject::getAlpha() {
	return data.angular_accelera;
}

BodyData& IPhysicsObject::GetData() {
	return data;
}

ICollisionObject * IPhysicsObject::GetCollisionObject() {
	return collision_object;
}

void IPhysicsObject::Update(float dt) {
	if (!data.isFixed) {
		AddVelocity(getAcc()*data.dt);
		SetVelocity(getVel()*data.friction);
		AddPosition(getVel()*data.dt);

		AddAngularVelocity(getAlpha()*data.dt);
		AddTheta(getOmega()*data.dt);
	}

	parent->SetCoordinates(data.position);
	SetCollisionObject();
}
