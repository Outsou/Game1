#include "stdafx.h"
#include "InputProviderSFML.h"

InputProviderSFML::InputProviderSFML()
{
}


bool InputProviderSFML::keyDown(Keys key)
{
	switch (key)
	{
	case LEFT:
		return sf::Keyboard::isKeyPressed(sf::Keyboard::Left);
		break;
	case RIGHT:
		return sf::Keyboard::isKeyPressed(sf::Keyboard::Right);
		break;
	case DOWN:
		return sf::Keyboard::isKeyPressed(sf::Keyboard::Down);
		break;
	default:
		return false;
		break;
	}
}