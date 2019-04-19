#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <list>
using namespace std;
using namespace sf;

class UI
{
private:
	Font font;		//holds the current font we are writing all the text in
	Text startGame;	//text for initial start up screen
	Text startButton;	//actual button that needs pressed to get past the start up screen
	Text text;	//holds default text that changes throught the program
	Text endGame;	//holds text for the end of game menu
	bool resestlvl = false;	//switches to true when a level needs to be reset
	int lives = 3;	//lives on game start up
	int aliensKilled = 0;	//aliens killed on start up
	int level = 1;	//starting level
	bool gameLost = false;	//holds whether the user was killed
	bool gameWon = false;	//holds whether the user killed all aliens
	bool isRunGame = false; //tells whether the start up button has been clicked in order to run the game

public:
	UI();
	void draw(RenderWindow& win);
	bool handleMouseUp(Vector2f& mouse);
	Text getStartButton();
	void resetUImgr();
	void drawMenu(RenderWindow &window);
	void showStats(RenderWindow &window);
	bool isGameRunning();
	void nextLevel();
	bool resetLevel();
	void loseLife();
	
	bool getIsRunGame();
	void setIsRunGame(bool input);

	int getLevel();
	void alienKilled();
};