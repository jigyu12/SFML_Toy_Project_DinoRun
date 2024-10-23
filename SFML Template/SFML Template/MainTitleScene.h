#pragma once

class MainTitleScene : public Scene
{
public:
	MainTitleScene();
	~MainTitleScene() = default;

	void Init() override;
	void Update(float dt) override;
	void Render(sf::RenderWindow& window) override;
	void Release() override;
};