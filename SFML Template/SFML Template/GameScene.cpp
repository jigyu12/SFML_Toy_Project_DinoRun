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
	TEX_MANAGER.Load("player", "Resource/bird.png");
	GameObject* player = AddGameObject(new SpriteGameObject("player", "player"));
	player->SetOrigin(Origins::MC);
	player->SetPosition({ 1920 / 2, 1080 / 2 });

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
	Scene::Release();

	TEX_MANAGER.Unload("player");
}