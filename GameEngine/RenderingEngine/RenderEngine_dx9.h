#pragma once
#include "IRenderer.h"
#include "../BulletPhysicsEngine/IWorldObject.h"
#include "IGraphicsObject.h"
#pragma comment (lib, "d3d9.lib")
#pragma comment (lib, "d3dx9.lib")

class RenderEngine_dx9 : public IRenderer {
public:
	RenderEngine_dx9(int w, int h);
	void init_frame(void*, void*, void*);
	void Render(IGraphicsObject*);
	void end_frame();
	void SetWindow();
	void SetHandle(void*);
	void clean();
	void Draw(void*, void*, void*);
	void SetNum(size_t);
	void* GetDevice();
	void SetList(IWorldObject*);
	~RenderEngine_dx9();
};
