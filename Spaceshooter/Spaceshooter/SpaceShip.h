#pragma once

#include "GameOBject.h"

class SpaceShip : public GameOBject
{
	//fuck
private:
	int lives;
	int score;
	int animationRow;

public:
	SpaceShip();
	void Destroy();

	void Init(ALLEGRO_BITMAP *image)
};