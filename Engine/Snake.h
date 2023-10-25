#pragma once
#include "Graphics.h"
#include "Location.h"
#include "Board.h"
#include "Goal.h"


class Snake
{
private:
	class Segment
	{
	public:
		Segment();
		void InitHead(const Location& in_loc);
		void InitBody(int segment_index);
		void Folow(const Segment& next);
		void MoveBy(const Location& delta_loc);
		void Draw(Board& brd);
		void DrawBody(Board& brd);
		bool GoalCollision(Location& goal_loc);
		bool BoardCollision(Board& brd) const;
		bool SnakeSelfCollision(Segment seg_0) const;
		bool SquareCollision(Location& sq_loc) const;
		
	private:
		Location loc;
		static int segmentCount;
		int r = 0;
		int g = 255;
		int b = 0;
	};

public:
	Snake(const Location& loc);
	void MoveBy(const Location& delta_loc);
	void Grow();
	void Draw(Board& brd);
	bool GoalCollision(Location& goal_loc);
	bool BoardCollision(Board& brd) const;
	bool SnakeSelfCollision() const;
	bool SquareCollision(Location& sq_loc) const;
	
private:
	
	static constexpr int rHead = 249;
	static constexpr int gHead = 232;
	static constexpr int bHead = 20;
	
	static constexpr int nSegmentsMax = 100;
	int nSegments = 1;
	Segment segments[nSegmentsMax];
	bool snakeSelfCollision = false;
};




