#pragma once
#include <iostream>
using namespace std;
#include <SFML/Graphics.hpp>
using namespace sf;
#include <list>
#include "spriteMgr.h"
#include "UI.h"

class Bomb
{
private:
	Sprite bombSprite;	//holds each bombs sprite
	const float MOVE_DISTANCE = 2.5;	//sets the speed the bomb moves

public:
	Bomb(UI *UImgr, SpriteMgr *spriteMgr, float x, float y);

	void moveBomb();
	void drawBomb(RenderWindow &window);
	Vector2f getPosition();
	FloatRect getBounds();
};