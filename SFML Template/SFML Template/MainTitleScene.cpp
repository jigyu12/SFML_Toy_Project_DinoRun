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
	GET_SINGLETON(GameManager).SetScore(-GET_SINGLETON(GameManager).GetScore());

	FONT_MANAGER.Load("font", "Fonts/KOMIKAP_.ttf");
	GameObject* mainTitleText = AddGameObject(new TextGameObject("font", "        Dino Run!\n\nPress Space to Start!", "mainTitleText", sf::Color::Black));
	mainTitleText->SetOrigin(Origins::MC);
	mainTitleText->SetPosition({ 1920 / 2, 1080 / 2 - 50 });

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
	Scene::Release();

	FONT_MANAGER.Unload("font");
}