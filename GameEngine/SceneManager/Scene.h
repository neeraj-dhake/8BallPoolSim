#pragma once
#include "../GameplayEngine/IWorldObject.h"
#include "../GameplayEngine/Vector3D.h"
#include <list>
class SceneManager;

class Scene {
protected:
	bool is_active;
	SceneManager* Manager;
	std::list<IWorldObject*> objects_in_scene;
	Vector3D camera_position;
	Vector3D camera_lookat;
	Vector3D camera_up;
public:
	Scene();
	virtual bool IsActive() = 0;
	virtual void SetActive(bool) = 0;
	virtual void SetManager(SceneManager*) = 0;
	virtual void AddObject(IWorldObject*) = 0;
	virtual void DeleteObject(IWorldObject*) = 0;
	~Scene();
};

