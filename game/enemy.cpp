#pragma once
#include <SFML/Graphics.hpp>
#include "enemy.h"
#include <iostream>
using namespace std;
using namespace sf;

//======================================================
// Enemy::Enemy(): constructor for each enemy; initializes the enemy' sprite and position
// parameters: UI *UImgr, SpriteMgr &spriteMgr, float x, float y
// UImgr: accesses the level; spriteMgr: accesses the sprite based on level; x and y: set position
// return type: void
//======================================================
Enemy::Enemy(UI *UImgr, SpriteMgr &spriteMgr, float x, float y)
{
	if (UImgr->getLevel() == 1)
	{
		enemySprite = spriteMgr.getEnemySprite();
	}
	else
	{
		enemySprite = spriteMgr.getEnemySprite2();
	}
	enemySprite.setPosition(x, y);
}

//======================================================
// Enemy::moveEnemy(): moves each enemy at a time accross the screen
// parameters: float speed: the speed passed to it based on level
// return type: void
//======================================================
void Enemy::moveEnemy(float speed)
{
	enemySprite.move(0, speed);
}

//======================================================
// Enemy::drawEnemy(): draw each individual enemy
// parameters: RenderWindow& window: window for drawing in
// return type: void
//======================================================
void Enemy::drawEnemy(RenderWindow &window)
{
	window.draw(enemySprite);
}

//======================================================
// Enemy::getPosition(): returns the position of the enemy
// parameters: none
// return type: Vector2f
//======================================================
Vector2f Enemy::getPosition()
{
	return enemySprite.getPosition();
}

//======================================================
// Enemy::getBounds(): returns the bounds of the enemy
// parameters: none
// return type: FloatRect
//======================================================
FloatRect Enemy::getBounds()
{
	return enemySprite.getGlobalBounds();
}