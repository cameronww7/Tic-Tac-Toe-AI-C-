/**************************************************************************
 * AUTHOR  : Cameron W
 * PROJECT : Tic Tac Toe + AI In C++
 *************************************************************************/

#include "AI.h"

AI::AI() {
	mPlayerOne.SetPlayerNameAndToken("Jim", 'x');
	mPlayerTwo.SetPlayerNameAndToken("Sam", 'o');

}

AI::~AI() {

}

/************************************************************************
 *  bool IsThereAMove
 * _______________________________________________________________________
 * This function will find in the board if there is a possible move and
 * return a true or false depending if it finds one.
 * _______________________________________________________________________
 * PRE-CONDITIONS
 *		mTicTacToeGame : must be made
 * POST-CONDITIONS
 * 		isThereAMove - returns either True or False
 ************************************************************************/
bool AI::IsThereAMove() {
	bool isThereAMove = false;

	for (int rows = 0; rows < NUM_ROWS && isThereAMove != true; rows++) {
		for (int cols = 0; cols < NUM_COLS && isThereAMove != true; cols++) {
			if (mTicTacToeGame.GetBoard()[rows][cols] == ' ') {
				isThereAMove = true;
			}
		}
	}

	return isThereAMove;
}

/************************************************************************
 *  int HowManyPossibleMoves
 * _______________________________________________________________________
 * This function will count how many possible moves are left on the board.
 * _______________________________________________________________________
 * PRE-CONDITIONS
 *		mTicTacToeGame : must be made
 * POST-CONDITIONS
 * 		howManyPossibleMoves - returns either True or False
 ************************************************************************/
int AI::HowManyPossibleMoves() {
	int howManyPossibleMoves = 0;

	for (int rows = 0; rows < NUM_ROWS; rows++) {
		for (int cols = 0; cols < NUM_COLS; cols++) {
			if (mTicTacToeGame.GetBoard()[rows][cols] == ' ') {
				howManyPossibleMoves++;
			}
		}
	}

	return howManyPossibleMoves;
}


