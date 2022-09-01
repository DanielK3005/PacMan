#include "Ghost.h"
#include "ThePacManGame.h"

void Ghost::move(Board& board)
{
	Point saver = body;
	setDirection(); // random direction
	if (board.isFoodInXY(body)){
		body.draw(FOOD); // create effect of a ghost flying over the food 
		hideCursor();
	}
	else
	{
		body.draw(' '); // delete last point
		hideCursor();
	}
	body.moveWIthDirection(direction);
	if (!board.IsThereAWall(body))
	{
		if(ColorON)
			setTextColor(this->_color);
		
		body.draw(GHOST); // print new point
		hideCursor();
		setTextColor(Color::WHITE);
	}
	else
	{
		body = saver;
		if (ColorON)
			setTextColor(this->_color); // will do only if user chose 1 at menu

		gotoxy(body.GetX(), body.GetY());
		body.draw(GHOST); // print new point
		hideCursor();
		setTextColor(Color::WHITE);
	}
	invisibleTunnelCheck();
}
// reset Ghost location to start Point when enter to invisible tunnels.
void Ghost::invisibleTunnelCheck()
{
	if (body.GetX() == DEPTH / 2 && body.GetY() == 0)
		{ body.draw(' '); body.setXY(startGhostPos.GetX(), startGhostPos.GetY()); }

	else if (body.GetX() == DEPTH / 2 && body.GetY() == LENGTH-1)
		{ body.draw(' '); body.setXY(startGhostPos.GetX(), startGhostPos.GetY()); }

	else if (body.GetX() == 0 && body.GetY() == (LENGTH / 2) - 1)
		{ body.draw(' '); body.setXY(startGhostPos.GetX(), startGhostPos.GetY()); }

	else if (body.GetX() == DEPTH && body.GetY() == (LENGTH / 2) - 1)
		{ body.draw(' '); body.setXY(startGhostPos.GetX(), startGhostPos.GetY()); }

	else { return; }
}