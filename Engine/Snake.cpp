#include "Snake.h"
#include <assert.h>

int Snake::Segment::segmentCount = 0;


Snake::Snake(const Location& loc)
{
	segments[0].InitHead(loc);
}

void Snake::MoveBy(const Location& delta_loc)
{
	for (int i = nSegments - 1; i > 0; i--)
	{
		segments[i].Folow(segments[i - 1]);
	}
	segments[0].MoveBy(delta_loc);
}

void Snake::Grow()
{
	if (nSegments < nSegmentsMax)
	{
		nSegments++;
		segments[nSegments - 1].InitBody(nSegments - 1);
		segments[nSegments - 1].Folow(segments[nSegments - 2]);
	}  
}

void Snake::Draw(Board& brd)
{
	for (int i = 0; i < nSegments; i++)
	{
		segments[i].Draw(brd);
	}
}

bool Snake::GoalCollision(Location& goal_loc)
{
	return segments[0].GoalCollision(goal_loc);
}

bool Snake::BoardCollision(Board& brd) const
{
	return segments[0].BoardCollision(brd);
}

bool Snake::SnakeSelfCollision() const
{
	bool colcheck = false;
	for (int i = 2; i < nSegments; i++)
	{
		if (segments[i].SnakeSelfCollision(segments[0]))
		{
			colcheck = true;
			break;
		}
	}
	return colcheck;
}

bool Snake::SquareCollision(Location& sq_loc) const
{
	return segments[0].SquareCollision(sq_loc);
}

Snake::Segment::Segment()
{

} 

void Snake::Segment::InitHead(const Location& in_loc)
{
	loc = in_loc;
	r = Snake::rHead;
	g = Snake::gHead;
	b = Snake::bHead;
	
}

void Snake::Segment::InitBody(int segment_index)
{
	r = 0 + (segment_index * 2);
	g = 255 - (segment_index * 2);
	b = 0 + (segment_index * 2);
}

void Snake::Segment::Folow(const Segment& next)
{
	loc = next.loc;
}

void Snake::Segment::MoveBy(const Location& delta_loc)
{
	assert(abs(delta_loc.x) + abs(delta_loc.y) == 1);
	loc.Add(delta_loc);
}

void Snake::Segment::Draw(Board& brd)
{
	brd.drawCell(loc, r, g, b);
}

void Snake::Segment::DrawBody(Board& brd)
{
	brd.drawCell(loc, r, g, b);
}



bool Snake::Segment::GoalCollision(Location& goal_loc)
{
	return
		goal_loc.x == loc.x &&
		goal_loc.y == loc.y;
}

bool Snake::Segment::BoardCollision(Board& brd) const
{
	return
		loc.x < 1 ||
		loc.x > 38 ||
		loc.y < 1 ||
		loc.y > 28;
}

bool Snake::Segment::SnakeSelfCollision(Segment seg_0) const
{
	return
		seg_0.loc.x == loc.x &&
		seg_0.loc.y == loc.y;
}

bool Snake::Segment::SquareCollision(Location& sq_loc) const
{
	return
		loc.x == sq_loc.x &&
		loc.y == sq_loc.y;
}


