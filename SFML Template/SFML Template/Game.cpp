#include "pch.h"

void Game::Init(const int width, const int height, const std::string& name)
{
    windowWidth = width;
    windowHeight = height;

	window.create(sf::VideoMode(width, height), name);

    GET_SINGLETON(GameManager).Init();
    GET_SINGLETON(InputManager).Init();
    TEX_MANAGER.Init();
    GET_SINGLETON(SceneManager).Init();
}

void Game::Do()
{
    while (window.isOpen())
    {
        sf::Time dt = clock.restart();
        GET_SINGLETON(GameManager).CalculateTime(dt);

        GET_SINGLETON(InputManager).Clear();

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            GET_SINGLETON(InputManager).Update(event);
        }

        window.clear(sf::Color(255,255,255));
        
        Update(GET_SINGLETON(GameManager).GetDeltaTime());
        Render(window);

        window.display();
    }
}

void Game::Update(float dt)
{
    GET_SINGLETON(GameManager).Update();
    TEX_MANAGER.Update();
    GET_SINGLETON(SceneManager).Update(dt);
}

void Game::Render(sf::RenderWindow& window)
{
    GET_SINGLETON(GameManager).Render();
    GET_SINGLETON(InputManager).Render();
    TEX_MANAGER.Render();
    GET_SINGLETON(SceneManager).Render(window);
}

void Game::Release()
{
    GET_SINGLETON(GameManager).Release();
    GET_SINGLETON(InputManager).Release();
    TEX_MANAGER.Release();
    GET_SINGLETON(SceneManager).Release();
}