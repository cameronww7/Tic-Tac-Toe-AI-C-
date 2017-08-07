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

	typedef char (*multiDimBoard)[3];

	// Getters
	multiDimBoard GetBoard() {return mBoard;};
	const char    GetWhoWonToken()  {return mWhoWon;};
	const char    GetWhosTurnItIs() {return mToken;};
	const char    GetPlayerOne()    {return mPlayer1;};
	const char    GetPlayerTwo()    {return mPlayer2;};

	// Setters
	void SetPlayerOneToken(char xToken) {mPlayer1 = xToken;};
	void SetPlayerTwoToken(char xToken) {mPlayer2 = xToken;};

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

	char  mBoard[NUM_ROWS][NUM_COLS];	// tic tac toe Board - IN
	char  mWhoWon;  // Winning Piece - IN
	char  mToken;	 // current token -IN/OUT

	char mPlayer1;  // Player 1 - IN
	char mPlayer2;  // Player 2 - IN

};

#endif /* TICTACTOE_H_ */
