#pragma once

class InputManager
{
	DECLARE_SINGLETON(InputManager);

public:
	void Init();
	void Update(const sf::Event& ev);
	void Render();
	void Release();

	bool GetKeyDown(const sf::Keyboard::Key key);
	bool GetKeyHold(const sf::Keyboard::Key key);
	bool GetKeyUp(const sf::Keyboard::Key key);
	bool GetMouseDown(const sf::Mouse::Button mouseButton);
	bool GetMouseHold(const sf::Mouse::Button mouseButton);
	bool GetMouseUp(const sf::Mouse::Button mouseButton);
	sf::Vector2i GetMousePosition(const sf::RenderWindow& window) const;

	void Clear();

private:
	sf::Mouse mouse;

	std::unordered_map<sf::Keyboard::Key, bool> downKeyList;
	std::unordered_map<sf::Keyboard::Key, bool> holdKeyList;
	std::unordered_map<sf::Keyboard::Key, bool> upKeyList;
	std::unordered_map<sf::Mouse::Button, bool> downMouseList;
	std::unordered_map<sf::Mouse::Button, bool> holdMouseList;
	std::unordered_map<sf::Mouse::Button, bool> upMouseList;
};