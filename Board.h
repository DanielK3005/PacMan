#pragma once
#include "Point.h"
#include "Color.h"

#define FOOD '*'
#define WALL '#'

class Board {
	char board[LENGTH * (DEPTH + 1) + 1] = 
		//   012345678901234567890123456789012345678901234567890123456789
			"############################## #############################\n"
			"# * * * * * * * * * * * * *  # # * * * * * * * * * * * * * #\n"
			"# * * * * * * * * * * * * *  # # * * * * * * * * * * * * * #\n"
			"# *  ### #### * * * * * * *      * * * * * * #### #### * * #\n"
			"# * *  # # * * * * * * * * * * * * * * * * * *  # #  * * * #\n"
			"# * *  # # * * * * * ################### * * *  # #  * * * #\n"
			"# * *  # # * * * * * * * *         * * * * * *  # #  * * * #\n"
			"# * *        ######       #### ####    ######        * * * #\n"
			"#####                     ##     ##                     ####\n"
			"             * * * * * *  #########  * * * * * *            \n"
			"#####        * * * * * * * * * * * * * * * * * *        ####\n"
			"#            ######                    ######              #\n"
			"# * * *   * * * * * * * * * * * * * * * * * * *  * * * * * #\n"
			"# * *  # #           ####################      # # * * * * #\n"
			"# * *  # #                                     # # * * * * #\n"
			"# * *  # #           ####################      # # * * * * #\n"
			"# * #### #### * * * * * * *      * * * * *  #### ####  * * #\n"
			"# * * * * * * * * * * * * *  # # * * * * * * * * * * * * * #\n"
			"# * * * * * * * * * * * * *  # # * * * * * * * * * * * * * #\n"
			"############################## #############################\n"
	;
public:

	bool foodArr[LENGTH + 1][DEPTH + 1] = { false };
	bool WallsArray[LENGTH + 1][DEPTH + 1] = { false };
	void printBoard() const { cout << board; }
	void printBoardWithColor() const;
	const char GetCh(int x, int y) { return board[(x * (DEPTH + 1)) + y]; }
	void initFoodAndWalls();
	bool IsThereAWall(Point& obj) { return WallsArray[obj.GetY()][obj.GetX()]; }
	bool isFoodInXY(Point& obj) { return foodArr[obj.GetY()][obj.GetX()]; }
	void updateFoodArr(Point& obj) { foodArr[obj.GetY()][obj.GetX()] = false; }
};