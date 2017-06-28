#include "Scene.h"
#include "SceneManager.h"

Scene::Scene() {
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

Vector3D Scene::GetLight()
{
	return lightDirec;
}

void Scene::SetCamera(void* pos, void* lookat, void* up) {
	camera_position = *(Vector3D*)pos;
	camera_lookat = *(Vector3D*)lookat;
	camera_up = *(Vector3D*)up;
}
void Scene::SetLight(void* direc)
{
	lightDirec = *(Vector3D*)direc;
}

void Scene::SetManager(SceneManager* manager) {
	Manager = manager;
}

void Scene::AddObject(IWorldObject* obj) {


	if(obj->GetgObject() != nullptr)
	{
		(obj->GetgObject())->SetDevice(Manager->render_engine->GetDevice());
		(obj->GetgObject())->Init();
	}

	obj->CreateObject(Manager->PhyWorld);
	objects_in_scene.push_back(obj);



	
}

void Scene::DeleteObject(IWorldObject* obj) {
}

void Scene::UpdateScene(){
}

void Scene::ActivateScene() {
	for (size_t i = 0; i < objects_in_scene.size() ; i++) {
		objects_in_scene[i]->CreateObject(Manager->PhyWorld);
	}
}

void Scene::DeactivateScene() {
	for (size_t i = 0; i < objects_in_scene.size(); i++) {
		Manager->PhyWorld->GetDynamicWorld()->removeCollisionObject(objects_in_scene[i]->GetpObject());
	}
}

Scene::~Scene() {
	objects_in_scene.clear();
}
