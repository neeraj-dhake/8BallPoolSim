#include "BulletWorld.h"
#include "WorldObject_cuboid.h"
#include "WorldObject_sphere.h"





BulletWorld::BulletWorld()
{

	collisionConfiguration = new btDefaultCollisionConfiguration();
	dispatcher = new btCollisionDispatcher(collisionConfiguration);
	overlappingPairCache = new btDbvtBroadphase();
	solver = new btSequentialImpulseConstraintSolver;
	dynamicsWorld = new btDiscreteDynamicsWorld(dispatcher, overlappingPairCache, solver, collisionConfiguration);

	dynamicsWorld->setGravity(btVector3(0, -10, 0));



	//{
	//	btCollisionShape* groundShape = new btBoxShape(btVector3(btScalar(50.), btScalar(50.), btScalar(50.)));

	//	collisionShapes.push_back(groundShape);

	//	btTransform groundTransform;
	//	groundTransform.setIdentity();
	//	groundTransform.setOrigin(btVector3(0, -56, 0));

	//	btScalar mass(0.);

	//	//rigidbody is dynamic if and only if mass is non zero, otherwise static
	//	bool isDynamic = (mass != 0.f);

	//	btVector3 localInertia(0, 0, 0);
	//	if (isDynamic)
	//		groundShape->calculateLocalInertia(mass, localInertia);

	//	//using motionstate is optional, it provides interpolation capabilities, and only synchronizes 'active' objects
	//	btDefaultMotionState* myMotionState = new btDefaultMotionState(groundTransform);
	//	btRigidBody::btRigidBodyConstructionInfo rbInfo(mass, myMotionState, groundShape, localInertia);
	//	btRigidBody* body = new btRigidBody(rbInfo);

	//	//add the body to the dynamics world
	//	dynamicsWorld->addRigidBody(body);
	//}

	//{
	//	//create a dynamic rigidbody sphere
	//	//btCollisionShape* colShape = new btBoxShape(btVector3(1,1,1));
	//	
	//	
	//	btCollisionShape* colShape = new btSphereShape(btScalar(1.));
	//	collisionShapes.push_back(colShape);

	//	/// Create Dynamic Objects
	//	btTransform startTransform;
	//	startTransform.setIdentity();

	//	btScalar mass(1.f);

	//	//rigidbody is dynamic if and only if mass is non zero, otherwise static
	//	bool isDynamic = (mass != 0.f);

	//	btVector3 localInertia(0, 0, 0);
	//	if (isDynamic)
	//		colShape->calculateLocalInertia(mass, localInertia);

	//	startTransform.setOrigin(btVector3(2, 10, 0));

	//	//using motionstate is recommended, it provides interpolation capabilities, and only synchronizes 'active' objects
	//	btDefaultMotionState* myMotionState = new btDefaultMotionState(startTransform);
	//	btRigidBody::btRigidBodyConstructionInfo rbInfo(mass, myMotionState, colShape, localInertia);
	//	btRigidBody* body = new btRigidBody(rbInfo);

	//	dynamicsWorld->addRigidBody(body);
	//}


	///-----stepsimulation_end-----






}

void BulletWorld::update()
{

	for (int i = 0; i < 150; i++)
	{
		dynamicsWorld->stepSimulation(1.f / 60.f, 10);

		//print positions of all objects
		for (int j = dynamicsWorld->getNumCollisionObjects() - 1; j >= 0; j--)
		{
			btCollisionObject* obj = dynamicsWorld->getCollisionObjectArray()[j];
			btRigidBody* body = btRigidBody::upcast(obj);
			btTransform trans;
			if (body && body->getMotionState())
			{
				body->getMotionState()->getWorldTransform(trans);
			}
			else
			{
				trans = obj->getWorldTransform();
			}
			printf("world pos object %d = %f,%f,%f\n", j, float(trans.getOrigin().getX()), float(trans.getOrigin().getY()), float(trans.getOrigin().getZ()));
		}
	}
}

void BulletWorld::AddObject(TypeOfObject type,void* parent)
{
	
	
	if (type == Cuboid)	
	{
		// call parent functions to set it			

		//	btCollisionShape* groundShape = new btBoxShape(btVector3(btScalar(50.), btScalar(50.), btScalar(50.)));
		btCollisionShape* groundShape = new btBoxShape(btVector3(btScalar(((WorldObject_cuboid*)parent)->GetDim().x), btScalar(((WorldObject_cuboid*)parent)->GetDim().y), btScalar(((WorldObject_cuboid*)parent)->GetDim().z)));

		collisionShapes.push_back(groundShape);

		btTransform groundTransform;
		groundTransform.setIdentity();
		groundTransform.setOrigin(btVector3(((WorldObject_cuboid*)parent)->GetPos().x, ((WorldObject_cuboid*)parent)->GetPos().y, ((WorldObject_cuboid*)parent)->GetPos().z));

		btScalar mass(1.);		// non static => dynamic	// btScalar mass(1.);
		//rigidbody is dynamic if and only if mass is non zero, otherwise static
		
		
		bool isDynamic = (mass != 0.f);				// similarly necessary then change this also

		btVector3 localInertia(0, 0, 0);
		if (isDynamic)
			groundShape->calculateLocalInertia(mass, localInertia);

		//using motionstate is optional, it provides interpolation capabilities, and only synchronizes 'active' objects
		btDefaultMotionState* myMotionState = new btDefaultMotionState(groundTransform);
		btRigidBody::btRigidBodyConstructionInfo rbInfo(mass, myMotionState, groundShape, localInertia);
		btRigidBody* body = new btRigidBody(rbInfo);

		//add the body to the dynamics world
		dynamicsWorld->addRigidBody(body);
	}

	else if (type == Sphere)
	{

		//btCollisionShape* colShape = new btSphereShape(btScalar(((WorldObject_sphere*)parent)->GetRadius()));
		btCollisionShape* colShape = new btSphereShape(btScalar(1));
		//collisionShapes.push_back(colShape);

		///// Create Dynamic Objects
		//btTransform startTransform;
		//startTransform.setIdentity();

		//btScalar mass(1.f);

		////rigidbody is dynamic if and only if mass is non zero, otherwise static
		//bool isDynamic = (mass != 0.f);

		//btVector3 localInertia(0, 0, 0);
		//if (isDynamic)
		//	colShape->calculateLocalInertia(mass, localInertia);

		////startTransform.setOrigin(btVector3(2, 10, 0));

		//startTransform.setOrigin(btVector3(((WorldObject_cuboid*)parent)->GetPos().x, ((WorldObject_cuboid*)parent)->GetPos().y, ((WorldObject_cuboid*)parent)->GetPos().z));

		////using motionstate is recommended, it provides interpolation capabilities, and only synchronizes 'active' objects
		//btDefaultMotionState* myMotionState = new btDefaultMotionState(startTransform);
		//btRigidBody::btRigidBodyConstructionInfo rbInfo(mass, myMotionState, colShape, localInertia);
		//btRigidBody* body = new btRigidBody(rbInfo);

		//dynamicsWorld->addRigidBody(body);
	}

}

BulletWorld::~BulletWorld()
{
	clean();
}
void BulletWorld::clean()
{
	//cleanup in the reverse order of creation/initialization

	///-----cleanup_start-----

	//remove the rigidbodies from the dynamics world and delete them
	for (int i = dynamicsWorld->getNumCollisionObjects() - 1; i >= 0; i--)
	{
		btCollisionObject* obj = dynamicsWorld->getCollisionObjectArray()[i];
		btRigidBody* body = btRigidBody::upcast(obj);
		if (body && body->getMotionState())
		{
			delete body->getMotionState();
		}
		dynamicsWorld->removeCollisionObject(obj);
		delete obj;
	}

	//delete collision shapes
	for (int j = 0; j < collisionShapes.size(); j++)
	{
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
