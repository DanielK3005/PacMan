#include "Board.h"
#include "ThePacManGame.h"

void Board::printBoardWithColor() const {
	for (int i = 0; i < LENGTH * (DEPTH + 1) + 1; i++)
		if (board[i] == '#')
		{
			setTextColor(Color::LIGHTGREEN);
			cout << WALL;
			setTextColor(Color::WHITE);
		}
		else
		{
			cout << board[i];
		}
}

void Board::initFoodAndWalls()
{
	// init walls
	for (int i = 0; i < LENGTH + 1; i++)
		for (int j = 0; j < DEPTH + 1; j++)
			if (board[i * (DEPTH +1) + j] == WALL)
				this->WallsArray[i][j] = true;
	// init food
	for (int i = 0; i < LENGTH + 1; i++)
		for (int j = 0; j < DEPTH + 1; j++)
			if (board[i * (DEPTH + 1) + j] == '*')
				this->foodArr[i][j] = true;
}