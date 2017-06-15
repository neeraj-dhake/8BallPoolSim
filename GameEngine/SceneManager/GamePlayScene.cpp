#include "GamePlayScene.h"
#include "../BulletPhysicsEngine/WorldObject_cuboid.h"
#include "../BulletPhysicsEngine/WorldObject_sphere.h"
#include "../InputLib_Win/InputHandler.h"
#include "../BulletPhysicsEngine/Vector3D.h"
#include "SceneManager.h"

GamePlayScene::GamePlayScene() {
	is_active = false;
}

void GamePlayScene::SetScene() {
	is_active = true;
	WorldObject_cuboid* obj1 = new WorldObject_cuboid;
	obj1->SetCoordinates(Vector3D(10, -10, 0));
	obj1->SetDim(10.0f, 10.0f, 10.0f);
	AddObject(obj1);

	WorldObject_cuboid* obj2 = new WorldObject_cuboid;
	obj2->SetCoordinates(Vector3D(-10, 10, 0));
	obj2->SetDim(10.0f, 10.0f, 10.0f);
	AddObject(obj2);

	WorldObject_sphere* obj3 = new WorldObject_sphere;
	obj3->SetCoordinates(Vector3D(10.0f, 10.0f, 0.0f));
	obj3->SetRadius(5.0f);
	AddObject(obj3);
}

GamePlayScene::~GamePlayScene() {
}

void GamePlayScene::UpdateScene() {
	if (InputHandler::instance().GetKeyState_current(KEY_D) && !InputHandler::instance().GetKeyState_prev(KEY_D))
		(objects_in_scene[obj1]->GetpObject())->applyCentralImpulse(btVector3(btScalar(-5.), btScalar(0), btScalar(0)));

	if (InputHandler::instance().GetKeyState_current(KEY_A) && !InputHandler::instance().GetKeyState_prev(KEY_A))
		(objects_in_scene[obj1]->GetpObject())->applyCentralImpulse(btVector3(btScalar(+5.), btScalar(0), btScalar(0)));

	if (InputHandler::instance().GetKeyState_current(KEY_W) && !InputHandler::instance().GetKeyState_prev(KEY_W))
		(objects_in_scene[obj1]->GetpObject())->applyCentralImpulse(btVector3(btScalar(0), btScalar(5), btScalar(0)));

	if (InputHandler::instance().GetKeyState_current(KEY_S) && !InputHandler::instance().GetKeyState_prev(KEY_S))
		(objects_in_scene[obj1]->GetpObject())->applyCentralImpulse(btVector3(btScalar(0), btScalar(-5), btScalar(0)));


	if(InputHandler::instance().GetKeyState_current(KEY_UP) && !InputHandler::instance().GetKeyState_prev(KEY_UP))
		(objects_in_scene[obj2]->GetpObject())->applyCentralImpulse(btVector3(btScalar(0), btScalar(5), btScalar(0)));

	if (InputHandler::instance().GetKeyState_current(KEY_DOWN) && !InputHandler::instance().GetKeyState_prev(KEY_DOWN))
		(objects_in_scene[obj2]->GetpObject())->applyCentralImpulse(btVector3(btScalar(0), btScalar(-5), btScalar(0)));

	if (InputHandler::instance().GetKeyState_current(KEY_LEFT) && !InputHandler::instance().GetKeyState_prev(KEY_LEFT))
		(objects_in_scene[obj2]->GetpObject())->applyCentralImpulse(btVector3(btScalar(+5.), btScalar(0), btScalar(0)));

	if (InputHandler::instance().GetKeyState_current(KEY_RIGHT) && !InputHandler::instance().GetKeyState_prev(KEY_RIGHT))
		(objects_in_scene[obj2]->GetpObject())->applyCentralImpulse(btVector3(btScalar(-5.), btScalar(0), btScalar(0)));

	for (size_t i = 0;i < objects_in_scene.size(); i++) {
		/*for (size_t j = i + 1; j < objects_in_scene.size(); j++) {
			ICollisionObject* a = (objects_in_scene[i])->GetpObject()->GetCollisionObject();
			ICollisionObject* b = (objects_in_scene[j])->GetpObject()->GetCollisionObject();
			if (Manager->physics_engine->DetectCollision(a, b)) {
				Manager->physics_engine->CollisionResponse( (objects_in_scene[i])->GetpObject()->GetData(),
															(objects_in_scene[j])->GetpObject()->GetData() );
			}
		}*/

		PhyWorld->update();		// physics world gets updated
		// now update the world object
		objects_in_scene[i]->SetCoordinates(Vector3D(objects_in_scene[i]->GetpObject()->getCenterOfMassPosition().getX(), objects_in_scene[i]->GetpObject()->getCenterOfMassPosition().getY(), objects_in_scene[i]->GetpObject()->getCenterOfMassPosition().getZ()));
		// updated the world object
	}
}
