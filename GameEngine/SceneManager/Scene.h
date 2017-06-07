#pragma once
#include "../GameplayEngine/IWorldObject.h"
#include "../GameplayEngine/Vector3D.h"
#include <list>
class SceneManager;

class Scene{
protected:
	bool is_active;
	SceneManager* Manager;
	Vector3D camera_position;
	Vector3D camera_lookat;
	Vector3D camera_up;
public:
	Scene();
	bool IsActive();
	std::list<IWorldObject*> objects_in_scene;
	Vector3D GetCameraPosition();
	Vector3D GetCameraLookAt();
	Vector3D GetCameraUp();
	void SetCamera(void*, void*, void*);
	void SetActive(bool);
	void SetManager(SceneManager*);
	void AddObject(IWorldObject*);
	void DeleteObject(IWorldObject*);
	virtual void SetScene() = 0;
	~Scene();
};

