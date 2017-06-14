#include "WorldObject_cuboid.h"
#include "BulletPhysicsObject_cuboid.h"
#include "../RenderingEngine/GraphicsObject_cuboid.h"

#include "BulletWorld.h"


WorldObject_cuboid::WorldObject_cuboid() {
	//pObject = new BulletPhysicsObject_cuboid(this);
	gObject = new GraphicsObject_cuboid(this);
}

Vector3D WorldObject_cuboid::GetDim() {
	return Vector3D(width, height, depth);
}

void WorldObject_cuboid::Create(BulletWorld* PhyWorld_)
{
	PhyWorld_->AddObject(Cuboid,this);
}

void WorldObject_cuboid::SetDim(float w, float h, float d) {
	width = w;
	depth = d;
	height = h;
	((BulletPhysicsObject_cuboid*)(pObject))->SetDim(w, h, d);
	((BulletPhysicsObject_cuboid*)(pObject))->SetCollisionObject();

}

WorldObject_cuboid::~WorldObject_cuboid() {
}
