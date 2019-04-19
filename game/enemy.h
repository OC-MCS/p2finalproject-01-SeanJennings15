#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <list>
using namespace std;
using namespace sf;
#include "spriteMgr.h"
#include "UI.h"

class Enemy
{
private:
	Sprite enemySprite;	//holds sprite for each enemy being added to the linked list

public:
	Enemy(UI *UIMgr, SpriteMgr &spriteMgr, float x, float y);
	void moveEnemy(float speed);
	void drawEnemy(RenderWindow &window);
	Vector2f getPosition();
	FloatRect getBounds();
};