#pragma once
#include "IGraphicsObject.h"
#pragma comment (lib, "d3d9.lib")
#pragma comment (lib, "d3dx9.lib")
class WorldObject_plane;
class GraphicsObject_plane : public IGraphicsObject {
public:
	GraphicsObject_plane(WorldObject_plane*);
	void Init();
	~GraphicsObject_plane();
};

