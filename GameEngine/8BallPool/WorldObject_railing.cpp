#include "WorldObject_railing.h"


WorldObject_railing::WorldObject_railing(property prp_,kind kind_) {
	gObject = new GraphicsObject_railing(this,kind_);
	prp = prp_;
}

void WorldObject_railing::CreateObject(BulletWorld* PhyWorld_) {
	pObject = PhyWorld_->AddObject(Railing, prp, this);
}

int WorldObject_railing::GetNumPoints() {
	return 8;
}


WorldObject_railing::~WorldObject_railing() {
}
