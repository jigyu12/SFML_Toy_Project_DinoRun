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
	isJump = false;
}

void SpriteGameObject::Update(float dt)
{
	if (GET_SINGLETON(GameManager).IsLive())
	{
		if (name == "player" && GET_SINGLETON(InputManager).GetKeyDown(sf::Keyboard::Space))
		{
			Jump(dt);
		}
		if (name == "player" && isJump)
		{
			velocityY += gravity * dt;

			SetPosition({ sprite.getPosition().x, sprite.getPosition().y + (velocityY * dt) });

			if (sprite.getPosition().y >= GET_SINGLETON(Game).GetWindowHeight() / 2 + 180) 
			{
				sprite.setPosition(sprite.getPosition().x, GET_SINGLETON(Game).GetWindowHeight() / 2 + 180);
				isJump = false;
				velocityY = 0.0f;
			}

			return;
		}
		if (name == "ground1")
		{
			if (sprite.getPosition().x < -2100)
			{
				SetPosition({ 2100, GET_SINGLETON(Game).GetWindowHeight() / 2 + 200 });
			}
		}
		if (name == "ground2")
		{
			if (sprite.getPosition().x < -2100)
			{
				SetPosition({ 2100, GET_SINGLETON(Game).GetWindowHeight() / 2 + 200 });
			}
		}
		if (name == "cloud1")
		{
			if (sprite.getPosition().x < -95)
			{
				SetPosition({ 1950, (GET_SINGLETON(Game).GetWindowHeight() / 2) - 250 });
			}
		}
		if (name == "cloud2")
		{
			if (sprite.getPosition().x < -95)
			{
				SetPosition({ 1950, (GET_SINGLETON(Game).GetWindowHeight() / 2) - 350 });
			}
		}
		if (name == "cactus1")
		{
			if (sprite.getPosition().x < -105)
			{
				SetPosition({ 1950 + (float)Utils::GetRandNum_C(200), GET_SINGLETON(Game).GetWindowHeight() / 2 + 180});
			}
		}
		if (name == "cactus2")
		{
			if (sprite.getPosition().x < -105)
			{
				SetPosition({ 1950 + (float)Utils::GetRandNum_C(200), GET_SINGLETON(Game).GetWindowHeight() / 2 + 180 });
			}
		}
		if (name == "cactus3")
		{
			if (sprite.getPosition().x < -105)
			{
				SetPosition({ 1950 + (float)Utils::GetRandNum_C(200), GET_SINGLETON(Game).GetWindowHeight() / 2 + 180 });
			}
		}
		if (name == "cactus4")
		{
			if (sprite.getPosition().x < -105)
			{
				SetPosition({ 1950 + (float)Utils::GetRandNum_C(200), GET_SINGLETON(Game).GetWindowHeight() / 2 + 180 });
			}
		}
		
		SetPosition({ sprite.getPosition().x + (speed.x * dt), sprite.getPosition().y + (speed.y * dt) });
	}
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

void SpriteGameObject::Jump(float dt)
{
	if (!isJump) 
	{
		isJump = true;
		velocityY = -500.f;
	}
}

sf::FloatRect SpriteGameObject::GetLocalBounds() const
{
	return sprite.getLocalBounds();
}