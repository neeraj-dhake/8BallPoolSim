#include "WorldObject_cuboid.h"
#include "BulletPhysicsObject_cuboid.h"
#include "../RenderingEngine/GraphicsObject_cuboid.h"

#include "BulletWorld.h"


WorldObject_cuboid::WorldObject_cuboid(property property_) {
	gObject = new GraphicsObject_cuboid(this);
	prp = property_;
}

Vector3D WorldObject_cuboid::GetDim() {
	return Vector3D(width, height, depth);
}

void WorldObject_cuboid::CreateObject(BulletWorld* PhyWorld_) {
	pObject = PhyWorld_->AddObject(Cuboid, prp, this);
}

void WorldObject_cuboid::SetDim(float w, float h, float d) {
	width = w;
	depth = d;
	height = h;

}

WorldObject_cuboid::~WorldObject_cuboid() {
}
