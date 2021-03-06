#include "WorldObject_pool.h"
#include "../SceneManager/Scene.h"
#include "../BulletPhysicsEngine/WorldObject_sphere.h"
#include "PoolBall.h"
#include "../BulletPhysicsEngine/WorldObject_plane.h"

const unsigned int PoolStick = 8;
const unsigned int PoolBallWhite = 7;
const float offsetFromBall = 70.0f;
#pragma once
class PoolTable {
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

	PoolBall* PoolBallWhite;

	PoolBall* PoolBallBlack_stripes;
	PoolBall* PoolBallBlue_stripes;
	PoolBall* PoolBallOchre_stripes;
	PoolBall* PoolBallBrown_stripes;
	PoolBall* PoolBallRed_stripes;
	PoolBall* PoolBallYellow_stripes;
	PoolBall* PoolBallGreen_stripes;
	PoolBall* PoolBallPurple_stripes;

	WorldObject_pool* PoolStick;

	WorldObject_plane* plane1;
	WorldObject_plane* plane2;
	WorldObject_plane* plane3;
public:
	PoolTable();
	void SetCoordinates(Vector3D);
	void AddObject(Scene*);
	~PoolTable();
};

