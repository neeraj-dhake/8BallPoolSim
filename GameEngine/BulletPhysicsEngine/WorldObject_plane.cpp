#include "WorldObject_plane.h"
#include "../RenderingEngine/GraphicsObject_plane.h"

WorldObject_plane::WorldObject_plane(property prp_, bool need_graphics) {
	if (need_graphics)
		gObject = new GraphicsObject_plane(this);
	else
		gObject = nullptr;
	prp = prp_;
}

Vector3D WorldObject_plane::GetNormal() {
	return normal;
}

void WorldObject_plane::SetPlane(Vector3D normal_, float dist_) {
	normal = normal_;
	dist = dist_;
}

void WorldObject_plane::CreateObject(BulletWorld* PhyWorld_) {
	pObject = PhyWorld_->AddObject(STATIC_PLANE, prp, this);
}

float WorldObject_plane::GetDist() {
	return dist;
}

WorldObject_plane::~WorldObject_plane() {
}
