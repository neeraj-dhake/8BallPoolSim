#pragma once
#include "../GameplayEngine/IWorldObject.h"
#include "../GameplayEngine/Vector3D.h"
#include <list>
class SceneManager;

class Scene{
protected:
	bool is_active;
	SceneManager* Manager;
	std::list<IWorldObject*> objects_in_scene;
	Vector3D camera_position;
	Vector3D camera_lookat;
	Vector3D camera_up;
public:
	Scene();
	bool IsActive();
	void SetActive(bool);
	void SetManager(SceneManager*);
	void AddObject(IWorldObject*);
	void DeleteObject(IWorldObject*);
	~Scene();
};

