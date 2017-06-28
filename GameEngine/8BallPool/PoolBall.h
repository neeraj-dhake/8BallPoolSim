#pragma once
#include "../BulletPhysicsEngine/WorldObject_sphere.h"
enum colour {red,ochre,black,blue,brown,green,yellow,purple, red_stripes, ochre_stripes, blue_stripes, brown_stripes, green_stripes, yellow_stripes, purple_stripes,white};
class PoolBall 
{
	WorldObject_sphere* ball;
public:
	PoolBall(property property_,colour);
	~PoolBall();
	WorldObject_sphere* GetObj();
};

