#include "pch.h"
#include "SpriteGameObject.h"

void GameManager::Init()
{
	time = 0.f;
	deltaTime = 0.f;
	realTime = 0.f;
	realDeltaTime = 0.f;
	timeScale = 1.f;

	score = 0;

	isLive = true;
}

void GameManager::Update()
{
	score += 40 * deltaTime;
}

void GameManager::Render()
{

}

void GameManager::Release()
{

}

void GameManager::CalculateTime(sf::Time& dt)
{
    realDeltaTime = deltaTime = dt.asSeconds();
    deltaTime *= timeScale;
    realTime += realDeltaTime;
    time += deltaTime;
}

bool GameManager::IsSpriteCollision(GameObject* obj1, GameObject* obj2)
{
	SpriteGameObject* player = dynamic_cast<SpriteGameObject*>(obj1);
	SpriteGameObject* cactus = dynamic_cast<SpriteGameObject*>(obj2);

	float originDistance = sqrt(pow(player->GetPosition().x - cactus->GetPosition().x, 2) + pow(player->GetPosition().y - cactus->GetPosition().y, 2));

	if (originDistance < 160.f)
	{
		return true;
	}

	return false;
}