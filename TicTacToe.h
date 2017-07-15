/**************************************************************************
 * AUTHOR  : Cameron W
 * PROJECT : Tic Tac Toe + AI In C++
 *************************************************************************/

#ifndef TICTACTOE_H_
#define TICTACTOE_H_

#include <iostream>
#include <iomanip>
#include <string>
#include <stdlib.h>
using namespace std;

class TicTacToe {
public:
	TicTacToe();
	virtual ~TicTacToe();

	void OutputInstruct();
	void DisplayBoard();
	void InitBoard();
	void OutputWinner();

	char CheckWin();
	char SwitchToken ();

private:
	static const int NUM_ROWS = 3; // the size of the columns in the array
	static const int NUM_COLS = 3; // the size of the rows in the array

	char   mBoard[NUM_ROWS][NUM_COLS];	// tic tac toe Board - IN
	char   mWhoWon;  // Winning Piece - IN
	char   mToken;	// current token -IN/OUT

	string mNameOfPlayer1;  // name of player 1 - IN
	string mNameOfPlayer2;  // name of player 2 - IN

};

#endif /* TICTACTOE_H_ */
