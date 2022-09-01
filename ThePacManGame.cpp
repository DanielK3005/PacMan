#include "ThePacManGame.h"

void ThePacManGame::init()
{
	// PacMan init
	pacman.setArrowKeys("wxads");
	pacman.setColor(Color::YELLOW);

	// Ghost init
	ghosts[0].setColor(Color::CYAN);
	ghosts[1].setColor(Color::RED);

	board.initFoodAndWalls();

	reset();
}
void ThePacManGame::run(char choice)
{
	unsigned int pointCounter = 0;
	int numOfLives = 3, moveCounter = 0;
	bool EndGame = false;

	if (choice == '1' || choice == '5')
	{
		clrscr();
		if (choice == '5')
		{
			pacman.setColorChoiceToFalse();
			ghosts[0].setColorChoiceToFalse();
			ghosts[1].setColorChoiceToFalse();
			board.printBoard();
		}
		else
		{
			pacman.setColorChoiceToTrue();
			ghosts[0].setColorChoiceToTrue();
			ghosts[1].setColorChoiceToTrue();
			board.printBoardWithColor();
		}
		char key = 0;
		int dir;
		do
		{
			if (_kbhit())
			{
				key = _getch();
				if (key == ESC)
					gamePaused();

				if ((dir = pacman.getDirection(key)) != -1) // pacman controll
					pacman.setDirection(dir);
			}
			moveCounter++; // key to controll gohst speed
			pacman.move(board);
			if (board.isFoodInXY(pacman.getLocation())) // points mechnisem based on foodArr
			{ 
				board.updateFoodArr(pacman.getLocation());
				pointCounter++;
			}
			if (PacManGotEaten()) // check if ghost and pacman on the same point.
				numOfLives--;

			if (moveCounter % 2 == 0)
			{
				ghosts[0].move(board);
				ghosts[1].move(board);
			}
			if (!numOfLives) // lives == 0 // gameover
			{
				displayGameOver();
				EndGame = true;
				continue;
			}
			if (pointCounter == VICTORY)
			{
				displayGameVictory();
				EndGame = true;
				continue;
			}
			Sleep(100);
			displayScore(pointCounter);
			displayLives(numOfLives);

		} while (!EndGame);	
		clrscr();
	}
}

void ThePacManGame::reset()
{
	gotoxy(pacman.getLocation().GetX(), pacman.getLocation().GetY());
	cout << ' ';
	pacman.setLocation(startPacmanPos.GetX(), startPacmanPos.GetY()); pacman.setDirection((int)Direction::STAY);

	gotoxy(ghosts[0].getLocation().GetX(), ghosts[0].getLocation().GetY());
	cout << ' ';
	ghosts[0].setLocation(startGhostPos.GetX(), startGhostPos.GetY());
	gotoxy(ghosts[1].getLocation().GetX(), ghosts[1].getLocation().GetY());
	cout << ' ';
	ghosts[1].setLocation(startGhostPos.GetX(), startGhostPos.GetY());
}

bool ThePacManGame::PacManGotEaten()
{
	if ((ghosts[0].getLocation().GetX() == pacman.getLocation().GetX() &&
		ghosts[0].getLocation().GetY() == pacman.getLocation().GetY()) ||
		(ghosts[1].getLocation().GetX() == pacman.getLocation().GetX() &&
			ghosts[1].getLocation().GetY() == pacman.getLocation().GetY()))
	{
		reset(); return true;
	}
	return false;
}

char ThePacManGame::printMenu()
{
	char choice = 0;
	while (isValidChoice(choice) == false)
	{
		cout << "(1) Start a new game" << endl << "(8) Present instructions and keys" << endl << "(9) Exit" << endl
			<< endl << "(5) start without Colors" << endl << endl;
		choice = _getch();
		if (isValidChoice(choice))
			break;
		else
		{
			clrscr();
			cout << "Invalid Choice please try again! " << endl << endl; // clrscr();
			continue;
		}
	}
	return choice;
}

bool ThePacManGame::isValidChoice(int choice)
{
	if (choice != '1' && choice != '8' && choice != '9' && choice != '5')
		return false;

	return true;
}

void gotoxy(int x, int y)
{
	HANDLE hConsoleOutput;
	COORD dwCursorPosition;
	cout.flush();
	dwCursorPosition.X = x;
	dwCursorPosition.Y = y;
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hConsoleOutput, dwCursorPosition);
}

// function definition -- requires process.h
void clrscr()
{
	system("cls");
}

void ThePacManGame::gamePaused()
{
	gotoxy(70, 10);
	cout << "Game Paused!";
	hideCursor();
	while (_getch() != ESC) // we trap the player until he presses ESC again..
	{
		continue;
	}
	gotoxy(70, 10);
	cout << "            "; // instead of clearScreen
}

void setTextColor(Color colorToSet) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (int)colorToSet);
}

void hideCursor()
{
	HANDLE myconsole = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO CURSOR;
	CURSOR.dwSize = 1;
	CURSOR.bVisible = FALSE;
	SetConsoleCursorInfo(myconsole, &CURSOR);//second argument need pointer
}

void ThePacManGame::printManualInstrctions()
{
	clrscr();
	cout << "Hello there!, in this game you play the pacMan game." << endl
		<< "controlls are:" << endl << endl << "W -> up\nX -> down\nA -> left\nD -> right\nS -> STAY Mode" << endl<<endl 
		<<"You have 3 Lives, when ever a ghost \"eats\" you, your life gets reduce by one."<<endl
		<<"Your score increase by one every time you eat a breadcrumb, to win you need to eat " << VICTORY << " breadcrumbs."<<endl
		<<"If you want to Pause the game you can Press ESC,\nWhen ever you want to continue from the exact same point that you paused the game, press ESC again."<<endl<< endl;
}

void ThePacManGame::displayScore(int score)
{
	gotoxy(10, 21);
	cout << "Score: " << score;
	hideCursor();
}

void ThePacManGame::displayLives(int lives)
{
	gotoxy(40, 21);
	cout << "lives left: " << lives;
	hideCursor();
}

void ThePacManGame::displayGameOver()
{
	_flushall();
	clrscr();
	gotoxy(31, 10); // some comfortable location to show the messege.
	cout << "Game Over!";
	gotoxy(20, 14); // some comfortable location to show the messege.
	cout << "Press any key to go back to menu...";
	if (_getch()) {} // required to swallow up the input in buffer, in order to avoid entering "Invalid-choice" messege.
}

void ThePacManGame::displayGameVictory()
{
	_flushall();
	clrscr();
	gotoxy(31, 10); // some comfortable location to show the messege.
	cout << "You Won!";
	gotoxy(20, 14); // some comfortable location to show the messege.
	cout << "Press any key to go back to menu...";
	if (_getch()) {} // required to swallow up the input in buffer, in order to avoid entering "Invalid-choice" messege.
}