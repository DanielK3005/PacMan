#pragma once
#include "Point.h"
#include "Color.h"
#include "Board.h"

#define GHOST (char)234
const Point startGhostPos(30, 8);

class Ghost
{
	Point body = startGhostPos;
	int direction = 0;
	Color _color;
	bool ColorON = true;
public:
	void setColor(Color color) { this->_color = color; }
	void move(Board& board);
	void setDirection() { direction = rand() % 4; }
	void setLocation(int x, int y) { body.setXY(x, y); }
	Point& getLocation() { return body; }
	void setColorChoiceToFalse() { ColorON = false; }
	void invisibleTunnelCheck();
	void setColorChoiceToTrue() { ColorON = true; }
};
