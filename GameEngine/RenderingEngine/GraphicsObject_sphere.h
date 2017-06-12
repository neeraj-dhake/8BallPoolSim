#pragma once
#include "IGraphicsObject.h"
#pragma comment (lib, "d3d9.lib")
#pragma comment (lib, "d3dx9.lib")

class WorldObject_sphere;
class GraphicsObject_sphere : public IGraphicsObject
{
public:
	GraphicsObject_sphere(WorldObject_sphere*);
	~GraphicsObject_sphere();
	void Init();
	void SetMesh();

};

