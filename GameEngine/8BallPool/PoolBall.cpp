#include "PoolBall.h"



PoolBall::PoolBall(property property_,colour c)
{
	std::string address;
	switch (c) {

	case blue:
		address = "PoolBall.blend_blue.x";
		break;
	case black:
		address = "PoolBall.blend_black.x";
		break;
	case red:
		address = "PoolBall.blend_red.x";
		break;
	case brown:
		address = "PoolBall.blend_brown.x";
		break;
	case ochre:
		address = "PoolBall.blend_ochre.x";
		break;
	case purple:
		address = "PoolBall.blend_purple.x";
		break;
	case yellow:
		address = "PoolBall.blend_yellow.x";
		break;
	case green:
		address = "PoolBall.blend_green.x";
		break;

	case blue_stripes:
		address = "PoolBall.blend_blue_stripes.x";
		break;
	case red_stripes:
		address = "PoolBall.blend_red_stripes.x";
		break;
	case brown_stripes:
		address = "PoolBall.blend_brown_stripes.x";
		break;
	case ochre_stripes:
		address = "PoolBall.blend_ochre_stripes.x";
		break;
	case purple_stripes:
		address = "PoolBall.blend_purple_stripes.x";
		break;
	case yellow_stripes:
		address = "PoolBall.blend_yellow_stripes.x";
		break;
	case green_stripes:
		address = "PoolBall.blend_green_stripes.x";
		break;
	}
	ball = new WorldObject_sphere(property_, address);
		
}



PoolBall::~PoolBall()
{
	delete ball;
}

WorldObject_sphere * PoolBall::GetObj()
{
	return ball;;
}
