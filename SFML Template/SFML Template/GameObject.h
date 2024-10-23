#pragma once

class GameObject
{
public:
	virtual void Init() = 0;
	virtual void Update(float dt) = 0;
	virtual void Render(sf::RenderWindow& window) = 0;
	virtual void Release() = 0;

	virtual void SetOrigin(Origins preset) = 0;
	virtual void SetOrigin(const sf::Vector2f& newOrigin) = 0;
	virtual void SetPosition(const sf::Vector2f& pos) = 0;

	GameObject(const std::string& name);
	virtual ~GameObject() = default;

	bool IsActive() const { return active; }
	const std::string& GetName() const { return name; }
	sf::Vector2f GetPosition() const { return position; }
	sf::Vector2f GetOrigin() const { return origin; }
	Origins GetOriginPreset() const { return originPreset; }

	void SetName(const std::string& n) { name = n; }
	void SetActive(const bool a) { active = a; }

protected:
	bool active;

	std::string name;

	sf::Vector2f position;
	sf::Vector2f origin;

	Origins originPreset;
};