#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <list>
using namespace std;
using namespace sf;
#include "spriteMgr.h"
#include "enemy.h"

class Missile
{
private:
	Sprite missileSprite;	//holds the missile's texture/graphic
	const float TRAVEL_DISTANCE = 8.0;	//holds the missile travel speed

public:
	Missile(SpriteMgr *spriteMgr, float x, float y);
	void moveMissile();
	void drawMissile(RenderWindow&);
	Vector2f getPosition();
	FloatRect getBounds();
};