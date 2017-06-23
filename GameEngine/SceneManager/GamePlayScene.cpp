#include "GamePlayScene.h"
#include "../BulletPhysicsEngine/WorldObject_cuboid.h"
#include "../BulletPhysicsEngine/WorldObject_sphere.h"
#include "../8BallPool/WorldObject_pool.h"
#include "../InputLib_Win/InputHandler.h"
#include "../BulletPhysicsEngine/Vector3D.h"
#include "SceneManager.h"
#include "../8BallPool/PoolTable.h"




GamePlayScene::GamePlayScene() {
	is_active = false;
}

void GamePlayScene::SetScene() {
	is_active = true;

	PoolTable* poolTable = new PoolTable();		
	poolTable->SetCoordinates(Vector3D(0, 0, 0));
	poolTable->AddObject(this);
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
static btQuaternion toQuaternion(double pitch /*y*/, double roll /*x*/, double yaw /*z*/)
{
	btQuaternion q;
	double t0 = std::cos(yaw * 0.5);
	double t1 = std::sin(yaw * 0.5);
	double t2 = std::cos(roll * 0.5);
	double t3 = std::sin(roll * 0.5);
	double t4 = std::cos(pitch * 0.5);
	double t5 = std::sin(pitch * 0.5);



	q.setW(t0 * t2 * t4 + t1 * t3 * t5);
	q.setX(t0 * t3 * t4 - t1 * t2 * t5);
	q.setY(t0 * t2 * t5 + t1 * t3 * t4);
	q.setZ(t1 * t2 * t4 - t0 * t3 * t5);
	return q;
}



void GamePlayScene::UpdateScene() {

	
	((btRigidBody*)(objects_in_scene[PoolStick]->GetpObject()))->setLinearFactor(btVector3(1, 0, 1));
	((btRigidBody*)(objects_in_scene[PoolStick]->GetpObject()))->setAngularFactor(btVector3(0, 1, 0));

	//((btRigidBody*)(objects_in_scene[PoolBallBlack]->GetpObject()))->setAngularVelocity(btVector3(0, 1, 0));
	const float rotateAngle = 0.01;

	btTransform transform;
	btScalar x, y, z;

	if (InputHandler::instance().GetKeyState_current(KEY_D)) {

		//((btRigidBody*)(objects_in_scene[PoolBallBlack]->GetpObject()))->applyTorqueImpulse(btVector3(btScalar(0), btScalar(2), btScalar(0)));

		((btRigidBody*)(objects_in_scene[PoolStick]->GetpObject()))->getOrientation().getEulerZYX(z,y,x);
		btQuaternion qt = toQuaternion(y- rotateAngle,x,z);
		btVector3 pos = (((btRigidBody*)(objects_in_scene[PoolStick]->GetpObject()))->getCenterOfMassPosition());

		pos.setX(pos.getX() - btScalar(offsetFromBall*std::sin(rotateAngle)));
		
		if(y>0)
			pos.setZ(pos.getZ() - btScalar(offsetFromBall*(1 - std::cos(rotateAngle))));
		else
			pos.setZ(pos.getZ() + btScalar(offsetFromBall*(1 - std::cos(rotateAngle))));

		transform.setOrigin(pos);
		transform.setRotation(qt);
		((btRigidBody*)(objects_in_scene[PoolStick]->GetpObject()))->setWorldTransform(transform);
	}
	if (InputHandler::instance().GetKeyState_current(KEY_A)) {
		//((btRigidBody*)(objects_in_scene[PoolBallBlack]->GetpObject()))->applyTorqueImpulse(btVector3(btScalar(0), btScalar(2), btScalar(0)));

		((btRigidBody*)(objects_in_scene[PoolStick]->GetpObject()))->getOrientation().getEulerZYX(z, y, x);
		btVector3 pos = (((btRigidBody*)(objects_in_scene[PoolStick]->GetpObject()))->getCenterOfMassPosition());


		pos.setX( pos.getX() + btScalar(offsetFromBall*std::sin(rotateAngle)));
		if (y<0)
			pos.setZ(pos.getZ() - btScalar(offsetFromBall*(1 - std::cos(rotateAngle))));
		else
			pos.setZ(pos.getZ() + btScalar(offsetFromBall*(1 - std::cos(rotateAngle))));


		transform.setOrigin(pos);
		btQuaternion qt = toQuaternion(y + rotateAngle, x, z);
		transform.setRotation(qt);
		((btRigidBody*)(objects_in_scene[PoolStick]->GetpObject()))->setWorldTransform(transform);

	}
	//if (InputHandler::instance().GetKeyState_current(KEY_W))
	//	((btRigidBody*)(objects_in_scene[PoolBallBlack]->GetpObject()))->applyTorqueImpulse(btVector3(btScalar(0), btScalar(0), btScalar(-0.5)));

	//if (InputHandler::instance().GetKeyState_current(KEY_S))
	//	((btRigidBody*)(objects_in_scene[PoolBallBlack]->GetpObject()))->applyTorqueImpulse(btVector3(btScalar(0), btScalar(-0), btScalar(0.5)));


	if (InputHandler::instance().GetKeyState_current(KEY_UP))
		((btRigidBody*)(objects_in_scene[PoolBallWhite]->GetpObject()))->applyCentralImpulse(btVector3(btScalar(0), btScalar(0), btScalar(-0.5)));

	if (InputHandler::instance().GetKeyState_current(KEY_DOWN))
		((btRigidBody*)(objects_in_scene[PoolBallWhite]->GetpObject()))->applyCentralImpulse(btVector3(btScalar(0), btScalar(-0), btScalar(0.5)));

	if (InputHandler::instance().GetKeyState_current(KEY_LEFT))
		((btRigidBody*)(objects_in_scene[PoolBallWhite]->GetpObject()))->applyCentralImpulse(btVector3(btScalar(+0.5), btScalar(0), btScalar(0)));

	if (InputHandler::instance().GetKeyState_current(KEY_RIGHT))
		((btRigidBody*)(objects_in_scene[PoolBallWhite]->GetpObject()))->applyCentralImpulse(btVector3(btScalar(-0.5), btScalar(0), btScalar(0)));


	if (InputHandler::instance().GetKeyState_current(KEY_W))
	{
		btVector3 posStick = (((btRigidBody*)(objects_in_scene[PoolStick]->GetpObject()))->getCenterOfMassPosition());
		btVector3 posBall = (((btRigidBody*)(objects_in_scene[PoolBallWhite]->GetpObject()))->getCenterOfMassPosition());

		btVector3 impulseDirec = posBall - posStick;
		btScalar power = 10.0f;
		impulseDirec =  power*impulseDirec.normalize();
		((btRigidBody*)(objects_in_scene[PoolBallWhite]->GetpObject()))->applyCentralImpulse(impulseDirec);

	}

	//InputHandler::instance().GetMouseX

	PhyWorld->update();
	
	for (size_t i = 0;i < objects_in_scene.size(); i++) {
	/*	char msgbuf[200];
		sprintf_s(msgbuf, 200, "%s %f %f %f\n", i, ((btRigidBody*)(objects_in_scene[i]->GetpObject()))->getCenterOfMassPosition().getX(), 
			((btRigidBody*)(objects_in_scene[i]->GetpObject()))->getCenterOfMassPosition().getY(),
			((btRigidBody*)(objects_in_scene[i]->GetpObject()))->getCenterOfMassPosition().getZ());
		OutputDebugString(msgbuf);*/
		objects_in_scene[i]->SetCoordinates(Vector3D(((btRigidBody*)(objects_in_scene[i]->GetpObject()))->getCenterOfMassPosition()));

		btScalar x, y, z;
		((btRigidBody*)(objects_in_scene[i]->GetpObject()))->getOrientation().getEulerZYX(z, y, x);

		objects_in_scene[i]->SetRotation(Vector3D(x,y,z));

	}
}
