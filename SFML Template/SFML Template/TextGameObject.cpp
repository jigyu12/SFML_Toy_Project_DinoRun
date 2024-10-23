#include "pch.h"
#include "TextGameObject.h"

TextGameObject::TextGameObject(const std::string& fontId, const std::string& textString, const std::string& name)
	: GameObject(name), fontId(fontId), textString(textString)
{
}

void TextGameObject::Init()
{
	text.setFont(FONT_MANAGER.Get(fontId));
	text.setString(textString);
	text.setCharacterSize(100);
	text.setFillColor(sf::Color::Black);
	SetOrigin(originPreset);
}

void TextGameObject::Update(float dt)
{

}

void TextGameObject::Render(sf::RenderWindow& window)
{
	window.draw(text);
}

void TextGameObject::Release()
{

}

void TextGameObject::SetOrigin(Origins preset)
{
	originPreset = preset;
	origin = Utils::SetOrigin(text, originPreset);
}

void TextGameObject::SetOrigin(const sf::Vector2f& newOrigin)
{
	originPreset = Origins::Custom;
	origin = newOrigin;
	text.setOrigin(origin);
}

void TextGameObject::SetPosition(const sf::Vector2f& pos)
{
	text.setPosition(pos);
}