#pragma once

#include<iostream>
#include<allegro5/allegro5.h>
#include<allegro5/allegro_primitives.h>
#include "globals.h"

class GameOBject
{
private:
	int ID;
	bool alive;
	bool collidable;

protected:
	float x;
	float y;

	float velX;
	float velY;

	int dirX;
	int dirY;

	int boundX;
	int boundY;

	int maxFrame;
	int curFrame;
	int frameCount;
	int frameDelay;
	int frameWidth;
	int frameHeight;
	int animationColumns;
	int animationDirection;

	ALLEGRO_BITMAP *image;


public:
	GameOBject();
	void virtual Destroy();

	void Init(float x, float y, float velX, float velY, int dirX, int dirY, int boundX, int boundY);
	void virtual Update();
	void virtual Render();

	float GetX() {
		return x;
	}
	float GetY() {
		return y;
	}

	void SetX(float x) { GameOBject::x = x; }
	void SetX(float y) { GameOBject::y = y; }

	int GetBoundX() { return boundX; }
	int GetBoundY() { return boundY; }

	int GetID() { return ID; }
	void SetID(int ID) { GameOBject::ID = ID; }

	bool GetAlive() { return alive; }
	void SetAlive(bool alive) { GameOBject::alive = alive; }
	
	bool GetCollidable() { return collidable; }
	void SetCollidable(bool collidable) { GameOBject::collidable = collidable; }
	
	bool CheckCollisions(GameOBject *otherObject);
	void virtual Collided(int objectID);
	bool Collidable();

};