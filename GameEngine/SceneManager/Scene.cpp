#include "Scene.h"
#include "SceneManager.h"

Scene::Scene() {
}

bool Scene::IsActive() {
	return is_active;
}

void Scene::SetActive(bool active) {
	is_active = active;
}

Vector3D Scene::GetCameraPosition() {
	return camera_position;
}

Vector3D Scene::GetCameraLookAt() {
	return camera_lookat;
}

Vector3D Scene::GetCameraUp() {
	return camera_up;
}

void Scene::SetCamera(void* pos, void* lookat, void* up) {
	camera_position = *(Vector3D*)pos;
	camera_lookat = *(Vector3D*)lookat;
	camera_up = *(Vector3D*)up;
}

void Scene::SetManager(SceneManager* manager) {
	Manager = manager;
}

void Scene::AddObject(IWorldObject* obj) {
	(obj->GetgObject())->SetDevice(Manager->render_engine->GetDevice());
	(obj->GetgObject())->Init();
	obj->CreateObject(Manager->PhyWorld);
	objects_in_scene.push_back(obj);
	// create is to be called

	
}

void Scene::DeleteObject(IWorldObject* obj) {
	//objects_in_scene.remove(obj);
	// To be implemented


}

void Scene::UpdateScene()
{
	/*for (unsigned int i = 0;i < objects_in_scene.size();i++)
		(objects_in_scene[i]->GetpObject())->Update(dt);*/
}

Scene::~Scene() {
	objects_in_scene.clear();
}
