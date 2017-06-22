#include "BulletWorld.h"
#include "WorldObject_cuboid.h"
#include "WorldObject_sphere.h"
#include "../8BallPool/WorldObject_pool.h"
#include "../Include/BulletCollision/CollisionShapes/btShapeHull.h"
#include "Vector3D.h"

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

btRigidBody* BulletWorld::AddObject(TypeOfObject type, property prp, void* parent) {	// user editable otherwise put that in else other object
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
		case pool: {
			int num_triangles = (((WorldObject_pool*)parent)->GetgObject())->GetNumPrimitives();
			int num_vertices = (((WorldObject_pool*)parent)->GetgObject())->GetNumVertices();
			void* vertices = (((WorldObject_pool*)parent)->GetgObject())->GetVBuf();

			if ((((WorldObject_pool*)parent)->GetgObject())->isConcave) {
				void* indices = (((WorldObject_pool*)parent)->GetgObject())->GetIBuf();
				btTriangleIndexVertexArray* meshInterface = new btTriangleIndexVertexArray();
				btIndexedMesh part;
				part.m_vertexBase = (const unsigned char*)vertices;
				part.m_vertexStride = sizeof(float) * 3;
				part.m_numVertices = num_vertices;
				part.m_triangleIndexBase = (const unsigned char*)indices;
				part.m_triangleIndexStride = sizeof(short) * 3;
				part.m_numTriangles = num_triangles;
				part.m_indexType = PHY_SHORT;
				part.m_vertexType = PHY_FLOAT;
				meshInterface->addIndexedMesh(part, PHY_SHORT);
				Shape = new btBvhTriangleMeshShape(meshInterface, true);
			}
			else {
				btVector3* vert = new btVector3[num_vertices];
				for (size_t i = 0; i < num_vertices; i++) {
					vert[i].setX(((Vector3D*)vertices)[i].x);
					vert[i].setY(((Vector3D*)vertices)[i].y);
					vert[i].setZ(((Vector3D*)vertices)[i].z);
				}
				Shape = new btConvexHullShape((btScalar*)vert, num_vertices, 4 * sizeof(double));
				Shape->setMargin(0.1);
				btShapeHull* hull = new btShapeHull((btConvexShape*)Shape);
				btScalar margin = Shape->getMargin();
				hull->buildHull(margin);
				delete Shape;
				Shape = new btConvexHullShape((btScalar*)(hull->getVertexPointer()), hull->numVertices());
			}
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

btDiscreteDynamicsWorld * BulletWorld::GetDynamicWorld() {
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
