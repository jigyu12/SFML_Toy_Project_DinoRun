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
	TEX_MANAGER.Load("cloud1", "Resource/cloud.png");
	GameObject* cloud1 = AddGameObject(new SpriteGameObject("cloud1", "cloud1"));
	cloud1->SetOrigin(Origins::MC);
	cloud1->SetPosition({ GET_SINGLETON(Game).GetWindowWidth() / 2, (GET_SINGLETON(Game).GetWindowHeight() / 2) + -250});
	cloud1->SetSpeed({ -200.f,0.f });

	TEX_MANAGER.Load("cloud2", "Resource/cloud.png");
	GameObject* cloud2 = AddGameObject(new SpriteGameObject("cloud2", "cloud2"));
	cloud2->SetOrigin(Origins::MC);
	cloud2->SetPosition({ GET_SINGLETON(Game).GetWindowWidth(), (GET_SINGLETON(Game).GetWindowHeight() / 2) + -350});
	cloud2->SetSpeed({ -200.f,0.f });

	TEX_MANAGER.Load("player", "Resource/player.png");
	GameObject* player = AddGameObject(new SpriteGameObject("player", "player"));
	player->SetOrigin(Origins::MC);
	player->SetPosition({ 200, GET_SINGLETON(Game).GetWindowHeight() / 2 + 180 });
	player->SetSpeed({ 0.f,0.f });

	TEX_MANAGER.Load("ground1", "Resource/ground.png");
	GameObject* ground1 = AddGameObject(new SpriteGameObject("ground1", "ground1"));
	ground1->SetOrigin(Origins::TL);
	ground1->SetPosition({ 0, GET_SINGLETON(Game).GetWindowHeight() / 2 + 200 });
	ground1->SetSpeed({ -400.f,0.f });

	TEX_MANAGER.Load("ground2", "Resource/ground.png");
	GameObject* ground2 = AddGameObject(new SpriteGameObject("ground2", "ground2"));
	ground2->SetOrigin(Origins::TL);
	ground2->SetPosition({ 2100, GET_SINGLETON(Game).GetWindowHeight() / 2 + 200});
	ground2->SetSpeed({ -400.f,0.f });

	TEX_MANAGER.Load("cactus1", "Resource/cactus1.png");
	GameObject* cactus1 = AddGameObject(new SpriteGameObject("cactus1", "cactus1"));
	cactus1->SetOrigin(Origins::MC);
	cactus1->SetPosition({ 1800, GET_SINGLETON(Game).GetWindowHeight() / 2 + 180 });
	cactus1->SetSpeed({ -400.f,0.f });

	TEX_MANAGER.Load("cactus2", "Resource/cactus2.png");
	GameObject* cactus2 = AddGameObject(new SpriteGameObject("cactus2", "cactus2"));
	cactus2->SetOrigin(Origins::MC);
	cactus2->SetPosition({ 2200, GET_SINGLETON(Game).GetWindowHeight() / 2 + 180 });
	cactus2->SetSpeed({ -400.f,0.f });

	TEX_MANAGER.Load("cactus3", "Resource/cactus3.png");
	GameObject* cactus3 = AddGameObject(new SpriteGameObject("cactus3", "cactus3"));
	cactus3->SetOrigin(Origins::MC);
	cactus3->SetPosition({ 2600, GET_SINGLETON(Game).GetWindowHeight() / 2 + 180 });
	cactus3->SetSpeed({ -400.f,0.f });
	
	FONT_MANAGER.Load("font", "Fonts/KOMIKAP_.ttf");
	GameObject* gameOver = AddGameObject(new TextGameObject("font", "       GAME OVER!!!\n\nPress Space to MainTitle", "gameOver", sf::Color::Transparent));
	gameOver->SetPosition({ GET_SINGLETON(Game).GetWindowWidth() / 2, (GET_SINGLETON(Game).GetWindowHeight() / 2 - 150) });
	gameOver->SetOrigin(Origins::MC);

	std::string fTemp = std::to_string(GET_SINGLETON(GameManager).GetScore());
	std::string f = fTemp.substr(0, fTemp.find('.') + 2);
	std::string temp = "SCORE: " + f;
	GameObject* score = AddGameObject(new TextGameObject("font", temp, "score", sf::Color::Black));
	score->SetPosition({ 50 ,  50 });
	score->SetOrigin(Origins::TL);
	Scene::Init();
}

void GameScene::Update(float dt)
{
	Scene::Update(dt);

	if (GET_SINGLETON(GameManager).IsSpriteCollision(FindGameObjectSingle("player"), FindGameObjectSingle("cactus1")))
	{
		GET_SINGLETON(GameManager).SetLive(false);
	}

	if (!GET_SINGLETON(GameManager).IsLive())
	{
		if (GET_SINGLETON(InputManager).GetKeyDown(sf::Keyboard::Space))
		{
			GET_SINGLETON(SceneManager).ChangeScene(SceneIds::MainTitleScene);
		}
	}
}

void GameScene::Render(sf::RenderWindow& window)
{
	Scene::Render(window);
}

void GameScene::Release()
{
	Scene::Release();

	TEX_MANAGER.Unload("cloud1");
	TEX_MANAGER.Unload("cloud2");
	TEX_MANAGER.Unload("player"); 
	TEX_MANAGER.Unload("ground1"); 
	TEX_MANAGER.Unload("ground2"); 
	TEX_MANAGER.Unload("cactus1"); 
	TEX_MANAGER.Unload("cactus2"); 
	TEX_MANAGER.Unload("cactus3"); 
	FONT_MANAGER.Unload("font");
}