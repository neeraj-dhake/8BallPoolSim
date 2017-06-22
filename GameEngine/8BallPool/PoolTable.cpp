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
	PoolBall1 = new WorldObject_sphere(DYNAMIC);
	PoolBall2 = new WorldObject_sphere(DYNAMIC);
	plane1 = new WorldObject_plane(STATIC);
	plane2 = new WorldObject_plane(STATIC);
	plane3 = new WorldObject_plane(STATIC);
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
	PoolBall1->SetCoordinates(Vector3D(5, 5, 0));
	PoolBall2->SetCoordinates(Vector3D(-5, 5, 0));
	PoolBall1->SetRadius(2.5f);
	PoolBall2->SetRadius(2.5f);
	plane1->SetPlane(Vector3D(0, 0, -1), -109);
	plane2->SetPlane(Vector3D(-0.5, 3, 1), -76);
	plane3->SetPlane(Vector3D(1, 0, 0), -100);
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
	scene->AddObject(PoolBall1);
	PoolBall1->GetpObject()->setActivationState(DISABLE_DEACTIVATION);		// used for player controllable objects
	scene->AddObject(PoolBall2);
	PoolBall2->GetpObject()->setActivationState(DISABLE_DEACTIVATION);		// used for player controllable objects
	scene->AddObject(plane1);
	scene->AddObject(plane2);
	scene->AddObject(plane3);
}


PoolTable::~PoolTable()
{

}
