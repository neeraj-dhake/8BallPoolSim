#pragma once
#include "../BulletPhysicsEngine/IWorldObject.h"
#include "../BulletPhysicsEngine/BulletWorld.h"
#include "../BulletPhysicsEngine/Vector3D.h"
#include <vector>
class SceneManager;

class Scene {
protected:
	bool is_active;
	SceneManager* Manager;
	Vector3D camera_position;
	Vector3D camera_lookat;
	Vector3D camera_up;
	Vector3D lightDirec;
	float dt = 0.016f;
public:
	Scene();
	bool IsActive();
	std::vector<IWorldObject*> objects_in_scene;
	Vector3D GetCameraPosition();
	Vector3D GetCameraLookAt();
	Vector3D GetCameraUp();
	Vector3D GetLight();
	void SetCamera(void*, void*, void*);
	void SetLight(void* direc);
	void SetActive(bool);
	void SetManager(SceneManager*);
	void AddObject(IWorldObject*);
	void DeleteObject(IWorldObject*);
	virtual void SetScene() = 0;
	virtual void UpdateScene();
	BulletWorld *PhyWorld;
	void ActivateScene();
	void DeactivateScene();
	
	
	~Scene();
};

