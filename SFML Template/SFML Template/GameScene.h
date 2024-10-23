#pragma once

class GameScene : public Scene
{
public:
	GameScene();
	~GameScene() = default;

	void Init() override;
	void Update(float dt) override;
	void Render(sf::RenderWindow& window) override;
	void Release() override;
};