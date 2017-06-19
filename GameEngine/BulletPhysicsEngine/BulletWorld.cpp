#include "BulletWorld.h"
#include "WorldObject_cuboid.h"
#include "WorldObject_sphere.h"
#include "../8BallPool/WorldObject_railing.h"

BulletWorld::BulletWorld() {
	collisionConfiguration = new btDefaultCollisionConfiguration();
	dispatcher = new btCollisionDispatcher(collisionConfiguration);
	overlappingPairCache = new btDbvtBroadphase();
	solver = new btSequentialImpulseConstraintSolver;
	dynamicsWorld = new btDiscreteDynamicsWorld(dispatcher, overlappingPairCache, solver, collisionConfiguration);

	dynamicsWorld->setGravity(btVector3(0, -10, 0));
}

void BulletWorld::update() {
	dynamicsWorld->stepSimulation(1.f / 60.f, 10);
}

btRigidBody* BulletWorld::AddObject(TypeOfObject type, property prp, void* parent) {
	btCollisionShape* Shape;
	switch (type) {
		case Cuboid: {
			Vector3D HalfDim = ((WorldObject_cuboid*)parent)->GetDim() / 2.0f;
			Shape = new btBoxShape(HalfDim.to_btVector3());
			break;
		}
		case Sphere: {
			float radius = ((WorldObject_sphere*)parent)->GetRadius();
			Shape = new btSphereShape(radius);
			break;
		}
		case Railing: {
			btVector3* points = ((WorldObject_railing*)parent)->GetPoints();
			int num = ((WorldObject_railing*)parent)->GetNumPoints();
			Shape = new btConvexHullShape(points, num);
			break;
		}
		default:
			return nullptr;

	}

	btScalar mass(0);

	if (prp == STATIC)
		mass = 0;
	else if (prp == DYNAMIC)
		mass = 1.;


	Shape->setMargin(0.1);
	collisionShapes.push_back(Shape);

	Vector3D position = ((WorldObject_cuboid*)parent)->GetPos();
	btDefaultMotionState* myMotionState = new btDefaultMotionState( btTransform( btQuaternion(0, 0, 0, 1), 
																				 position.to_btVector3() ) );

	bool isDynamic = (mass != 0.f);
	btVector3 localInertia(0, 0, 0);
	if (isDynamic)
		Shape->calculateLocalInertia(mass, localInertia);

	btRigidBody::btRigidBodyConstructionInfo rbInfo(mass, myMotionState, Shape, localInertia);
	btRigidBody* body = new btRigidBody(rbInfo);
	dynamicsWorld->addRigidBody(body);
	return body;

}

btDiscreteDynamicsWorld * BulletWorld::GetDynamicWorld()
{
	return dynamicsWorld;
}

BulletWorld::~BulletWorld() {
	clean();
}

void BulletWorld::clean() {
	for (int i = dynamicsWorld->getNumCollisionObjects() - 1; i >= 0; i--) {
		btCollisionObject* obj = dynamicsWorld->getCollisionObjectArray()[i];
		btRigidBody* body = btRigidBody::upcast(obj);
		if (body && body->getMotionState()) {
			delete body->getMotionState();
		}
		dynamicsWorld->removeCollisionObject(obj);
		delete obj;
	}

	for (int j = 0; j < collisionShapes.size(); j++) {
		btCollisionShape* shape = collisionShapes[j];
		collisionShapes[j] = 0;
		delete shape;
	}

	delete dynamicsWorld;
	delete solver;
	delete overlappingPairCache;
	delete dispatcher;
	delete collisionConfiguration;

	collisionShapes.clear();
}
