#include "pch.h"

GameObject::GameObject(const std::string& name)
	: name(name)
{
	active = true;
	position = { 0.f, 0.f };
	origin = { 0.f, 0.f };
	originPreset = Origins::TL;
}