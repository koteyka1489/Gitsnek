#pragma once
#include "Board.h"


class Square
{
public:
	Square();
	void SetLoc(Location& loc);
	void Draw(Board& brd);
	Location GetLoc();

private:
	int r = 200;
	int g = 200;
	int b = 200;
	Location loc;
};

