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

bool AI::IsThereAMove(TicTacToe mTicTacToeGame) {
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

int AI::HowManyPossibleMoves(TicTacToe mTicTacToeGame) {
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


