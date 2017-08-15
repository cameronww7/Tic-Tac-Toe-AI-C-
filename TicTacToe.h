/**************************************************************************
 * AUTHOR  : Cameron W
 * PROJECT : Tic Tac Toe + AI In C++
 *************************************************************************/

#ifndef TICTACTOE_H_
#define TICTACTOE_H_

// Class Directives
#include "Player.h"
#include "InputValidation.h"

// Preprocessor Directives
#include <iostream>
#include <iomanip>
#include <string>
#include <stdlib.h>
#include <limits>
using namespace std;

/**************************************************************************
 *
 *		Class :: TicTacToe
 * _____________________________________________________________________
 *
 *		Objective :
 *		The goal of this class is to create a game of Tic Tac Toe. On
 *		top on just creating a game it will manage the game's process.
 *		Meaning it should make sure who's move it is and if someone has
 *		win's the game. Because its part of a greater process it must be
 *		able to return its contents that will be used for unknown to
 *		this classes intentions.
 * _____________________________________________________________________
 *
 *************************************************************************/

class TicTacToe : public InputValidation {
public:
	TicTacToe(); 							// Base Constructor
	TicTacToe(char xPlayerOneToken,
			  char xPlayerTwoToken); 		// Input Constructor
	TicTacToe(TicTacToe & xTicTacToeGame); 	// Copy Constructor
	virtual ~TicTacToe() {};

	void ClearBoard();

	typedef char (*multiDimBoard)[3];

	// Getters
	multiDimBoard GetBoard() {return mBoard;};
	const char    GetWhoWonToken()  {return mWhoWon;};
	const char    GetWhosTurnItIs() {return mToken;};
	const char    GetPlayerOne()    {return mPlayer1;};
	const char    GetPlayerTwo()    {return mPlayer2;};
	const char	  GetStartingToken(){return mStartingToken;};

	// Setters
	void SetPlayerOneToken(char xToken) {mPlayer1 = xToken;};
	void SetPlayerTwoToken(char xToken) {mPlayer2 = xToken;};

	// Display
	void DisplayInstruct();
	void DisplayBoard();
	void DisplayWinner();

	// Other Stuff
	bool IsThereAMove();
	char CheckWin();
	char SwitchToken();
	void StartingToken(char xToken);

private:
	static const int NUM_ROWS = 3; // the size of the columns in the array
	static const int NUM_COLS = 3; // the size of the rows in the array

	char mBoard[NUM_ROWS][NUM_COLS]; // tic tac toe Board - IN
	char mWhoWon;  		 // Winning Piece - IN
	char mToken;  		 // Current token - IN/OUT
	char mStartingToken; // Passed in starting Token

	char mPlayer1; // Player 1 - IN
	char mPlayer2; // Player 2 - IN
};

#endif /* TICTACTOE_H_ */
