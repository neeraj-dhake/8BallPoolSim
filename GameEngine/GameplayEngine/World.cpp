#include "World.h"
#include "../RenderingEngine/RenderEngine_dx9.h"


World::World(int width, int height, void* HWND) {
	engine = new RenderEngine_dx9(width, height);
	engine->SetHandle(HWND);
	engine->SetWindow();
}

void World::SetRenderList() {
	int num = list_of_objects.size();
	IWorldObject* RenderList = new IWorldObject[num];
	for (int i = 0; i < num; i++) {
		RenderList[i] = *list_of_objects[i];
	}
	engine->SetList(RenderList);
	engine->SetNum(num);
}

void World::AddObject(IWorldObject* temp) {
	list_of_objects.push_back(temp);
	(temp->GetgObject())->SetDevice(engine->GetDevice());
	(temp->GetgObject())->Init();
}

void World::Draw(void* pos, void* lookat, void* up) {
	SetRenderList();
	engine->Draw(pos, lookat, up);
}

void World::SetHandle(void* HWND) {
	engine->SetHandle(HWND);
}

void World::SetWindow() {
	engine->SetWindow();
}

World::~World(){
	delete engine;
}
