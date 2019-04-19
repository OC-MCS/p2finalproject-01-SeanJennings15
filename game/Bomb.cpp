#pragma once
#include <iostream>
using namespace std;
#include <SFML/Graphics.hpp>
using namespace sf;
#include <list>
#include "Bomb.h"

//======================================================
// Bomb::Bomb(): constructor for each bomb dropped; sets the sprite based on level and the starting position
// parameters: UI *UImgr, SpriteMgr *spriteMgr, float x, float y
// UImgr: used to access the level; spriteMgr: used to access sprite depending on level; x and y set the position
// return type: none
//======================================================
Bomb::Bomb(UI *UImgr, SpriteMgr *spriteMgr, float x, float y)
{
	if (UImgr->getLevel() == 1)
	{
		bombSprite = spriteMgr->getBombSprite();
	}
	else
	{
		bombSprite = spriteMgr->getBombSprite2();
	}
	bombSprite.setPosition(x - 12, y);
}

//======================================================
// Bomb::moveBomb(): moves the bomb across the screen
// parameters: none
// return type: void
//======================================================
void Bomb::moveBomb()
{
	bombSprite.move(0, MOVE_DISTANCE);
}

//======================================================
// Bomb::drawBomb(): draws the bomb on the screen
// parameters: window: window to draw in
// return type: void
//======================================================
void Bomb::drawBomb(RenderWindow &window)
{
	window.draw(bombSprite);
}

//======================================================
// Bomb::getPosition(): returns the bomb's position
// parameters: none
// return type: Vector2f
//======================================================
Vector2f Bomb::getPosition()
{
	return bombSprite.getPosition();
}

//======================================================
// Bomb::getBounds(): returns the bomb sprite's bounds
// parameters: none
// return type: FloatRect
//======================================================
FloatRect Bomb::getBounds()
{
	return bombSprite.getGlobalBounds();
}