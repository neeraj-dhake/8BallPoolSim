#include "WorldObject_pool.h"
#include "../SceneManager/Scene.h"
#include "../BulletPhysicsEngine/WorldObject_sphere.h"
#include "PoolBall.h"

const unsigned int PoolBallBlack = 8;
const unsigned int PoolBallBlue = 7;
#pragma once
class PoolTable
{
	WorldObject_pool* baseObj;
	WorldObject_pool* leftCushionObj;
	WorldObject_pool* rightCushionObj;
	WorldObject_pool* topleftCushionObj;
	WorldObject_pool* toprightCushionObj;
	WorldObject_pool* bottomleftCushionObj;
	WorldObject_pool* bottomrightCushionObj;
	PoolBall* PoolBallBlack;
	PoolBall* PoolBallBlue;
	PoolBall* PoolBallOchre;
	PoolBall* PoolBallBrown;
	PoolBall* PoolBallRed;
	PoolBall* PoolBallYellow;
	PoolBall* PoolBallGreen;
	PoolBall* PoolBallPurple;

	PoolBall* PoolBallBlack_stripes;
	PoolBall* PoolBallBlue_stripes;
	PoolBall* PoolBallOchre_stripes;
	PoolBall* PoolBallBrown_stripes;
	PoolBall* PoolBallRed_stripes;
	PoolBall* PoolBallYellow_stripes;
	PoolBall* PoolBallGreen_stripes;
	PoolBall* PoolBallPurple_stripes;

public:
	PoolTable();
	void SetCoordinates(Vector3D);
	void AddObject(Scene*);
	~PoolTable();
};

