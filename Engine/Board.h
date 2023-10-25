#pragma once
#include "Graphics.h"
#include "Location.h"


class Board
{
public:
	Board(Graphics& gfx);
	void drawCell(const Location& loc, int r, int g, int b);
	void DrawGrid();
	int GetGridWidht();
	int GetGridHeight();
	int GetxGridStart();
	int GetyGridStart();


private:
	static constexpr int dimensionCell = 20;
	static constexpr int widhtGrid = 780;
	static constexpr int heightGrid = 580;
	static constexpr int xGridStart = 20;
	static constexpr int yGridStart = 20;
	Graphics& gfx;
	Color boardColor = Colors::Cyan;


};
