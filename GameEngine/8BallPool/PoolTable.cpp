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



}

void PoolTable::SetCoordinates(Vector3D v)
{
	baseObj->SetCoordinates(v);
	leftCushionObj->SetCoordinates(v);
	rightCushionObj->SetCoordinates(v);
	topleftCushionObj->SetCoordinates(v);
	toprightCushionObj->SetCoordinates(v);
	bottomleftCushionObj->SetCoordinates(v);
	bottomrightCushionObj->SetCoordinates(v);
	PoolBallBlack->GetObj()->SetCoordinates(Vector3D(5, 0, 0));
	PoolBallBlue->GetObj()->SetCoordinates(Vector3D(-5, 0, 0));

	PoolBallWhite->GetObj()->SetCoordinates(Vector3D(-5, 0, 20));

	PoolStick->SetCoordinates(Vector3D(25, 0, 20));

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
	//scene->AddObject(PoolStick);
	//PoolStick->GetpObject()->setActivationState(DISABLE_DEACTIVATION);		// used for player controllable objects
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

	for (size_t i = 0; i < scene->objects_in_scene.size(); i++)
	{
		(scene->objects_in_scene[i])->GetpObject()->setFriction(5.0f);
		(scene->objects_in_scene[i])->GetpObject()->setAnisotropicFriction(btVector3(5, 5, 5));
	}

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
