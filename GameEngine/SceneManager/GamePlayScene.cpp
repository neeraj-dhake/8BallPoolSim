#include "GamePlayScene.h"
#include "../BulletPhysicsEngine/WorldObject_cuboid.h"
#include "../BulletPhysicsEngine/WorldObject_sphere.h"
#include "../8BallPool/WorldObject_railing.h"
#include "../InputLib_Win/InputHandler.h"
#include "../BulletPhysicsEngine/Vector3D.h"
#include "SceneManager.h"


GamePlayScene::GamePlayScene() {
	is_active = false;
}

void GamePlayScene::SetScene() {
	is_active = true;
	WorldObject_railing* baseObj = new WorldObject_railing(STATIC, base);
	baseObj->SetCoordinates(Vector3D(0, -10, -50));
	AddObject(baseObj);

	//WorldObject_railing* leftCushionObj = new WorldObject_railing(STATIC, left_cushion);
	//leftCushionObj->SetCoordinates(Vector3D(0, -10, -50));
	//AddObject(leftCushionObj);

	//WorldObject_railing* rightCushionObj = new WorldObject_railing(STATIC, right_cushion);
	//rightCushionObj->SetCoordinates(Vector3D(0, -10, -50));
	//AddObject(rightCushionObj);

	

	WorldObject_sphere* obj2 = new WorldObject_sphere(DYNAMIC);
	obj2->SetCoordinates(Vector3D(5, 0, 0));
	obj2->SetRadius(5.0f);
	AddObject(obj2);
	obj2->GetpObject()->setActivationState(DISABLE_DEACTIVATION);		// used for player controllable objects

	WorldObject_sphere* obj3 = new WorldObject_sphere(DYNAMIC);
	obj3->SetCoordinates(Vector3D(5.0f, 0.0f, 0.0f));
	obj3->SetRadius(5.0f);
	AddObject(obj3);
	obj3->GetpObject()->setActivationState(DISABLE_DEACTIVATION);
}

GamePlayScene::~GamePlayScene() {
}

// helper function ---- to convert quaternions to euler angles

Vector3D toEulerianAngle(const btQuaternion& q)
{
	double ysqr = q.y() * q.y();

	// pitch (x-axis rotation)
	double t0 = +2.0 * (q.w() * q.x() + q.y() * q.z());
	double t1 = +1.0 - 2.0 * (q.x() * q.x() + ysqr);
	double pitch = std::atan2(t0, t1);

	// yaw (y-axis rotation)
	double t2 = +2.0 * (q.w() * q.y() - q.z() * q.x());
	t2 = t2 > 1.0 ? 1.0 : t2;
	t2 = t2 < -1.0 ? -1.0 : t2;
	double yaw = std::asin(t2);

	// roll (z-axis rotation)
	double t3 = +2.0 * (q.w() * q.z() + q.x() * q.y());
	double t4 = +1.0 - 2.0 * (ysqr + q.z() * q.z());
	double roll = std::atan2(t3, t4);

	return Vector3D(pitch, yaw, roll);
}

void GamePlayScene::UpdateScene() {
	if (InputHandler::instance().GetKeyState_current(KEY_D))
		(objects_in_scene[obj3]->GetpObject())->applyCentralImpulse(btVector3(btScalar(-0.5), btScalar(0), btScalar(0)));

	if (InputHandler::instance().GetKeyState_current(KEY_A))
		(objects_in_scene[obj3]->GetpObject())->applyCentralImpulse(btVector3(btScalar(+0.5), btScalar(0), btScalar(0)));

	if (InputHandler::instance().GetKeyState_current(KEY_W))
		(objects_in_scene[obj3]->GetpObject())->applyCentralImpulse(btVector3(btScalar(0), btScalar(0), btScalar(-0.5)));

	if (InputHandler::instance().GetKeyState_current(KEY_S))
		(objects_in_scene[obj3]->GetpObject())->applyCentralImpulse(btVector3(btScalar(0), btScalar(-0), btScalar(0.5)));


	if (InputHandler::instance().GetKeyState_current(KEY_UP))
		(objects_in_scene[obj2]->GetpObject())->applyCentralImpulse(btVector3(btScalar(0), btScalar(0), btScalar(-0.5)));

	if (InputHandler::instance().GetKeyState_current(KEY_DOWN))
		(objects_in_scene[obj2]->GetpObject())->applyCentralImpulse(btVector3(btScalar(0), btScalar(-0), btScalar(0.5)));

	if (InputHandler::instance().GetKeyState_current(KEY_LEFT))
		(objects_in_scene[obj2]->GetpObject())->applyCentralImpulse(btVector3(btScalar(+0.5), btScalar(0), btScalar(0)));

	if (InputHandler::instance().GetKeyState_current(KEY_RIGHT))
		(objects_in_scene[obj2]->GetpObject())->applyCentralImpulse(btVector3(btScalar(-0.5), btScalar(0), btScalar(0)));



	//InputHandler::instance().GetMouseX

	PhyWorld->update();
	
	for (size_t i = 0;i < objects_in_scene.size(); i++) {
		char msgbuf[200];
		sprintf_s(msgbuf, 200, "%d %f %f %f\n", i, objects_in_scene[i]->GetpObject()->getCenterOfMassPosition().getX(), objects_in_scene[i]->GetpObject()->getCenterOfMassPosition().getY(), objects_in_scene[i]->GetpObject()->getCenterOfMassPosition().getZ());
		OutputDebugString(msgbuf);
		objects_in_scene[i]->SetCoordinates(Vector3D(objects_in_scene[i]->GetpObject()->getCenterOfMassPosition()));
		objects_in_scene[i]->SetRotation(Vector3D(toEulerianAngle(objects_in_scene[i]->GetpObject()->getOrientation())));

	}
}
