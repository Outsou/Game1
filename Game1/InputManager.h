#pragma once
#include "SFML\Window.hpp"

class InputManager 
{
public:
	InputManager();
	~InputManager();

	bool keyDown(sf::Keyboard::Key key) const;
};