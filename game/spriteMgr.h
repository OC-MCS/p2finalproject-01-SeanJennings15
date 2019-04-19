#pragma once
#include <iostream>
using namespace std;
#include <SFML/Graphics.hpp>
using namespace sf;
#include <list>

class SpriteMgr
{
private:
	//declaring all the sprites and their textures that will be used
	Texture backgroundTexture, enemyTexture, bombTexture, shipTexture, missileTexture, enemyTexture2, bombTexture2;
	Sprite backgroundSprite, enemySprite, bombSprite, shipSprite, missileSprite, enemySprite2, bombSprite2;

public:
	SpriteMgr();
	
	Sprite getBackgroundSprite();
	Sprite getEnemySprite();
	Sprite getBombSprite();
	Sprite getShipSprite();
	Sprite getMissileSprite();
	Sprite getEnemySprite2();
	Sprite getBombSprite2();
};