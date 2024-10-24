#include "pch.h"
#include "SpriteGameObject.h"

SpriteGameObject::SpriteGameObject(const std::string& textureId, const std::string& name)
	: GameObject(name), textureId(textureId)
{
}

void SpriteGameObject::Init()
{
	sprite.setTexture(TEX_MANAGER.Get(textureId));
	SetOrigin(originPreset);
}

void SpriteGameObject::Update(float dt)
{
	sprite.setPosition({sprite.getPosition().x + (speed.x * dt), sprite.getPosition().y + (speed.y * dt) });
}

void SpriteGameObject::Render(sf::RenderWindow& window)
{
	window.draw(sprite);
}

void SpriteGameObject::Release()
{
	
}

void SpriteGameObject::SetOrigin(Origins preset)
{
	originPreset = preset;
	origin = Utils::SetOrigin(sprite, originPreset);
	sprite.setOrigin(origin);
}

void SpriteGameObject::SetOrigin(const sf::Vector2f& newOrigin)
{
	originPreset = Origins::Custom;
	origin = newOrigin;
	sprite.setOrigin(origin);
}

void SpriteGameObject::SetPosition(const sf::Vector2f& pos)
{
	sprite.setPosition(pos);
	position = sprite.getPosition();
}

sf::FloatRect SpriteGameObject::GetLocalBounds() const
{
	return sprite.getLocalBounds();
}