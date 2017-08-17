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

const int NUM_OF_GAMES = 1000;

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

	for (int index = 0; index < NUM_OF_GAMES; index++) {
		if(NUM_OF_GAMES < (NUM_OF_GAMES / 2)) {
			ticTacToeGame.StartingToken(playerOne.GetPlayerToken());
		} else {
			ticTacToeGame.StartingToken(playerTwo.GetPlayerToken());
		}

		while(ticTacToeGame.IsThereAMove()) {

		}

		if (ticTacToeGame.CheckWin() == playerOne.GetPlayerToken()) {
			playerOneWinCount++;
		} else if (ticTacToeGame.CheckWin() == playerTwo.GetPlayerToken()) {
			playerTwoWinCount++;
		} else {
			tieCount++;
		}
		ticTacToeGame.ClearBoard();
	}

	std::cout << "There were " << NUM_OF_GAMES << "played." << std::endl;
	std::cout << " Wins " << std::endl;
	std::cout << "--------------------------------" << std::endl;
	std::cout << "Player 1 : " << playerOneWinCount << std::endl;
	std::cout << "Player 2 : " << playerTwoWinCount << std::endl;
	std::cout << "  Ties   : " << tieCount          << std::endl;

	return 0;
}



