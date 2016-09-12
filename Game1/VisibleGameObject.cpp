#include "StdAfx.h"
#include "VisibleGameObject.h"


VisibleGameObject::VisibleGameObject()
	: _isLoaded(true)
{
	//_isLoaded = false;
}


VisibleGameObject::~VisibleGameObject()
{
}

void VisibleGameObject::Load(std::string filename)
{
	if (_texture.loadFromFile(filename) == false)
	{
		_filename = "";
		_isLoaded = false;
	}
	else
	{
		_filename = filename;
		_sprite.setTexture(_texture);
		_isLoaded = true;
	}
}

void VisibleGameObject::Draw(sf::RenderWindow & renderWindow)
{
	if (_isLoaded)
	{
		renderWindow.draw(_sprite);
	}
}

void VisibleGameObject::Update(sf::Time elapsed)
{
}

void VisibleGameObject::SetPosition(float x, float y)
{
	if (_isLoaded)
	{
		_sprite.setPosition(x, y);
	}
}

sf::Vector2f VisibleGameObject::GetPosition() const
{
	if (_isLoaded)
	{
		return _sprite.getPosition();
	}
	return sf::Vector2f();
}

sf::Sprite& VisibleGameObject::GetSprite()
{
	return _sprite;
}

bool VisibleGameObject::IsLoaded() const
{
	return _isLoaded;
}

float VisibleGameObject::GetHeight() const
{
	return _sprite.getGlobalBounds().height;
}

float VisibleGameObject::GetWidth() const
{
	return _sprite.getGlobalBounds().width;
}

sf::Rect<float> VisibleGameObject::GetBoundingRect() const
{
	/*
	sf::Vector2f size = _sprite.GetSize();
	sf::Vector2f position = _sprite.GetPosition();

	return sf::Rect<float>(
		position.x - size.x / 2,
		position.y - size.y / 2,
		position.x + size.x / 2,
		position.y + size.y / 2
		);
		*/
	return _sprite.getGlobalBounds();
}