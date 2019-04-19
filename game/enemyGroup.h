#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <list>
#include "enemy.h"
#include "spriteMgr.h"
#include "Bomb.h"
#include "ship.h"
#include "UI.h"
using namespace std;
using namespace sf;


class EnemyGroup
{
private:
    list<Enemy> enemyList;	//linked list for all the enemies
	list<Bomb> bombList;	//linked list for all the bommbs
	
	//initializing all the sprites for each class needed
	Ship *ship;				
	SpriteMgr spriteMgr;	
	UI* UImgr;

	int bombTimer = 20;	//starting time before a bomb drops
	float enemyHeight;	//height for the line of enemies

public:
	EnemyGroup(SpriteMgr& spriteMgr, UI& UImgr, Ship& ship);
	void moveAliens(RenderWindow&);
	void drawAliens(RenderWindow&);
	void resetAliens();
	void handleHit();
	void moveBombs(RenderWindow&);
	void drawBombs(RenderWindow&);
	void dropBombs();
};