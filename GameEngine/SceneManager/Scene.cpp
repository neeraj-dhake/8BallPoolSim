#include "Scene.h"

Scene::Scene() {
}

bool Scene::IsActive() {
	return is_active;
}

void Scene::SetActive(bool active) {
	is_active = active;
}

void Scene::SetManager(SceneManager* manager) {
	Manager = manager;
}

void Scene::AddObject(IWorldObject* obj) {
	objects_in_scene.push_back(obj);
}

void Scene::DeleteObject(IWorldObject* obj) {
	objects_in_scene.remove(obj);
}

Scene::~Scene() {
}
