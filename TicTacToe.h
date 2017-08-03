/**************************************************************************
 * AUTHOR  : Cameron W
 * PROJECT : Tic Tac Toe + AI In C++
 *************************************************************************/

#ifndef TICTACTOE_H_
#define TICTACTOE_H_

#include "Player.h"
#include "InputValidation.h"

#include <iostream>
#include <iomanip>
#include <string>
#include <stdlib.h>
#include <limits>
using namespace std;

class TicTacToe : public InputValidation {
public:
	TicTacToe();
	virtual ~TicTacToe() {};

	void InitBoard();

	typedef char (*ptr)[3];

	// Getters
	ptr  GetBoard() {return mBoard;};
	char GetWhoWonToken() {return mWhoWon;};
	char GetWhosTurnItIs() {return mToken;};

	// Display
	void DisplayInstruct();
	void DisplayBoard();
	void DisplayWinner();

	// Other Stuff
	char CheckWin();
	char SwitchToken ();

private:
	static const int NUM_ROWS = 3; // the size of the columns in the array
	static const int NUM_COLS = 3; // the size of the rows in the arrayb

	char   mBoard[NUM_ROWS][NUM_COLS];	// tic tac toe Board - IN
	char   mWhoWon;  // Winning Piece - IN
	char   mToken;	 // current token -IN/OUT

	Player mPlayer1;  // Player 1 - IN
	Player mPlayer2;  // Player 2 - IN

};

#endif /* TICTACTOE_H_ */
