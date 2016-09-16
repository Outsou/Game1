#pragma once
#include "VisibleGameObject.h"

class Wall :
	public VisibleGameObject
{
public:
	Wall();
	~Wall();

	void Update(sf::Time elapsed);
	void Draw(sf::RenderWindow& rw);

};