#include "WorldObject_cuboid.h"
#include "PhysicsObject_cuboid.h"
#include "../RenderingEngine/GraphicsObject_cuboid.h"


WorldObject_cuboid::WorldObject_cuboid() {
	pObject = new PhysicsObject_cuboid(this);
	gObject = new GraphicsObject_cuboid(this);
}

Vector3D WorldObject_cuboid::GetDim() {
	return Vector3D(width, height, depth);
}

void WorldObject_cuboid::SetDim(float w, float h, float d) {
	width = w;
	depth = d;
	height = h;
	((PhysicsObject_cuboid*)(pObject))->SetDim(w, h, d);
	((PhysicsObject_cuboid*)(pObject))->SetCollisionObject();

}
AABB* WorldObject_cuboid::GetAABB() {
	return (AABB*)((PhysicsObject_cuboid*)(pObject))->GetCollisionObject();
}

WorldObject_cuboid::~WorldObject_cuboid() {
}
