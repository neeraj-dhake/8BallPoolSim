#include "WorldObject_pool.h"


WorldObject_pool::WorldObject_pool(property prp_,kind Kind_ ,TypeOfObject type_) {
	gObject = new GraphicsObject_pool(this,Kind_);
	prp = prp_;
	type = type_;
	Kind = Kind_;
}

void WorldObject_pool::CreateObject(BulletWorld* PhyWorld_) {

	if(Kind == stick)
		pObject = PhyWorld_->AddObject(POOL, prp, this);
	else
		pObject = PhyWorld_->AddObject(POOL, prp, this);
}


WorldObject_pool::~WorldObject_pool() {
}
