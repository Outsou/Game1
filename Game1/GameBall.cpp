#include "StdAfx.h"
#include "GameBall.h"


GameBall::GameBall()
{
	Load("Assets/Images/ball.png");
	assert(IsLoaded());

	GetSprite().setOrigin(15, 15);
}


GameBall::~GameBall()
{
}