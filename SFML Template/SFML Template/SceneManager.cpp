#include "pch.h"
#include "MainTitleScene.h"
#include "GameScene.h"

void SceneManager::Init()
{
	Release();

	startSceneId = SceneIds::MainTitleScene;

	scenes.push_back(new MainTitleScene());
	scenes.push_back(new GameScene());

	currentSceneId = startSceneId;
	currentScene = scenes[(int)currentSceneId];
	scenes[(int)currentSceneId]->Init();
}

void SceneManager::Update(float dt)
{
	scenes[(int)currentSceneId]->Update(dt);
}

void SceneManager::Render(sf::RenderWindow& window)
{
	scenes[(int)currentSceneId]->Render(window);
}

void SceneManager::Release()
{
	for (auto scene : scenes)
	{
		scene->Release();
		delete scene;
	}
	scenes.clear();
}

void SceneManager::ChangeScene(SceneIds id)
{
	scenes[(int)currentSceneId]->Release();
	currentSceneId = id;
	currentScene = scenes[(int)currentSceneId];
	scenes[(int)currentSceneId]->Init();
}