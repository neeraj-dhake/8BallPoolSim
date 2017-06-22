#include "WorldObject_pool.h"


WorldObject_pool::WorldObject_pool(property prp_,kind Kind) {
	gObject = new GraphicsObject_pool(this,Kind);
	prp = prp_;
}

void WorldObject_pool::CreateObject(BulletWorld* PhyWorld_) {
	pObject = PhyWorld_->AddObject(POOL, prp, this);
}


WorldObject_pool::~WorldObject_pool() {
}
