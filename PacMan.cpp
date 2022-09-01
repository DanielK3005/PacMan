#include "PacMan.h"
#include "ThePacManGame.h"

void PacMan::move(Board& board)
{
	Point saver = body;
	body.draw(' '); // delete last point
	body.moveWIthDirection(direction);
	if (!board.IsThereAWall(body))
	{
		if (ColorON)
			setTextColor(_color);

		invisibleTunnelCheck();
		body.draw(PACMAN); // print new point
		hideCursor();
		setTextColor(Color::WHITE);
	}
	else
	{
		body = saver;
		if (ColorON)
			setTextColor(_color);

		gotoxy(body.GetX(), body.GetY());
		invisibleTunnelCheck();
		body.draw(PACMAN); // print new point
		hideCursor();
		setTextColor(Color::WHITE);
	}
}

void PacMan::setArrowKeys(const char* keys)
{
	arrowKeys[0] = keys[0];
	arrowKeys[1] = keys[1];
	arrowKeys[2] = keys[2];
	arrowKeys[3] = keys[3];
	arrowKeys[4] = keys[4];
}

int PacMan::getDirection(char key)
{
	for (int i = 0; i < 5; i++)
	{
		if (key == arrowKeys[i])
			return i;
	}
	return -1;
}

void PacMan::invisibleTunnelCheck()
{
	if (body.GetX() == DEPTH / 2 && body.GetY() == 0) { body.setXY(DEPTH / 2, LENGTH-2); } // valid

	else if (body.GetX() == DEPTH / 2 && body.GetY() == LENGTH - 1) { body.setXY(DEPTH / 2, 1); } // valid

	else if (body.GetX() == 0 && body.GetY() == LENGTH/2-1) { body.setXY(DEPTH-2, LENGTH / 2 - 1); } // valid

	else if (body.GetX() == DEPTH-1 && body.GetY() == LENGTH / 2 - 1) { body.setXY(1, LENGTH / 2 - 1); } // valid

	else { return; }
}