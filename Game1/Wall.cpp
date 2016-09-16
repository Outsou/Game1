#include "StdAfx.h"
#include "Wall.h"

Wall::Wall() {
	Load("Assets/Images/wall.png");
	assert(IsLoaded());

	GetSprite().setOrigin(GetSprite().getGlobalBounds().width / 2, GetSprite().getGlobalBounds().height / 2);
}

Wall::~Wall()
{
}

void Wall::Draw(sf::RenderWindow &rw) {
	VisibleGameObject::Draw(rw);
}

void Wall::Update(sf::Time elapsedTime) {

}