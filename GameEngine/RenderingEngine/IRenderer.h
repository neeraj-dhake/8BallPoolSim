#pragma once
#include "../BulletPhysicsEngine/IWorldObject.h"
#include <vector>
class IRenderer {
protected:
	void* hwnd;
	int SCREEN_WIDTH;
	int SCREEN_HEIGHT;
	void* intrfc;
	void* device;
	void* light;
	IWorldObject* list_to_render;
	size_t num_objects;
public:
	IRenderer();
	virtual void init_frame(void*, void*, void*) = 0;
	virtual void Render(IGraphicsObject*) = 0;
	virtual void end_frame() = 0;
	virtual void SetWindow() = 0;
	virtual void SetHandle(void*) = 0;
	virtual void clean() = 0;
	virtual void Draw(void*, void*, void*) = 0;
	virtual void SetNum(size_t) = 0;
	virtual void* GetDevice() = 0;
	virtual void SetList(IWorldObject*) = 0;
	~IRenderer();
};

