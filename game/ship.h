#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <list>
using namespace std;
using namespace sf;
#include "missile.h"
#include "spriteMgr.h"

class Ship
{
private:
	list<Missile> missileList;	//linked list for all the missiles
	Sprite shipSprite;		//ship's texture/graphic
	const float TRAVEL_DISTANCE = 5.0;	//speed the ship travels
	Sprite *background;		//holds the background sprite to see if the ship is still on the screen
	SpriteMgr *spriteManager;	//used for declaring the missile
	int missileCount = 0;	//count of missiles in the air at a time (5 is the max)

public:
	Ship(Sprite &background, SpriteMgr &spriteMgr, float x, float y);
	void fireMissile();
	void moveMissileList();
	void moveShip();
	void resetShip();
	void draw(RenderWindow &window);
	int getMissileCount();
	void decreaseMissileCount();
	bool hitEnemy(FloatRect);
	Vector2f getPosition();
	FloatRect getBounds();
};