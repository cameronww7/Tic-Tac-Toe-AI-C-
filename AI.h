/**************************************************************************
 * AUTHOR  : Cameron W
 * PROJECT : Tic Tac Toe + AI In C++
 *************************************************************************/

#ifndef AI_H_
#define AI_H_

// Class Directives
#include "Player.h"
#include "InputValidation.h"
#include "TicTacToe.h"

// Preprocessor Directives
#include <iostream>
#include <iomanip>
#include <string>
#include <stdlib.h>
#include <limits>
#include <bits/stdc++.h>
using namespace std;

struct mMove {
    int structRow; // Row slot in Multi-Dim Array
	int structCol; // Col slot in Multi-Dim Array
};

/**************************************************************************
 *
 *		Class :: AI
 * _____________________________________________________________________
 *
 *		Objective :
 *		The goal of this class is to win the a Tic Tac Toe Game, using its
 *		superior method of accessing every possible option and finding the
 *		best, most optimal way to win.
 * _____________________________________________________________________
 *
 *************************************************************************/

class AI {
public:
	AI(); // Base Constructor
	AI(Player & xPlayerOne,
	   Player & xPlayerTwo,
	   TicTacToe & xTicTacToeGame); // Input Constructor
	virtual ~AI();

	void MakeAMove();

private:
	static const int NUM_ROWS = 3; // the size of the columns in the array
	static const int NUM_COLS = 3; // the size of the rows in the array

	TicTacToe mTicTacToeGame;
	Player    mMe;
	Player    mOpp;

	bool DidSomeoneWin();
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
