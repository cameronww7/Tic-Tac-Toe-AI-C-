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
    int structRow;
	int structCol;
};

class AI {
public:
	AI();
	AI(Player xPlayerOne,
	   Player xPlayerTwo,
	   TicTacToe xTicTacToeGame);
	virtual ~AI();

private:
	static const int NUM_ROWS = 3; // the size of the columns in the array
	static const int NUM_COLS = 3; // the size of the rows in the array

	TicTacToe mTicTacToeGame;
	Player    mMe;
	Player    mOpp;

	void MakeAMove();
	bool IsThereAMove(TicTacToe xTicTacToeGame);
	int  HowManyPossibleMoves(TicTacToe xTicTacToeGame);
	int  CheckStateOfBoard(TicTacToe xTicTacToeGame);
	int  MiniMax(TicTacToe xTicTacToeGame,
					int 	  xDepth,
					bool 	  xIsMax,
					const int NUM_ROWS,
					const int NUM_COLS);
	mMove FindBestMove(TicTacToe xTicTacToeGame);
};

#endif /* AI_H_ */
