#include "Board.h"

Board::Board(Graphics& gfx)
	:
	gfx(gfx)
{
}

void Board::drawCell(const Location& loc, int r, int g, int b)
{
	gfx.DrawRectDim(loc.x * dimensionCell, loc.y * dimensionCell, dimensionCell, dimensionCell, r, g, b);
}

void Board::DrawGrid()
{
	for (int i = xGridStart; i < widhtGrid; i++)
	{
		gfx.PutPixel(i, yGridStart, boardColor);
	}
	for (int i = xGridStart; i < widhtGrid; i++)
	{
		gfx.PutPixel(i, heightGrid, boardColor);
	}
	for (int i = yGridStart; i < heightGrid; i++)
	{
		gfx.PutPixel(xGridStart, i, boardColor);
	}
	for (int i = yGridStart; i < heightGrid; i++)
	{
		gfx.PutPixel(widhtGrid, i, boardColor);
	}

	
}



int Board::GetGridWidht()
{
	return widhtGrid;
}

int Board::GetGridHeight()
{
	return heightGrid;
}

int Board::GetxGridStart()
{
	return xGridStart;
}

int Board::GetyGridStart()
{
	return yGridStart;
}


