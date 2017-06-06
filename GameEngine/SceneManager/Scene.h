#pragma once
#include "../GameplayEngine/IWorldObject.h"
#include <list>
class SceneManager;

class Scene {
protected:
	unsigned int NameHash;
	bool IsActive;
	SceneManager* Manager;
	std::list<IWorldObject*> objects_in_scene;
public:
	Scene();
	bool IsActive();
	void SetActive(bool);
	void SetManager(SceneManager*);
	void AddObject(IWorldObject*);
	void DeleteObject(IWorldObject*);
	~Scene();
};

