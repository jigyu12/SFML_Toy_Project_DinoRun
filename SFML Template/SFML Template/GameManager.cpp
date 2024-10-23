#include "pch.h"

void GameManager::Init()
{
	time = 0.f;
	deltaTime = 0.f;
	realTime = 0.f;
	realDeltaTime = 0.f;
	timeScale = 1.f;

	score = 0;
}

void GameManager::Update()
{

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