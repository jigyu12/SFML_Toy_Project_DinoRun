#pragma once

class SpriteGameObject : public GameObject
{
public:
	SpriteGameObject(const std::string& textureId, const std::string& name);
	~SpriteGameObject() = default;

	void Init() override;
	void Update(float dt) override;
	void Render(sf::RenderWindow& window) override;
	void Release() override;

	void SetOrigin(Origins preset) override;
	void SetOrigin(const sf::Vector2f& newOrigin) override;
	void SetPosition(const sf::Vector2f& pos) override;

	void Jump(float dt);

	sf::FloatRect GetLocalBounds()  const;

protected:
	sf::Sprite sprite;
	std::string textureId;

	bool isJump;
	float velocityY = 0.0f;
};