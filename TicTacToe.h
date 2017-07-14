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

class Tic_Tac_Toe {
public:
	Tic_Tac_Toe();
	virtual ~Tic_Tac_Toe();

	void OutputInstruct(); // displays the instructions for the game
	void DisplayBoard(); // tic tac toe Board - IN
	void InitBoard(); // tic tac toe Board - IN
	void OutputWinner(); // players O's name - OUT

	char CheckWin(); // tic tac toe Board - IN

private:
	const int NUM_ROWS = 3; // the size of the columns in the array
	const int NUM_COLS = 3; // the size of the rows in the array

	char   mBoard[NUM_ROWS][NUM_COLS];	// tic tac toe Board - IN
	string mNameOfPlayer1;  // name of player 1 - IN
	string mNameOfPlayer2;  // name of player 2 - IN
	char   mWhoWon;  // Winning Piece - IN

};

#endif /* TICTACTOE_H_ */
