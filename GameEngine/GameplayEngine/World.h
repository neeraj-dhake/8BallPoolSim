#include "IWorldObject.h"
#include "../RenderingEngine/IRenderer.h"
#pragma once
class World
{
	std::vector <IWorldObject*> list_of_objects;
	IRenderer* engine;
public:
	World(int width, int height, void* HWND);
	void SetRenderList();
	void AddObject(IWorldObject*);
	void Draw(void*, void*, void*);
	~World();
};

