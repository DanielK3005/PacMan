#pragma once
#include "Point.h"
#include "Color.h"
#include "Board.h"

#define PACMAN (char)001

const Point startPacmanPos(30,14);

enum class Direction { UP, DOWN, LEFT, RIGHT, STAY };

class PacMan
{
	Point body = startPacmanPos;
	int direction = 4;
	char arrowKeys[5];
	Color _color;
	bool ColorON = true;

public:
	void setColor(Color color) { this->_color = color; }
	void setArrowKeys(const char* keys);
	void setLocation(int x, int y) { body.setXY(x, y); }
	void move(Board& walls);
	int getDirection(char key);
	void setDirection(int dir)
	{
		direction = dir;
	}
	Point& getLocation() { return this->body; }
	void setColorChoiceToFalse() { ColorON = false; }
	void invisibleTunnelCheck();
	void setColorChoiceToTrue() { ColorON = true; }
};