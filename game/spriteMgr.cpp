#pragma once
#include <iostream>
using namespace std;
#include <SFML/Graphics.hpp>
using namespace sf;
#include <list>
#include "spriteMgr.h"

//======================================================
// SpriteMgr::SpriteMgr(): default constructor simply loads all the sprite's textures from their files and sets their scale
// parameters: none
// return type: none
//======================================================
SpriteMgr :: SpriteMgr()
{
	if (!shipTexture.loadFromFile("ship.png"))
	{
		cout << "Unable to load ship texture!" << endl;
		exit(EXIT_FAILURE);
	}
	shipSprite.setTexture(shipTexture);
	shipSprite.setScale(0.1, 0.1);
	
	if (!backgroundTexture.loadFromFile("stars.jpg"))
	{
		cout << "Unable to load stars texture!" << endl;
		exit(EXIT_FAILURE);
	}
	backgroundSprite.setTexture(backgroundTexture);
	backgroundSprite.setScale(0.6, 0.8);

	if (!enemyTexture.loadFromFile("enemyTexture.png"))
	{
		cout << "Unable to load enemy 1 texture!" << endl;
		exit(EXIT_FAILURE);
	}
	enemySprite.setTexture(enemyTexture);
	enemySprite.setScale(0.05, 0.05);

	if (!bombTexture.loadFromFile("bombTexture.png"))
	{
		cout << "Unable to load bomb texture!" << endl;
		exit(EXIT_FAILURE);
	}
	bombSprite.setTexture(bombTexture);
	bombSprite.setScale(0.08, 0.08);

	if (!missileTexture.loadFromFile("missileTexture.png"))
	{
		cout << "Unable to load missiles texture!" << endl;
		exit(EXIT_FAILURE);
	}
	missileSprite.setTexture(missileTexture);
	missileSprite.setScale(0.07, 0.07);

	if (!enemyTexture2.loadFromFile("enemySprite2.png"))
	{
		cout << "Unable to load enemy 2 texture!" << endl;
		exit(EXIT_FAILURE);
	}
	enemySprite2.setTexture(enemyTexture2);
	enemySprite2.setScale(0.075, 0.075);

	if (!bombTexture2.loadFromFile("bombSprite2.png"))
	{
		cout << "Unable to load bomb texture!" << endl;
		exit(EXIT_FAILURE);
	}
	bombSprite2.setTexture(bombTexture2);
	bombSprite2.setScale(0.3, 0.3);
}

//======================================================
// SpriteMgr::getBombSprite2(): returns the second level bomb sprite
// parameters: none
// return type: Sprite
//======================================================
Sprite SpriteMgr::getBombSprite2()
{
	return bombSprite2;
}

//======================================================
// SpriteMgr::getEnemySprite2(): returns the second level enemy sprite
// parameters: none
// return type: Sprite
//======================================================
Sprite SpriteMgr::getEnemySprite2()
{
	return enemySprite2;
}

//======================================================
// SpriteMgr::getBackgroundSprite(): returns the background sprite
// parameters: none
// return type: Sprite
//======================================================
Sprite SpriteMgr::getBackgroundSprite()
{
	return backgroundSprite;
}

//======================================================
// SpriteMgr::getEnemySprite(): returns the first level enemy sprite
// parameters: none
// return type: Sprite
//======================================================
Sprite SpriteMgr::getEnemySprite()
{
	return enemySprite;
}

//======================================================
// SpriteMgr::getBombSprite(): returns the first level bomb sprite
// parameters: none
// return type: Sprite
//======================================================
Sprite SpriteMgr::getBombSprite()
{
	return bombSprite;
}

//======================================================
// SpriteMgr::getShipSprite(): returns the ship's sprite
// parameters: none
// return type: Sprite
//======================================================
Sprite SpriteMgr::getShipSprite()
{
	return shipSprite;
}

//======================================================
// SpriteMgr::getMissileSprite(): returns the missile's sprite
// parameters: none
// return type: Sprite
//======================================================
Sprite SpriteMgr::getMissileSprite()
{
	return missileSprite;
}