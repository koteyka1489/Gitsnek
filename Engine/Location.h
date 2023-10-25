#pragma once


struct Location
{
	Location()
	{
	}
	Location(int x, int y)
	{
		this->x = x;
		this->y = y;
	}
	void operator= (const Location& other)
	{
		this->x = other.x;
		this->y = other.y;
	}
	void Add(const Location& val)
	{
		x += val.x;
		y += val.y;
	}
	int x;
	int y;
};
