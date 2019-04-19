#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;
using namespace sf;
#include "UI.h";

//======================================================
// UI::UI(): constructor only loads the text font
// parameters: none
// return type: none
//======================================================
UI::UI()
{
	if (!font.loadFromFile("C:\\Windows\\Fonts\\arial.ttf"))
	{
		cout << "couldn't load font";
		exit(-1);
	}
}

//======================================================
// UI::draw(): draws start up menu text and button
// parameters: RenderWindow& win: for drawing in
// return type: void
//======================================================
void UI::draw(RenderWindow& win)
{
	startGame.setString("   	Space Invaders\nPress start to play new game:");
	startGame.setFont(font);
	startGame.setCharacterSize(35);
	startGame.setPosition(200, 150);
	startGame.setFillColor(Color::Blue);
	win.draw(startGame);

	startButton.setString("START");
	startButton.setFont(font);
	startButton.setCharacterSize(45);
	startButton.setPosition(340, 300);
	startButton.setFillColor(Color::Red);
	win.draw(startButton);
}

//======================================================
// UI::handleMouseUp(): checks to see if the start button was pressed
// parameters: Vector2f: contains the mouse's position
// return type: bool
//======================================================
bool UI::handleMouseUp(Vector2f& mouse)
{
	bool startGame = false;
	if (startButton.getGlobalBounds().contains(mouse))
	{
		startGame = true;
	}

	return startGame;
}

//======================================================
// UI::getStartButton(): returns start button text for drawing
// parameters: none
// return type: Text
//======================================================
Text UI::getStartButton()
{
	return startButton;
}

//======================================================
// UI::resetUImgr(): restart setting in the game
// parameters: none
// return type: void
//======================================================
void UI::resetUImgr()
{
	lives = 3;
	level = 1;
	gameLost = false;
	gameWon = false;
	resestlvl = true;
	aliensKilled = 0;
} 

//======================================================
// UI::drawMenu(): draws the menu to start again after you either lost or won
// parameters: RenderWindow& win: for drawing in
// return type: void
//======================================================
void UI::drawMenu(RenderWindow &window)
{ 
	text.setFont(font);
	text.setFillColor(Color::Green);
	text.setCharacterSize(50);
	text.setPosition(300, 50);
	if (gameLost)
	{

		text.setString("You Lost!");
		window.draw(text);
	}
	else
	{
		text.setString("You Won!");
		window.draw(text);
	}
	text.setString("Final Score: " + to_string(aliensKilled));
	text.setCharacterSize(35);
	text.setPosition(10, 0);
	window.draw(text);

	text.setString("Press Start to Play Again:");
	text.setCharacterSize(35);
	text.setPosition(200, 200);
	text.setFillColor(Color::Blue);
	window.draw(text);
}

//======================================================
// UI::showStats(): draws stats on the screen during the game: lives, kills, and level
// parameters: RenderWindow& win: for drawing in
// return type: void
//======================================================
void UI::showStats(RenderWindow &window)
{
	text.setFont(font);
	text.setFillColor(Color::Red);
	text.setCharacterSize(24);
	
	text.setString("Lives " + to_string(lives));
	text.setPosition(10, 0);
	window.draw(text);

	text.setString("Kills: " + to_string(aliensKilled));
	text.setPosition(10, 22);
	window.draw(text);

	text.setString("Level: " + to_string(level));
	text.setPosition(690, 0);
	window.draw(text);
}

//======================================================
// UI::isGameRunning(): checks to see if the game has been won or not
// parameters: none
// return type: bool
//======================================================
bool UI::isGameRunning()
{
	bool temp = true;
	if (gameWon || gameLost)
	{
		isRunGame = false;
		temp = false;
	}
	return temp;
}

//======================================================
// UI::nextLevel(): checks to see if it is time for the next level or not
// parameters: none
// return type: void
//======================================================
void UI::nextLevel()
{
	if (level != 2)
	{
		level = 2;
		resestlvl = true;
	}
	else
	{
		gameWon = true;
	}
}

//======================================================
// UI::resetLevel(): resets the level if needed
// parameters: none
// return type: bool
//======================================================
bool UI::resetLevel()
{
	bool temp = resestlvl;
	
	if (resestlvl)
	{
		resestlvl = false;
	}

	return temp;
}

//======================================================
// UI::loseLife(): decreases the lives count
// parameters: none
// return type: void
//======================================================
void UI::loseLife()
{
	lives--;
	if (lives <= 0)
	{
		gameLost = true;
	}
	resestlvl = true;
}

//======================================================
// UI::getIsRunGame(): returns whether the start button has been pressed and the game is ready to run
// parameters: none
// return type: bool
//======================================================
bool UI::getIsRunGame()
{
	return isRunGame;
}

//======================================================
// UI::setIsRunGame(): sets the isRunGame bool
// parameters: none
// return type: void
//======================================================
void UI::setIsRunGame(bool input)
{
	isRunGame = input;
}

//======================================================
// UI::getLevel(): returns the current level
// parameters: none
// return type: int
//======================================================
int UI::getLevel()
{
	return level;
}

//======================================================
// UI::alienKilled(): increments the number of aliens killed
// parameters: none
// return type: void
//======================================================
void UI::alienKilled()
{
	aliensKilled++;
}