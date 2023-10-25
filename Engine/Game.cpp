/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.cpp																			  *
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
#include "MainWindow.h"
#include "Game.h"

Game::Game( MainWindow& wnd )
	:
	wnd(wnd),
	gfx(wnd),
	brd(gfx),
	rng(rd()),
	xGoalDist(1, 38),
	yGoalDist(1, 28),
	startLoc(19, 14),
	snake(startLoc),
	goalLoc(xGoalDist(rng), yGoalDist(rng)),
	gl(goalLoc),
	moveMemory(1, 0),
	xSquareDist(2, 37),
	ySquareDist(2, 27)
	
{
}

void Game::Go()
{
	gfx.BeginFrame();	
	UpdateModel();
	ComposeFrame();
	gfx.EndFrame();
}
void Game::MoveSnake()
{
	if (wnd.kbd.KeyIsPressed(VK_UP))
	{
		if (!upIsPressed)
		{
			Location loc(0, -1);
			upIsPressed = true;
			moveMemory = loc;
		}

	}
	if (wnd.kbd.KeyIsPressed(VK_DOWN))
	{
		if (!downIsPressed)
		{
			Location loc(0, 1);
			downIsPressed = true;
			moveMemory = loc;
		}
	}
	if (wnd.kbd.KeyIsPressed(VK_RIGHT))
	{
		if (!rightIsPressed)
		{
			Location loc(1, 0);
			rightIsPressed = true;
			moveMemory = loc;
		}
	}
	if (wnd.kbd.KeyIsPressed(VK_LEFT))
	{
		if (!leftIsPressed)
		{
			Location loc(-1, 0);
			leftIsPressed = true;
			moveMemory = loc;
		}
	}
	if (!wnd.kbd.KeyIsPressed(VK_UP))
	{
		upIsPressed = false;
	}
	if (!wnd.kbd.KeyIsPressed(VK_DOWN))
	{
		downIsPressed = false;
	}
	if (!wnd.kbd.KeyIsPressed(VK_RIGHT))
	{
		rightIsPressed = false;
	}
	if (!wnd.kbd.KeyIsPressed(VK_LEFT))
	{
		leftIsPressed = false;
	}
	moveTicks++;





}

void Game::GoalCheckCollision()
{
	goalCollision = snake.GoalCollision(gl.GetLock());
}

void Game::GoalDraw()
{

	if (!goalCollision)
	{
		gl.draw(brd);
	}
	else
	{
		Location newLock(xGoalDist(rng), yGoalDist(rng));
		gl.SetLoc(newLock);
	}
}

void Game::snakeUpdate()
{

	if (goalCollision)
	{
		snake.Grow();
		if (curentSnakeSpeed > maxSnakeSpeed)
		{
			curentSnakeSpeed--;
		}
	}
	if (moveTicks == curentSnakeSpeed)
	{
		snake.MoveBy(moveMemory);
		moveTicks = 0;
		
	}
}

void Game::SquareSetLoc()
{
	if (!SquareSetLocDone)
	{
		for (int i = 0; i < SquareMaxSize; i++)
		{
			Location squareloc(xSquareDist(rng), ySquareDist(rng));
			sqr[i].SetLoc(squareloc);
		}
		SquareSetLocDone = true;
	}
}

void Game::DrawSquare()
{
	squareDrawTicks++;
	if (squareDrawTicks == squareDrawTime && curentSquareSize < SquareMaxSize)
	{
		curentSquareSize++;
		squareDrawTicks = 0;
	}
	for (int i = 0; i < curentSquareSize; i++)
	{
		sqr[i].Draw(brd);
	}
}

void Game::SquareCollision()
{
	for (int i = 0; i < curentSquareSize; i++)
	{
		if (snake.SquareCollision(sqr[i].GetLoc()))
		{
			squareCollision = true;
		}
	}
}



void Game::UpdateModel()
{
	SquareCollision();
	if (snake.BoardCollision(brd) ||
		snake.SnakeSelfCollision() ||
		squareCollision)
	{
		SpriteCodex::DrawGameOver(350, 250, gfx);
	}
	else
	{
		MoveSnake();
		GoalCheckCollision();
		snakeUpdate();
		SquareSetLoc();
		

	}
}



void Game::ComposeFrame()
{
	if (snake.BoardCollision(brd) ||
		snake.SnakeSelfCollision() ||
		squareCollision)
	{
		SpriteCodex::DrawGameOver(350, 250, gfx);
	}
	else
	{
		brd.DrawGrid();
		snake.Draw(brd);
		GoalDraw();
		DrawSquare();
	}
}
