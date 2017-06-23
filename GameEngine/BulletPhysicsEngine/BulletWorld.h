#include "../Include/btBulletDynamicsCommon.h"
#include "../Include/LinearMath/btVector3.h"
#include "../Include/LinearMath/btAlignedObjectArray.h"
#include "../Include/BulletCollision/CollisionShapes/btCollisionShape.h"



#pragma once
#pragma comment (lib, "BulletDynamics_vs2010_x64_debug.lib")
#pragma comment (lib, "Bullet3Collision_vs2010_x64_debug.lib")
#pragma comment (lib, "LinearMath_vs2010_x64_debug.lib")

enum ShapeOfObject {SPHERE, CUBOID, POOL, STATIC_PLANE};
enum property {STATIC, DYNAMIC};
enum TypeOfObject { RIGID_BODY, COLLISION_OBJECT, GHOST_OBJECT, SOFT_BODY};

class BulletWorld {
	btDefaultCollisionConfiguration* collisionConfiguration;
	btCollisionDispatcher* dispatcher;
	btBroadphaseInterface* overlappingPairCache;
	btSequentialImpulseConstraintSolver* solver;
	btDiscreteDynamicsWorld* dynamicsWorld;			// the whole world the most important character of bullet3d game engine 
													// All the power of the engine resides with this guy  #Respect :P
	btAlignedObjectArray<btCollisionShape*> collisionShapes;
public:
	BulletWorld();
	~BulletWorld();
	void clean();
	void update();
	btCollisionObject* AddObject(ShapeOfObject, property,  void*, TypeOfObject type = RIGID_BODY);
	btDiscreteDynamicsWorld* GetDynamicWorld();
};

