//================================================
// Sean Jennings
// Programming 2
// Assignment 7 (Final Project): Game
// 4-19-19
//================================================
#include <iostream>
using namespace std;
#include <SFML/Graphics.hpp>
using namespace sf; 
#include <list>
#include "UI.h"
#include "ship.h"
#include "spriteMgr.h"
#include "enemyGroup.h"


int main()
{
	//declaring the drawing window's size and frame rate
	const int WINDOW_WIDTH = 800;
	const int WINDOW_HEIGHT = 600;
	RenderWindow window(VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "aliens!");
	window.setFramerateLimit(60);		// Limit the framerate to 60 frames per second
	
	//declaring managers for each of my classes that will be used in main
	SpriteMgr spriteMgr;
	UI UImgr;
	
	Sprite background = spriteMgr.getBackgroundSprite();	
	
	// initial position of the ship will be approx middle of screen
	float shipX = window.getSize().x / 2.0f;
	float shipY = window.getSize().y / 1.1f; //2.0
	Ship ship(background, spriteMgr, shipX, shipY);

	//manager for the class of all the aliens as a whole
	EnemyGroup groupMgr(spriteMgr, UImgr, ship);
	
	Event startUpMenu; //used for initial start up menu and for the menu after a won/lost game

	while (window.isOpen() && !UImgr.getIsRunGame())
	{
		window.draw(background);
		window.draw(UImgr.getStartButton());
		UImgr.draw(window);
		while (window.pollEvent(startUpMenu))
		{
			if (startUpMenu.type == Event::Closed)
				window.close();
			else if (startUpMenu.type == Event::MouseButtonReleased)
			{
				Vector2f mousePos = window.mapPixelToCoords(Mouse::getPosition(window));	//position of mouse
				UImgr.setIsRunGame(UImgr.handleMouseUp(mousePos));
			}
		}
		window.display();
	}

	while (window.isOpen())
	{
		// check all the window's events that were triggered since the last iteration of the loop
		// For now, we just need this so we can click on the window and close it
		Event event;

		while (window.pollEvent(event))
		{
			// "close requested" event: we close the window
			if (event.type == Event::Closed)
				window.close();
			else if (event.type == Event::KeyPressed)
			{
				if ((event.key.code == Keyboard::Space) && (ship.getMissileCount() < 5))
				{
					ship.fireMissile();
				}
			}
			/*if (event.type == Event::MouseButtonReleased)
			{
				UImgr.moustButtonReleased(window.mapPixelToCoords(Mouse::getPosition(window)));
			}*/
		}
		window.clear();
		if (UImgr.isGameRunning())
		{
			if (UImgr.resetLevel())
			{
				groupMgr.resetAliens();
				ship.resetShip();
			}

			// draw background first, so everything that's drawn later 
			// will appear on top of background
			window.draw(background);
			
			ship.moveShip();
			ship.moveMissileList();
			ship.draw(window);

			groupMgr.moveAliens(window);
			groupMgr.drawAliens(window);
			groupMgr.dropBombs();
			groupMgr.moveBombs(window);
			groupMgr.drawBombs(window);
			groupMgr.handleHit();

			UImgr.showStats(window);
		}
		else
		{
			while (window.isOpen() && !UImgr.getIsRunGame())
			{	
				window.draw(background);
				UImgr.drawMenu(window);
				window.draw(UImgr.getStartButton());

				while (window.pollEvent(startUpMenu))
				{
					if (startUpMenu.type == Event::Closed)
						window.close();
					else if (startUpMenu.type == Event::MouseButtonReleased)
					{
						Vector2f mousePos = window.mapPixelToCoords(Mouse::getPosition(window));	//position of mouse
						UImgr.setIsRunGame(UImgr.handleMouseUp(mousePos));
					}
				}
				window.display();
			}
			UImgr.resetUImgr();
		}
		window.display();
	} // end body of animation loop
	return 0;
}