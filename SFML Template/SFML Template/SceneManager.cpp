#include "pch.h"
#include "MainTitleScene.h"
#include "GameScene.h"

void SceneManager::Init()
{
	Release();

	startScene = SceneIds::MainTitleScene;

	scenes.push_back(new MainTitleScene());
	scenes.push_back(new GameScene());

	for (auto scene : scenes)
	{
		scene->Init();
	}

	currentScene = startScene;
	scenes[(int)currentScene]->Init();
}

void SceneManager::Update(float dt)
{
	scenes[(int)currentScene]->Update(dt);
}

void SceneManager::Render(sf::RenderWindow& window)
{
	scenes[(int)currentScene]->Render(window);
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
	scenes[(int)currentScene]->Release();
	currentScene = id;
	scenes[(int)currentScene]->Init();
}