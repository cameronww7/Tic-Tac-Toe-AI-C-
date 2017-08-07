/**************************************************************************
 * AUTHOR  : Cameron W
 * PROJECT : Tic Tac Toe + AI In C++
 *************************************************************************/

#ifndef AI_H_
#define AI_H_

#include "Player.h"
#include "InputValidation.h"
#include "TicTacToe.h"

#include <iostream>
#include <iomanip>
#include <string>
#include <stdlib.h>
#include <limits>
#include <bits/stdc++.h>
using namespace std;

struct mMove
{
    int row, col;
};

class AI {
public:
	AI();
	virtual ~AI();

	bool IsThereAMove(TicTacToe xTicTacToeGame);
	int  HowManyPossibleMoves(TicTacToe xTicTacToeGame);

	void MakeAMove();
	int  MiniMax(TicTacToe xTicTacToeGame,
				int 	  xDepth,
				bool 	  xIsMax,
				const int NUM_ROWS,
				const int NUM_COLS);

private:
	static const int NUM_ROWS = 3; // the size of the columns in the array
	static const int NUM_COLS = 3; // the size of the rows in the array

	TicTacToe mTicTacToeGame;
	Player    mPlayerOne;
	Player    mPlayerTwo;

	int CheckStateOfBoard(TicTacToe xTicTacToeGame);
	mMove FindBestMove(TicTacToe xTicTacToeGame);

};

#endif /* AI_H_ */
