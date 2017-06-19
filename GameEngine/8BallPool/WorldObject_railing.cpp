#include "WorldObject_railing.h"


WorldObject_railing::WorldObject_railing(property prp_) {
	gObject = new GraphicsObject_railing(this);
	prp = prp_;
}

void WorldObject_railing::CreateObject(BulletWorld* PhyWorld_) {
	pObject = PhyWorld_->AddObject(Railing, prp, this);
}

btVector3* WorldObject_railing::GetPoints() {
	btVector3 points[8] = {
		btVector3(32, -5, -5),
		btVector3(-32, -5, -5),
		btVector3(32, -5, 5),
		btVector3(-32, -5, 5),
		btVector3(28, 5, -5),
		btVector3(-28, 5, -5),
		btVector3(28, 3, -5),
		btVector3(-28, 3, -5),
	};
	btVector3* pt = new btVector3[8];
	memcpy(pt, points, 8 * sizeof(btVector3));
	return pt;
}

int WorldObject_railing::GetNumPoints() {
	return 8;
}


WorldObject_railing::~WorldObject_railing() {
}
