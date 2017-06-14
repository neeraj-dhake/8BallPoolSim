#include "../Include/btBulletDynamicsCommon.h"
#pragma once


enum TypeOfObject {Sphere,Cuboid};

class BulletWorld
{
	btDefaultCollisionConfiguration* collisionConfiguration;
	btCollisionDispatcher* dispatcher;
	btBroadphaseInterface* overlappingPairCache;
	btSequentialImpulseConstraintSolver* solver;
	btDiscreteDynamicsWorld* dynamicsWorld;			// the whole world the most important character of bullet3d game engine 
													// All the power of the engine resides with this guy  #Respect :P

	btAlignedObjectArray<btCollisionShape*> collisionShapes;  // list of shapes of object

public:
	BulletWorld();
	~BulletWorld();
	void clean();
	void update();
	void AddObject(TypeOfObject,void*);
};

