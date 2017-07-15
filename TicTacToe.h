/**************************************************************************
 * AUTHOR  : Cameron W
 * PROJECT : Tic Tac Toe + AI In C++
 *************************************************************************/

#ifndef TICTACTOE_H_
#define TICTACTOE_H_

#include "Player.h"

#include <iostream>
#include <iomanip>
#include <string>
#include <stdlib.h>
#include <limits>
using namespace std;

class TicTacToe {
public:
	TicTacToe();
	virtual ~TicTacToe();

	void DisplayInstruct();
	void DisplayBoard();
	void InitBoard();
	void DisplayWinner();

	char CheckWin();
	char SwitchToken ();

private:
	static const int NUM_ROWS = 3; // the size of the columns in the array
	static const int NUM_COLS = 3; // the size of the rows in the array

	char   mBoard[NUM_ROWS][NUM_COLS];	// tic tac toe Board - IN
	char   mWhoWon;  // Winning Piece - IN
	char   mToken;	// current token -IN/OUT

	Player mPlayer1;  // Player 1 - IN
	Player mPlayer2;  // Player 2 - IN

};

#endif /* TICTACTOE_H_ */
