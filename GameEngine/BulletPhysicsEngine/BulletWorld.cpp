#include "BulletWorld.h"
#include "WorldObject_cuboid.h"
#include "WorldObject_sphere.h"





BulletWorld::BulletWorld() {
	collisionConfiguration = new btDefaultCollisionConfiguration();
	dispatcher = new btCollisionDispatcher(collisionConfiguration);
	overlappingPairCache = new btDbvtBroadphase();
	solver = new btSequentialImpulseConstraintSolver;
	dynamicsWorld = new btDiscreteDynamicsWorld(dispatcher, overlappingPairCache, solver, collisionConfiguration);

	dynamicsWorld->setGravity(btVector3(0, 0, 0));		// remember to change it back
}

void BulletWorld::update() {
	dynamicsWorld->stepSimulation(1.f / 60.f, 10);
}

btRigidBody* BulletWorld::AddObject(TypeOfObject type,void* parent) {
	if (type == Cuboid)	{
		btCollisionShape* Shape = new btBoxShape(btVector3(btScalar(((WorldObject_cuboid*)parent)->GetDim().x/2), btScalar(((WorldObject_cuboid*)parent)->GetDim().y / 2), btScalar(((WorldObject_cuboid*)parent)->GetDim().z / 2)));
		collisionShapes.push_back(Shape);

		btScalar mass(1.);		
		btDefaultMotionState* myMotionState = new btDefaultMotionState(btTransform(btQuaternion(0, 0, 0, 1), btVector3(((WorldObject_cuboid*)parent)->GetPos().x, ((WorldObject_cuboid*)parent)->GetPos().y, ((WorldObject_cuboid*)parent)->GetPos().z)));

		bool isDynamic = (mass != 0.f);				// similarly necessary then change this also
		btVector3 localInertia(0, 0, 0);
		if (isDynamic)
			Shape->calculateLocalInertia(mass, localInertia);

		
		btRigidBody::btRigidBodyConstructionInfo rbInfo(mass, myMotionState, Shape, localInertia);
		btRigidBody* body = new btRigidBody(rbInfo);

		dynamicsWorld->addRigidBody(body);
		return body;
	}

	else if (type == Sphere) {

		btCollisionShape* Shape = new btSphereShape(btScalar(((WorldObject_sphere*)parent)->GetRadius()));
		collisionShapes.push_back(Shape);


		btDefaultMotionState* myMotionState = new btDefaultMotionState(btTransform(btQuaternion(0, 0, 0, 1), btVector3(((WorldObject_sphere*)parent)->GetPos().x, ((WorldObject_sphere*)parent)->GetPos().y, ((WorldObject_sphere*)parent)->GetPos().z)));
		
		btScalar mass(1.f);
		bool isDynamic = (mass != 0.f);

		btVector3 localInertia(0, 0, 0);
		if (isDynamic)
			Shape->calculateLocalInertia(mass, localInertia);
		
		btRigidBody::btRigidBodyConstructionInfo rbInfo(mass, myMotionState, Shape, localInertia);
		btRigidBody* body = new btRigidBody(rbInfo);
		dynamicsWorld->addRigidBody(body);
		
		return body;
	}
	else
		return nullptr;

}

BulletWorld::~BulletWorld() {
	clean();
}
void BulletWorld::clean() {
	//cleanup in the reverse order of creation/initialization

	///-----cleanup_start-----

	//remove the rigidbodies from the dynamics world and delete them
	for (int i = dynamicsWorld->getNumCollisionObjects() - 1; i >= 0; i--) {
		btCollisionObject* obj = dynamicsWorld->getCollisionObjectArray()[i];
		btRigidBody* body = btRigidBody::upcast(obj);
		if (body && body->getMotionState()) {
			delete body->getMotionState();
		}
		dynamicsWorld->removeCollisionObject(obj);
		delete obj;
	}

	//delete collision shapes
	for (int j = 0; j < collisionShapes.size(); j++) {
		btCollisionShape* shape = collisionShapes[j];
		collisionShapes[j] = 0;
		delete shape;
	}

	//delete dynamics world
	delete dynamicsWorld;

	//delete solver
	delete solver;

	//delete broadphase
	delete overlappingPairCache;

	//delete dispatcher
	delete dispatcher;

	delete collisionConfiguration;

	//next line is optional: it will be cleared by the destructor when the array goes out of scope
	collisionShapes.clear();
}
