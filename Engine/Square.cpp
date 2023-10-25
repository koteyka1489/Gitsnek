#include "Square.h"

Square::Square()
{
}

void Square::SetLoc(Location& loc)
{
	this->loc = loc;
}

void Square::Draw(Board& brd)
{
	brd.drawCell(loc, r, g, b);
}

Location Square::GetLoc()
{
	return loc;
}
