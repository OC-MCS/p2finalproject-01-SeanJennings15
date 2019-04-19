#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <list>
using namespace std;
using namespace sf;
#include "enemyGroup.h"

//======================================================
// Enemy::EnemyGroup(): constuctor for the group of aliens; sets up starting amount, sprite, position, and height
// parameters: SpriteMgr& inputSpriteMgr, UI& inputUImgr, Ship& inputShip
// inputSpriteMgr: set the enemy's starting texture; inputUImgr: for initilizing the tempEnemy
// inputShip: creates a way to address ship for later
// return type: none
//======================================================
EnemyGroup::EnemyGroup(SpriteMgr& inputSpriteMgr, UI& inputUImgr, Ship& inputShip)
{
	for (int i = 0; i < 15; i++)
	{
		Enemy tempEnemy(&inputUImgr, spriteMgr, 30.0f + (i * 50.0), 80.0f);
		enemyList.push_back(tempEnemy);
	}
	enemyHeight = 80.0;

	//saving variables fpr the other classes for use later
	spriteMgr = inputSpriteMgr;
	UImgr = &inputUImgr;
	ship = &inputShip;
}

//======================================================
// EnemyGroup::moveAliens(): moves the the aliens down the screen by accessing each one, one at a time
// parameters: RenderWindow& window: for drawing in
// return type: void
//======================================================
void EnemyGroup::moveAliens(RenderWindow &window)
{
	float alienSpeed;
	if (enemyHeight <= window.getSize().y / 1.1f)
	{
		list<Enemy>::iterator it;
		for (it = enemyList.begin(); it != enemyList.end(); it++)
		{
			if (UImgr->getLevel() == 1)
			{
				alienSpeed = 0.2;
			}
			else
			{
				alienSpeed = 0.3;
			}

			it->moveEnemy(alienSpeed);
			enemyHeight = it->getPosition().y;
		}
	}
	else
	{
		resetAliens();
		UImgr->loseLife();
	}
}

//======================================================
// EnemyGroup::drawAliens(RenderWindow& window): draws the aliens as they move down the screen, accesses each one, one at a time
// parameters: RenderWindow& window: window for drawing in
// return type: void
//======================================================
void EnemyGroup::drawAliens(RenderWindow &window)
{
	list<Enemy>::iterator it;
	for (it = enemyList.begin(); it != enemyList.end(); it++)
	{
		it->drawEnemy(window);
	}
}

//======================================================
// EnemyGroup::resetAliens(): after a new game, loss, win, or aliens reaching the bottom, they need to be reset (sets 15 aliens)
// parameters: none
// return type: void
//======================================================
void EnemyGroup::resetAliens()
{
	enemyList.clear();
	bombList.clear();

	for (int i = 0; i < 15; i++)
	{
		Enemy tempEnemy(UImgr, spriteMgr, 30.0f + (i* 50.0f), 80.0f);
		enemyList.push_back(tempEnemy);
	}
	enemyHeight = 100;
}

//======================================================
// EnemyGroup::handleHit(): deals with missiles hitting the enemies and bombs hitting the user
// parameters: none
// return type: void
//======================================================
void EnemyGroup::handleHit()
{
	list<Enemy>::iterator enemyIt;
	enemyIt = enemyList.begin();
	list<Bomb>::iterator bombIt;
	bombIt = bombList.begin();
	if (enemyList.size() == 0)
	{
		UImgr->nextLevel();
	}
	else
	{
		while (enemyIt != enemyList.end())
		{
			if (ship->hitEnemy(enemyIt->getBounds()))
			{
				enemyIt = enemyList.erase(enemyIt);
				UImgr->alienKilled();
			}
			else
			{
				enemyIt++;
			}
		}
		while (bombIt != bombList.end())
		{
			float bombX = bombIt->getPosition().x;
			float bombY = bombIt->getPosition().y;
			if (ship->getBounds().contains(bombIt->getPosition()) || (((bombY) > ship->getPosition().y - 20) && (((ship->getPosition().x) > bombX) && (ship->getPosition().x < (bombX + 35)))))
			{
				bombIt = bombList.erase(bombIt);
				UImgr->loseLife();
				ship->resetShip();
			}
			else
			{
				bombIt++;
			}
		}
	}
}

//======================================================
// EnemyGroup::moveBombs(): moves the list of bombs down the screen by accessing each one individually
// parameters: RenderWindow& window: for drawing in
// return type: void
//======================================================
void EnemyGroup::moveBombs(RenderWindow& window)
{
	list<Bomb>::iterator it;
	it = bombList.begin();
	while (it != bombList.end())
	{
		it->moveBomb();
		if (it->getPosition().y > window.getSize().y)
		{
			it = bombList.erase(it);
		}
		else
		{
			it++;
		}
	}
}

//======================================================
// EnemyGroup::drawBombs(): draws the bombs by accessing the draw function on at a time
// parameters: RenderWindow& window: for drawing in
// return type: void
//======================================================
void EnemyGroup::drawBombs(RenderWindow& window)
{
	list<Bomb>::iterator it;
	for (it = bombList.begin(); it != bombList.end(); it++)
	{
		it->drawBomb(window);
	}
}

//======================================================
// EnemyGroup::dropBombs(): picks which alien will drop the bomb and initializes the bombs position to that alien
// parameters: none
// return type: void
//======================================================
void EnemyGroup::dropBombs()
{
	if (bombTimer == 0)
	{
		int randomAlien = rand() % enemyList.size();
		list<Enemy>::iterator it;
		it = enemyList.begin();

		for (int i = 0; i < randomAlien; i++)
		{
			it++;
		}
		//initializing each new bomb
		Bomb newBomb(UImgr, &spriteMgr, it->getPosition().x + 10, it->getPosition().y + 20);
		bombList.push_back(newBomb);
		if (UImgr->getLevel() == 1)
		{
			bombTimer = (rand() % 60) + 120;
		}
		else
		{
			bombTimer = (rand() % 60) + 120 - (15 * UImgr->getLevel());
		}
	}
	//decreases time for before next drop
	bombTimer--;
}