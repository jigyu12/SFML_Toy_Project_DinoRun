#pragma once

class TextGameObject : public GameObject
{
public:
	TextGameObject(const std::string& fontId, const std::string& textString, const std::string& name);
	~TextGameObject() = default;

	void Init() override;
	void Update(float dt) override;
	void Render(sf::RenderWindow& window) override;
	void Release() override;

	void SetOrigin(Origins preset) override;
	void SetOrigin(const sf::Vector2f& newOrigin) override;
	void SetPosition(const sf::Vector2f& pos) override;

protected:
	sf::Text text;
	std::string textString;
	std::string fontId;
};