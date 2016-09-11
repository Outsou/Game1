#include "stdafx.h"
#include "InputManager.h"

InputManager::InputManager()
{
}

InputManager::~InputManager()
{
}

bool InputManager::keyDown(sf::Keyboard::Key key) const
{
	return sf::Keyboard::isKeyPressed(key);
}