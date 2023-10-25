/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.h																				  *
 *	Copyright 2016 PlanetChili.net <http://www.planetchili.net>							  *
 *																						  *
 *	This file is part of The Chili DirectX Framework.									  *
 *																						  *
 *	The Chili DirectX Framework is free software: you can redistribute it and/or modify	  *
 *	it under the terms of the GNU General Public License as published by				  *
 *	the Free Software Foundation, either version 3 of the License, or					  *
 *	(at your option) any later version.													  *
 *																						  *
 *	The Chili DirectX Framework is distributed in the hope that it will be useful,		  *
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of						  *
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the						  *
 *	GNU General Public License for more details.										  *
 *																						  *
 *	You should have received a copy of the GNU General Public License					  *
 *	along with The Chili DirectX Framework.  If not, see <http://www.gnu.org/licenses/>.  *
 ******************************************************************************************/
#pragma once

#include "Keyboard.h"
#include "Mouse.h"
#include "Graphics.h"
#include "Board.h"
#include <random>
#include "Snake.h"
#include "Location.h"
#include "Goal.h"
#include "SpriteCodex.h"
#include "Square.h"

class Game
{
public:
	Game( class MainWindow& wnd );
	Game( const Game& ) = delete;
	Game& operator=( const Game& ) = delete;
	void Go();
private:
	void ComposeFrame();
	void UpdateModel();
	void MoveSnake();
	void GoalCheckCollision();
	void GoalDraw();
	void snakeUpdate();
	void SquareSetLoc();
	void DrawSquare();
	void SquareCollision();
	

private:
	MainWindow& wnd;
	Graphics gfx;
	Board brd;
	std::random_device rd;
	std::mt19937 rng;
	std::uniform_int_distribution<int> xGoalDist;
	std::uniform_int_distribution<int> yGoalDist;
	Location startLoc;
	Snake snake;
	bool upIsPressed = false;
	bool downIsPressed = false;
	bool rightIsPressed = false;
	bool leftIsPressed = false;
	Location goalLoc;
	Goal gl;
	bool goalCollision = false;
	int moveTicks = 0;
	Location moveMemory;
	int curentSnakeSpeed = 15;
	static constexpr int maxSnakeSpeed = 5;
	static constexpr int SquareMaxSize = 15;
	Square sqr [SquareMaxSize];
	int curentSquareSize = 1;
	std::uniform_int_distribution<int> xSquareDist;
	std::uniform_int_distribution<int> ySquareDist;
	int squareDrawTicks = 0;
	static constexpr int squareDrawTime = 360;
	bool SquareSetLocDone = false;
	bool squareCollision = false;

};