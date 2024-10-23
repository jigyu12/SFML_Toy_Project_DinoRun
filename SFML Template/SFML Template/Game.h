#pragma once

class Game
{
	DECLARE_SINGLETON(Game);

public:
	void Init(const int width, const int height, const std::string& name);
	void Do();
	void Release();

	int GetWindowWidth() const { return windowWidth; }
	int GetWindowHeight() const { return windowHeight; }

private:
	void Update();
	void Render();

	sf::RenderWindow window;
	sf::Clock clock;

	int windowWidth;
	int windowHeight;
};