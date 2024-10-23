#include "pch.h"
#include "MainTitleScene.h"
#include "SpriteGameObject.h"
#include "TextGameObject.h"

MainTitleScene::MainTitleScene()
	: Scene(SceneIds::MainTitleScene)
{
}

void MainTitleScene::Init()
{
	std::cout << "MainTitleScene::Init()" << std::endl;

	FONT_MANAGER.Load("font", "Fonts/KOMIKAP_.ttf");
	GameObject* obj2 = AddGameObject(new TextGameObject("font", "MainTitle", "scoreText"));
	obj2->SetOrigin(Origins::MC);
	obj2->SetPosition({ 1920 / 2, 1080 / 2 });

	Scene::Init();
}

void MainTitleScene::Update(float dt)
{
	Scene::Update(dt);
	if (GET_SINGLETON(InputManager).GetKeyDown(sf::Keyboard::Space))
	{
		GET_SINGLETON(SceneManager).ChangeScene(SceneIds::GameScene);
	}
}

void MainTitleScene::Render(sf::RenderWindow& window)
{
	Scene::Render(window);
}

void MainTitleScene::Release()
{
	std::cout << "MainTitleScene::Release()" << std::endl;

	Scene::Release();

	FONT_MANAGER.Unload("font");
}