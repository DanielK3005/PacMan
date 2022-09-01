#include "ThePacManGame.h"
#include "Point.h"

void Point::draw(char ch) const 
{
	gotoxy(x, y);
	cout << ch << endl;
}

void Point::moveWIthDirection(int dir)
{
	switch (dir)
	{
	case 0: // UP
		--y;
		break;
	case 1: // DOWN
		++y;
		break;
	case 2: // LEFT
		--x;
		break;
	case 3: // RIGHT
		++x;
		break;
	case 4: // STAY
		break;
	}
}