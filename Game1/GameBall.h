#pragma once
#include "visiblegameobject.h"


class GameBall :
	public VisibleGameObject
{
public:
	GameBall();
	virtual ~GameBall();
	void Update(sf::Time);

private:
	float _velocityStart;
	float _velocity;
	float _angle;
	float _elapsedTimeSinceStart;

	float LinearVelocityX(float angle);
	float LinearVelocityY(float angle);
};