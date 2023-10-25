#include "Goal.h"
Goal::Goal(Location& loc)
{
	this->loc = loc;
}

void Goal::draw(Board& brd)
{
	brd.drawCell(loc, r, g, b);
}

Location Goal::GetLoc()
{
	return loc;
}

void Goal::SetLoc(Location& new_loc)
{
	loc = new_loc;
}

Location Goal::GetLock()
{
	return loc;
}