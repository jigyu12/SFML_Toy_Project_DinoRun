#include "pch.h"
#include "GameScene.h"
#include "SpriteGameObject.h"
#include "TextGameObject.h"

GameScene::GameScene()
	: Scene(SceneIds::GameScene)
{
}

void GameScene::Init()
{
	std::cout << "GameScene::Init()" << std::endl;

	TEX_MANAGER.Load("player", "Resource/bird.png");
	GameObject* obj = AddGameObject(new SpriteGameObject("player", "player"));
	obj->SetOrigin(Origins::MC);
	obj->SetPosition({ 1920 / 2, 1080 / 2 });

	Scene::Init();
}

void GameScene::Update(float dt)
{
	Scene::Update(dt);
	if (GET_SINGLETON(InputManager).GetKeyDown(sf::Keyboard::Space))
	{
		GET_SINGLETON(SceneManager).ChangeScene(SceneIds::MainTitleScene);
	}
}

void GameScene::Render(sf::RenderWindow& window)
{
	Scene::Render(window);
}

void GameScene::Release()
{
	std::cout << "GameScene::Release()" << std::endl;

	Scene::Release();

	TEX_MANAGER.Unload("player");
}