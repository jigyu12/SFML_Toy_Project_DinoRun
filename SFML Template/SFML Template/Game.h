#pragma once

class Game
{
	DECLARE_SINGLETON(Game);

public:
	void Init(const int width, const int height, const std::string& name);
	void Do();
	void Release();

	float GetWindowWidth() const { return (float)windowWidth; }
	float GetWindowHeight() const { return (float)windowHeight; }

private:
	void Update(float dt);
	void Render(sf::RenderWindow& window);

	sf::RenderWindow window;
	sf::Clock clock;

	int windowWidth;
	int windowHeight;
};