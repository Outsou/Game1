#pragma once
#include "SFML\Window.hpp"
#include "IInputProvider.h"

class InputProviderSFML  : public IInputProvider
{
public:
	InputProviderSFML();

	bool keyDown(Keys key);
};