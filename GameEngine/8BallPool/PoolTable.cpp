#include "PoolTable.h"



PoolTable::PoolTable()
{
	baseObj = new WorldObject_pool(STATIC,base);
	leftCushionObj = new WorldObject_pool(STATIC,left_cushion);
	rightCushionObj = new WorldObject_pool(STATIC,right_cushion);
	topleftCushionObj = new WorldObject_pool(STATIC,top_left_cushion);
	toprightCushionObj = new WorldObject_pool(STATIC, top_right_cushion);
	bottomleftCushionObj = new WorldObject_pool(STATIC, bottom_left_cushion);
	bottomrightCushionObj = new WorldObject_pool(STATIC, bottom_right_cushion);
	PoolBallBlack = new PoolBall(DYNAMIC,black);
	PoolBallBlue = new PoolBall(DYNAMIC,blue);
	PoolBallGreen = new PoolBall(DYNAMIC, green);
	PoolBallRed = new PoolBall(DYNAMIC, red);
	PoolBallYellow = new PoolBall(DYNAMIC, yellow);
	PoolBallOchre = new PoolBall(DYNAMIC, ochre);
	PoolBallPurple = new PoolBall(DYNAMIC, purple);
	PoolBallBrown = new PoolBall(DYNAMIC, brown);

	PoolBallWhite = new PoolBall(DYNAMIC, white);

	PoolBallBlue_stripes = new PoolBall(DYNAMIC, blue_stripes);
	PoolBallGreen_stripes = new PoolBall(DYNAMIC, green_stripes);
	PoolBallRed_stripes = new PoolBall(DYNAMIC, red_stripes);
	PoolBallYellow_stripes = new PoolBall(DYNAMIC, yellow_stripes);
	PoolBallOchre_stripes = new PoolBall(DYNAMIC, ochre_stripes);
	PoolBallPurple_stripes = new PoolBall(DYNAMIC, purple_stripes);
	PoolBallBrown_stripes = new PoolBall(DYNAMIC, brown_stripes);

	PoolStick = new WorldObject_pool(DYNAMIC, stick);
	plane1 = new WorldObject_plane(STATIC, false);
	plane2 = new WorldObject_plane(STATIC, false);
	plane3 = new WorldObject_plane(STATIC, false);
}

void PoolTable::SetCoordinates(Vector3D v) {
	baseObj->SetCoordinates(v);
	leftCushionObj->SetCoordinates(v);
	rightCushionObj->SetCoordinates(v);
	topleftCushionObj->SetCoordinates(v);
	toprightCushionObj->SetCoordinates(v);
	bottomleftCushionObj->SetCoordinates(v);
	bottomrightCushionObj->SetCoordinates(v);
	plane1->SetPlane(v + Vector3D(0, 0, -1), -109);
	plane2->SetPlane(v + Vector3D(-0.5, 3, 1), -76);
	plane3->SetPlane(v + Vector3D(1, 0, 0), -100);
	PoolBallBlack->GetObj()->SetCoordinates(Vector3D(5, 5, 0));
	PoolBallBlue->GetObj()->SetCoordinates(Vector3D(-5, 5, 0));


	PoolBallBlue_stripes->GetObj()->SetCoordinates(v + Vector3D(15, 5, 5));
	PoolBallGreen_stripes->GetObj()->SetCoordinates(v + Vector3D(-15, 5, -5));
	PoolBallRed_stripes->GetObj()->SetCoordinates(v + Vector3D(25, 5, 10));
	PoolBallYellow_stripes->GetObj()->SetCoordinates(v + Vector3D(-25, 5, -10));
	PoolBallOchre_stripes->GetObj()->SetCoordinates(v + Vector3D(35, 5, 20));
	PoolBallPurple_stripes->GetObj()->SetCoordinates(v + Vector3D(-35, 5, -20));
	PoolBallBrown_stripes->GetObj()->SetCoordinates(v + Vector3D(20, 5, 15));


	PoolBallGreen->GetObj()->SetCoordinates(v + Vector3D(-20, 5, -15));
	PoolBallRed->GetObj()->SetCoordinates(v + Vector3D(-10, 5, 25));
	PoolBallYellow->GetObj()->SetCoordinates(v + Vector3D(10, 5, -25));
	PoolBallOchre->GetObj()->SetCoordinates(v + Vector3D(-30, 5, 30));
	PoolBallPurple->GetObj()->SetCoordinates(v + Vector3D(30, 5, -35));
	PoolBallBrown->GetObj()->SetCoordinates(v + Vector3D(5, 5, 35));



	PoolBallWhite->GetObj()->SetCoordinates(v + Vector3D(-0, 5, 50));

	Vector3D StickPos = PoolBallWhite->GetObj()->GetPos();
	StickPos.z += offsetFromBall;
	StickPos.y += 20;

	PoolStick->SetCoordinates(StickPos);

	// set radius
	PoolBallBlue_stripes->GetObj()->SetRadius(2.5f);
	PoolBallGreen_stripes->GetObj()->SetRadius(2.5f);
	PoolBallRed_stripes->GetObj()->SetRadius(2.5f);
	PoolBallYellow_stripes->GetObj()->SetRadius(2.5f);
	PoolBallOchre_stripes->GetObj()->SetRadius(2.5f);
	PoolBallPurple_stripes->GetObj()->SetRadius(2.5f);
	PoolBallBrown_stripes->GetObj()->SetRadius(2.5f);

	PoolBallWhite->GetObj()->SetRadius(2.5f);

	PoolBallBlack->GetObj()->SetRadius(2.5f);
	PoolBallBlue->GetObj()->SetRadius(2.5f);
	PoolBallGreen->GetObj()->SetRadius(2.5f);
	PoolBallRed->GetObj()->SetRadius(2.5f);
	PoolBallYellow->GetObj()->SetRadius(2.5f);
	PoolBallOchre->GetObj()->SetRadius(2.5f);
	PoolBallPurple->GetObj()->SetRadius(2.5f);
	PoolBallBrown->GetObj()->SetRadius(2.5f);

}

void PoolTable::AddObject(Scene *scene)
{
	scene->AddObject(baseObj);
	scene->AddObject(leftCushionObj);
	scene->AddObject(rightCushionObj);
	scene->AddObject(topleftCushionObj);
	scene->AddObject(toprightCushionObj);
	scene->AddObject(bottomleftCushionObj);
	scene->AddObject(bottomrightCushionObj);
	scene->AddObject(PoolBallWhite->GetObj());
	PoolBallWhite->GetObj()->GetpObject()->setActivationState(DISABLE_DEACTIVATION);		// used for player controllable objects

	scene->AddObject(PoolStick);
	/*PoolStick->GetpObject()->setActivationState(DISABLE_DEACTIVATION);	*/	// used for player controllable objects
	//PoolStick->GetpObject()->setGravity(btVector3(0,0,0));		
	//PoolStick->GetpObject()->setCollisionFlags(PoolStick->GetpObject()->CF_NO_CONTACT_RESPONSE);

	//PoolStick->GetpObject()->setCollisionFlags(PoolStick->GetpObject()->getCollisionFlags() ^ btCollisionObject::CF_NO_CONTACT_RESPONSE);

	//PoolStick->GetpObject()->setCollisionFlags(PoolStick->GetpObject()->getCollisionFlags() |		btCollisionObject::CF_NO_CONTACT_RESPONSE);
	//PoolStick->GetpObject()->CollisionObjectTypes(btCollisionObject::CO_GHOST_OBJECT);
//	PoolStick->GetpObject()->setFlags(btCollisionObject::CO_GHOST_OBJECT);


	PoolStick->GetpObject()->setCollisionFlags(PoolStick->GetpObject()->getCollisionFlags() | btCollisionObject::CF_NO_CONTACT_RESPONSE);
	PoolStick->GetpObject()->setActivationState(DISABLE_DEACTIVATION);


	scene->AddObject(PoolBallBlue->GetObj());
	scene->AddObject(PoolBallBrown->GetObj());
	scene->AddObject(PoolBallRed->GetObj());
	scene->AddObject(PoolBallYellow->GetObj());
	scene->AddObject(PoolBallGreen->GetObj());
	scene->AddObject(PoolBallOchre->GetObj());
	scene->AddObject(PoolBallPurple->GetObj());

	scene->AddObject(PoolBallBlue_stripes->GetObj());
	scene->AddObject(PoolBallBrown_stripes->GetObj());
	scene->AddObject(PoolBallRed_stripes->GetObj());
	scene->AddObject(PoolBallYellow_stripes->GetObj());
	scene->AddObject(PoolBallGreen_stripes->GetObj());
	scene->AddObject(PoolBallOchre_stripes->GetObj());
	scene->AddObject(PoolBallPurple_stripes->GetObj());

	scene->AddObject(PoolBallBlack->GetObj());
	scene->AddObject(PoolStick);
	//scene->AddObject(plane1);
	//scene->AddObject(plane2);
	//scene->AddObject(plane3);

	for (size_t i = 0; i < scene->objects_in_scene.size(); i++)
	{
		(scene->objects_in_scene[i])->GetpObject()->setFriction(1.0);
		(scene->objects_in_scene[i])->GetpObject()->setRollingFriction(0.8);
		(scene->objects_in_scene[i])->GetpObject()->setSpinningFriction(0.8);
	}


	
	PoolStick->GetpObject()->setActivationState(DISABLE_DEACTIVATION);		// used for player controllable objects



	PoolBallWhite->GetObj()->GetpObject()->setRestitution(0.8);
	float x = PoolBallWhite->GetObj()->GetpObject()->getRestitution();
	((btRigidBody*)(PoolStick->GetpObject()))->setLinearFactor(btVector3(1, 0, 1));
	((btRigidBody*)(PoolStick->GetpObject()))->setAngularFactor(btVector3(0, 1, 0));

}


PoolTable::~PoolTable()
{
	delete baseObj;
	delete leftCushionObj;
	delete rightCushionObj;
	delete topleftCushionObj;
	delete toprightCushionObj;
	delete bottomleftCushionObj;
	delete bottomrightCushionObj;
	delete PoolBallBlack;
	delete PoolBallBlue;
	delete PoolBallGreen;
	delete PoolBallRed;
	delete PoolBallYellow;
	delete PoolBallOchre;
	delete PoolBallPurple;
	delete PoolBallBrown;

	delete PoolStick;
	delete PoolBallWhite;

	delete PoolBallBlue_stripes;
	delete PoolBallGreen_stripes;
	delete PoolBallRed_stripes;
	delete PoolBallYellow_stripes;
	delete PoolBallOchre_stripes;
	delete PoolBallPurple_stripes;
	delete PoolBallBrown_stripes;
}
