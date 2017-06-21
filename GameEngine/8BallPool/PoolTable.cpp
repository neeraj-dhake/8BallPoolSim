#include "PoolTable.h"



PoolTable::PoolTable(property property_)
{
	baseObj = new WorldObject_pool(property_,base);
	leftCushionObj = new WorldObject_pool(property_,left_cushion);
	rightCushionObj = new WorldObject_pool(property_,right_cushion);
	topleftCushionObj = new WorldObject_pool(property_,top_left_cushion);
	toprightCushionObj = new WorldObject_pool(property_, top_right_cushion);
	bottomleftCushionObj = new WorldObject_pool(property_, bottom_left_cushion);
	bottomrightCushionObj = new WorldObject_pool(property_, bottom_right_cushion);
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
}


PoolTable::~PoolTable()
{

}
