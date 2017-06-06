#include "WorldObject_cuboid.h"
#include "../RenderingEngine/GraphicsObject_cuboid.h"

WorldObject_cuboid::WorldObject_cuboid() {
	pObject = NULL;
	gObject = new GraphicsObject_cuboid(this);
}

Vector3D WorldObject_cuboid::GetDim() {
	return Vector3D(width, height, depth);
}

void WorldObject_cuboid::SetDim(float w, float h, float d) {
	width = w;
	depth = d;
	height = h;
}

WorldObject_cuboid::~WorldObject_cuboid() {
}
