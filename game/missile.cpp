#pragma once
#include <SFML/Graphics.hpp>
#include "missile.h"
#include <iostream>
using namespace std;
using namespace sf;

//======================================================
// Missile::Missile(): constructor for the missile: sets up texture and position
// parameters: SpriteMgr *spriteMgr, float x, float y
// spriteMgr: for setting the texture; x and y: set the missile's starting position
// return type: none
//======================================================
Missile::Missile(SpriteMgr *spriteMgr, float x, float y)
{
	missileSprite = spriteMgr->getMissileSprite();
	missileSprite.setPosition(x, y);
}

//======================================================
// Missile::moveMissile(): moves the missile's position up the screen
// parameters: none
// return type: void
//======================================================
void Missile::moveMissile()
{
	missileSprite.move(0, -TRAVEL_DISTANCE);
}

//======================================================
// Missile::drawMissile(): draws the missile as it moves up the screen
// parameters: RenderWindow& window: for drawing in
// return type: void
//======================================================
void Missile::drawMissile(RenderWindow &window)
{
	window.draw(missileSprite);
}

//======================================================
// Missile::getPosition(): returns the missile's current position
// parameters: none
// return type: Vector2f
//======================================================
Vector2f Missile::getPosition()
{
	return missileSprite.getPosition();
}

//======================================================
// Missile::getBounds(): returns the bounds of the missile
// parameters: none
// return type: FloatRect
//======================================================
FloatRect Missile::getBounds()
{
	return missileSprite.getGlobalBounds();
}