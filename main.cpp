/**************************************************************************
 * AUTHOR  : Cameron W
 * PROJECT : Tic Tac Toe + AI In C++
 *************************************************************************/

#include "header.h"
#include "AI.h"
#include "Player.h"
#include "TicTacToe.h"

/**************************************************************************
 *
 *		Program :: Multi-Dimensional Array - Tic Tac Toe
 * _____________________________________________________________________
 *
 *		Objective :
 *		This program will first out put instructions on how to play
 *		tic tac toe then prompt the user's for their names and then
 *		will let them play. It will display each and every play, check
 *		if there is a win or a tie and then re-prompt the user if they
 *		would like to play again.
 * _____________________________________________________________________
 *
 *************************************************************************/

int main() {

	std::cout << "Tic Tac Toe C++";

	int playerOneWinCount = 0;
	int playerTwoWinCount = 0;
	int tieCount 		  = 0;

	Player playerOne("p1", 'x');
	Player playerTwo("p2", 'o');

	TicTacToe ticTacToeGame;

	AI aiPlayerOne(playerOne,
				   playerTwo,
				   ticTacToeGame);
	AI aiPlayerTwo(playerTwo,
				   playerOne,
				   ticTacToeGame);

	for (int index = 0; index < 1000; index++) {
		while(ticTacToeGame.IsThereAMove()) {

		}

		if (ticTacToeGame.CheckWin() == 'x') {
			playerOneWinCount++;
		} else if (ticTacToeGame.CheckWin() == 'o') {
			playerTwoWinCount++;
		} else {
			tieCount++;
		}
	}

	return 0;
}



