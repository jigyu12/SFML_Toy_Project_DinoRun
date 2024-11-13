#include "pch.h"

void InputManager::Init()
{
	downKeyList.clear();
	holdKeyList.clear();
	upKeyList.clear();

	downMouseList.clear();
	holdMouseList.clear();
	upMouseList.clear();
}

void InputManager::Update(const sf::Event& ev)
{
	switch (ev.type)
	{
	case sf::Event::KeyPressed:
	{
		holdKeyList[ev.key.code] = true;
		downKeyList[ev.key.code] = true;
	}
		break;
	case sf::Event::KeyReleased:
	{
		holdKeyList[ev.key.code] = false;
		upKeyList[ev.key.code] = true;
	}
		break;
	case sf::Event::MouseButtonPressed:
	{
		holdMouseList[ev.mouseButton.button] = true;
		downMouseList[ev.mouseButton.button] = true;
	}
		break;
	case sf::Event::MouseButtonReleased:
	{
		holdMouseList[ev.mouseButton.button] = false;
		upMouseList[ev.mouseButton.button] = true;
	}
		break;
	default:
	{

	}
		break;
	}
}

void InputManager::Render()
{

}

void InputManager::Release()
{

}

bool InputManager::GetKeyDown(const sf::Keyboard::Key key)
{
	return downKeyList[key];
}

bool InputManager::GetKeyHold(const sf::Keyboard::Key key)
{
	return holdKeyList[key];
}

bool InputManager::GetKeyUp(const sf::Keyboard::Key key)
{
	return upKeyList[key];
}

bool InputManager::GetMouseDown(const sf::Mouse::Button mouseButton)
{
	return downMouseList[mouseButton];
}

bool InputManager::GetMouseHold(const sf::Mouse::Button mouseButton)
{
	return holdMouseList[mouseButton];
}
bool InputManager::GetMouseUp(const sf::Mouse::Button mouseButton)
{
	return upMouseList[mouseButton];
}

sf::Vector2i InputManager::GetMousePosition(const sf::RenderWindow& window) const
{
	return mouse.getPosition(window);
}

void InputManager::Clear()
{
	for (auto iter = downKeyList.begin(); iter != downKeyList.end(); iter++)
	{
		iter->second = false;
	}
	for (auto iter = upKeyList.begin(); iter != upKeyList.end(); iter++)
	{
		iter->second = false;
	}
	for (auto iter = downMouseList.begin(); iter != downMouseList.end(); iter++)
	{
		iter->second = false;
	}
	for (auto iter = upMouseList.begin(); iter != upMouseList.end(); iter++)
	{
		iter->second = false;
	}
}