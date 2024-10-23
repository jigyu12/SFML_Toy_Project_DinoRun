#include "pch.h"

Scene::Scene(SceneIds sceneId)
	: sceneId(sceneId)
{
}

void Scene::Init()
{
	for (auto obj : gameObjectList)
	{
		obj->Init();
	}
}

void Scene::Update(float dt)
{
	for (auto obj : gameObjectList)
	{
		if (!obj->IsActive())
			continue;

		obj->Update(dt);
	}
}

void Scene::Render(sf::RenderWindow& window)
{
	for (auto obj : gameObjectList)
	{
		if (!obj->IsActive())
			continue;

		obj->Render(window);
	}
}

void Scene::Release()
{
	for (auto obj : gameObjectList)
	{
		obj->Release();
		delete obj;
	}
	gameObjectList.clear();
}

GameObject* Scene::AddGameObject(GameObject* obj)
{
	if (std::find(gameObjectList.begin(), gameObjectList.end(), obj) == gameObjectList.end())
	{
		gameObjectList.push_back(obj);
	}

	return obj;
}

void Scene::RemoveGameObjectSingle(GameObject* obj)
{
	gameObjectList.remove(obj);
}

int Scene::RemoveGameObjectAll(const std::string& name, std::list<GameObject*>& objectList)
{
	int count = 0;

	for (auto iter = gameObjectList.begin(); iter != gameObjectList.end();) 
	{
		if ((*iter)->GetName() == name)
		{
			iter = gameObjectList.erase(iter);
			count++;
		}
		else
		{
			iter++;
		}
	}

	return count;
}

GameObject* Scene::FindGameObjectSingle(const std::string& name)
{
	for (auto obj : gameObjectList)
	{
		if (obj->GetName() == name)
		{
			return obj;
		}
	}

	return nullptr;
}

int Scene::FindGameObjectAll(const std::string& name, std::list<GameObject*>& objectList)
{
	int count = 0;

	for (auto obj : gameObjectList)
	{
		if (obj->GetName() == name)
		{
			objectList.push_back(obj);
			count++;
		}
	}

	return count;
}