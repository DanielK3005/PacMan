#pragma once
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <process.h>
#include "Color.h"
#include "PacMan.h"
#include "Ghost.h"
#include "Board.h"

void setTextColor(Color);
void hideCursor();
void gotoxy(int, int);
void clrscr();

enum { ESC = 27, INSTRUCTIONS = 56, EXIT = 57 , VICTORY = 270};
using namespace std;

class ThePacManGame
{
	PacMan pacman;
	Ghost ghosts[2];
	Board board;

public:
	void init();
	void run(char choice);
	void reset();
	bool PacManGotEaten();
	char printMenu();
	bool isValidChoice(int choice);
	void gamePaused();
	void printManualInstrctions();
	void displayScore(int score);
	void displayLives(int lives);
	void displayGameOver();
	void displayGameVictory();
};