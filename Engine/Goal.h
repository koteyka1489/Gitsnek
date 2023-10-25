#pragma once
#include "Graphics.h"
#include "Location.h"
#include "Board.h"

class Goal
{
public:
	Goal(Location& loc);
	void draw(Board& brd);
	Location GetLoc();
	void SetLoc(Location& new_loc);
	Location GetLock();
private:
	int r = 128;
	int g = 0;
	int b = 0;
	Location loc;

};



