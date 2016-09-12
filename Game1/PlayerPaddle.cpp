#include "StdAfx.h"
#include "PlayerPaddle.h"
#include "Game.h"
#include "ServiceLocator.h"
#include "EnumKeyboard.h"


PlayerPaddle::PlayerPaddle() :
	_velocity(0),
	_maxVelocity(600.0f)
{
	Load("Assets/Images/paddle.png");
	assert(IsLoaded());

	GetSprite().setOrigin(GetSprite().getGlobalBounds().width / 2, GetSprite().getGlobalBounds().height / 2);
}


PlayerPaddle::~PlayerPaddle()
{
}

void PlayerPaddle::Draw(sf::RenderWindow & rw)
{
	VisibleGameObject::Draw(rw);
}

float PlayerPaddle::GetVelocity() const
{
	return _velocity;
}

void PlayerPaddle::Update(sf::Time elapsedTime)
{
	//Left
	if (ServiceLocator::GetInput()->keyDown(LEFT))
	{
		_velocity -= 3.0f;
	}

	//Right
	if (ServiceLocator::GetInput()->keyDown(RIGHT))
	{
		_velocity += 3.0f;
	}


	if (ServiceLocator::GetInput()->keyDown(DOWN))
	{
		_velocity = 0.0f;
	}

	if (_velocity > _maxVelocity)
		_velocity = _maxVelocity;

	if (_velocity < -_maxVelocity)
		_velocity = -_maxVelocity;


	sf::Vector2f pos = this->GetPosition();

	if (pos.x  < GetSprite().getGlobalBounds().width / 2
		|| pos.x >(Game::SCREEN_WIDTH - GetSprite().getGlobalBounds().width / 2))
	{
		_velocity = -_velocity; // Bounce by current velocity in opposite direction
	}



	GetSprite().move(_velocity * elapsedTime.asSeconds(), 0);

}