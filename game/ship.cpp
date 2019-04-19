#pragma once
#include <SFML/Graphics.hpp>
#include "ship.h"
#include <iostream>
#include <list>
using namespace std;
using namespace sf;

//======================================================
// Ship::Ship(): constructor for the ship: initializes texture and position
// parameters: Sprite &inputBackground, SpriteMgr &spriteMgr, float x, float y
// inputBackground: used for checking if the missiles are still in the screen
// spriteMgr: initializing the textures; x and y: initializing the position of the ship
// return type: none
//======================================================
Ship::Ship(Sprite &inputBackground, SpriteMgr &spriteMgr, float x, float y)
{
	shipSprite = spriteMgr.getShipSprite();
	shipSprite.setPosition(x, y);
	background = &inputBackground;
	spriteManager = &spriteMgr;
}

//======================================================
// Ship::Ship(): creates a new missile and adds it to the list
// parameters: none
// return type: void
//======================================================
void Ship::fireMissile()
{
	Missile tempMissile(spriteManager, shipSprite.getPosition().x + 16, shipSprite.getPosition().y - 5);
	missileList.push_back(tempMissile);
	missileCount++;
}

//======================================================
// Ship::moveMissileList(): moves the missiles across the screen one at a time
// parameters: none
// return type: void
//======================================================
void Ship::moveMissileList()
{
	list<Missile>::iterator it;

	for (it = missileList.begin(); it != missileList.end(); it++)
	{
		it->moveMissile();
	}

	for (it = missileList.begin(); it != missileList.end(); )
	{
		if (!background->getGlobalBounds().contains(it->getPosition()))
		{
			it = missileList.erase(it);
			missileCount--;
		}
		else
		{
			it++;
		}
	}
}

//======================================================
// Ship::decreaseMissileCount(): decreasing the amount of missile when one is hit an alien or goes of screen
// parameters: none
// return type: void
//======================================================
void Ship::decreaseMissileCount()
{
	missileCount--;
}

//======================================================
// Ship::getMissileCount(): returns the number of missiles currently on the screen
// parameters: none
// return type: void
//======================================================
int Ship::getMissileCount()
{
	return missileCount;
}

//======================================================
// Ship::moveShip(): moves the ship's position left or right
// parameters: none
// return type: void
//======================================================
void Ship::moveShip()
{
	if (Keyboard::isKeyPressed(Keyboard::Left))
	{
		if ((shipSprite.getPosition().x + -TRAVEL_DISTANCE) >= 0)
		{
			shipSprite.move(-TRAVEL_DISTANCE, 0);
		}
	}
	else if (Keyboard::isKeyPressed(Keyboard::Right))
	{
		if ((shipSprite.getPosition().x + TRAVEL_DISTANCE) <= ((background->getGlobalBounds().width * 1.4) - (shipSprite.getLocalBounds().width)))
		{
			shipSprite.move(TRAVEL_DISTANCE, 0);
		}
	}
}

//======================================================
// Ship::resetShip(): resests the list of missiles, the missile count, and the ship's position
// parameters: none
// return type: void
//======================================================
void Ship::resetShip()
{
	missileList.clear();
	missileCount = 0;
	shipSprite.setPosition(400, shipSprite.getPosition().y);
}

//======================================================
// Ship::drawShip(): draws the ship as it moves side to side
// parameters: RenderWindow& window: for drawing in
// return type: void
//======================================================
void Ship::draw(RenderWindow &window)
{
	window.draw(shipSprite);
	list<Missile>::iterator it;
	for (it = missileList.begin(); it != missileList.end(); it++)
	{
		it->drawMissile(window);
	}
}

//======================================================
// Ship::hitEnemy(): checks for a hit on an enemy and if so deletes the missile
// parameters: FloatRect enemyBounds
// return type: bool
//======================================================
bool Ship::hitEnemy(FloatRect enemyBounds)
{
	bool collision = false;
	list<Missile>::iterator it;
	it = missileList.begin();
	while (it != missileList.end())
	{
		if (enemyBounds.contains(it->getPosition()))
		{
			it = missileList.erase(it);
			missileCount--;
			collision = true;
		}
		else
		{
			it++;
		}
	}
	return collision;
}

//======================================================
// Ship::getPosition(): returns the ship's position
// parameters: none
// return type: Vector2f
//======================================================
Vector2f Ship::getPosition()
{
	return shipSprite.getPosition();
}

//======================================================
// Ship::getBounds(): returns the ship's bounds
// parameters: none
// return type: Float Rect
//======================================================
FloatRect Ship::getBounds()
{
	return shipSprite.getGlobalBounds();
}