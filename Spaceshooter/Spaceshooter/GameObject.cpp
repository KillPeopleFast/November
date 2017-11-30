#include"GameOBject.h"

GameOBject::GameOBject()
{
	x = 0;
	y = 0;

	velX = 0;
	velY = 0;
	dirX = 0;
	dirY = 0;

	boundX = 0;
	boundY = 0;

	maxFrame = 0;
	curFrame = 0;
	frameCount = 0;
	frameDelay = 0;
	frameWidth = 0;
	frameHeight = 0;
	animationColumns = 0;
	animationDirection = 0;

	image = NULL;

	alive = true;
	collidable = true;

}

void GameOBject::Destroy()
{
	if (image != NULL)
		al_destroy_bitmap(image);
}

void GameOBject::Init(float x, float y, float velX, float velY, int dirX, int dirY, int boundX, int boundY);
{
	GameOBject::x = x;
	GameOBject::y = y;

	GameOBject::velX = velX;
	GameOBject::velY = velY;

	GameOBject::dirX = dirX;
	GameOBject::driY = dirY;

	GameOBject::boundX = boundX;
	GameOBject::boundY = boundY;
}
void GameOBject::Update() 
{
	x += velX *dirX;
	y += velY *dirY;
}
void GameOBject::Render() {

}
bool GameOBject::CheckCollisions(GameOBject *otherObject)
{
	float oX = otherObject->GetX();
	float oY = otherObject->GetY();

	int obX = otherObject->GetBoundX();
	int obY = otherObject->GetBoundY();
	if (x + boundX > oX - obX &&
		x - boundX < oX + obX &&
		y + boundY > oY - obY &&
		y - boundX < oY + obY)
		return true;
	else
		return false;
}
void GameOBject::Collided(int objectID)
{

}
bool GameOBject::Collidable()
{
	return alive && collidable;
}