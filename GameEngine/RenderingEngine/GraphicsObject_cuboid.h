#pragma once
#include "IGraphicsObject.h"
#pragma comment (lib, "d3d9.lib")
#pragma comment (lib, "d3dx9.lib")
class WorldObject_cuboid;
class GraphicsObject_cuboid : public IGraphicsObject {
public:
	GraphicsObject_cuboid(WorldObject_cuboid*);
	void SetIndices(void*);
	void SetVertices(void*);
	void SetVBuf(void*, int);
	void SetIBuf(void*, int);
	void SetTexture(void*);
	void Init();
	~GraphicsObject_cuboid();
};

