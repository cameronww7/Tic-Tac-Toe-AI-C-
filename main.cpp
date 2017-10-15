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
	std::cout << "> Tic Tac Toe C++" << std::endl;

	std::cout << "> Creating Variables" << std::endl;
	int playerOneWinCount = 0;
	int playerTwoWinCount = 0;
	int tieCount 		  = 0;

	std::cout << "> Creating Objects" << std::endl;
	Player playerOne("p1", 'x');
	Player playerTwo("p2", 'o');

	TicTacToe ticTacToeGame;

	AI aiPlayerOne(playerOne,
				   playerTwo,
				   ticTacToeGame);
	AI aiPlayerTwo(playerTwo,
				   playerOne,
				   ticTacToeGame);

	std::cout << std::endl << ">      <<< Starting Game >>>" << std::endl;
	std::cout << "> <<< " << NUM_OF_GAMES << " Games to be Played >>>" << std::endl << std::endl;

	for (int index = 0; index < NUM_OF_GAMES; index++) {
		std::cout << "> Starting Game Number " << index+1 << std::endl;

		if(NUM_OF_GAMES < (NUM_OF_GAMES / 2)) {
			std::cout << "> " << playerOne.GetPlayerName() << " Has Started" << std::endl;
			ticTacToeGame.StartingToken(playerOne.GetPlayerToken());
		} else {
			std::cout << "> " << playerTwo.GetPlayerName() << " Has Started" << std::endl;
			ticTacToeGame.StartingToken(playerTwo.GetPlayerToken());
		}

		static int numOfMovesMade = 0;

		while(ticTacToeGame.CheckForAWin()) {
			aiPlayerOne.MakeAMove();

		}

		if (ticTacToeGame.CheckWin() == playerOne.GetPlayerToken()) {
			std::cout << "> " << playerOne.GetPlayerName() << " Has Won" << std::endl;
			playerOneWinCount++;
		} else if (ticTacToeGame.CheckWin() == playerTwo.GetPlayerToken()) {
			std::cout << "> " << playerTwo.GetPlayerName() << " Has Won" << std::endl;
			playerTwoWinCount++;
		} else if (ticTacToeGame.CheckForTie()){
			std::cout << "> " << "A Tie Has Happen " << std::endl;
			tieCount++;
		} else {
			std::cout << "> " << "No one has Won or Tie'ed, So Error" << std::endl;
		}
		std::cout << "> Clearing Board\n\n";
		ticTacToeGame.ClearBoard();
	}

	std::cout << "\n\n";
	std::cout << "> There were " << NUM_OF_GAMES << " played." << std::endl;
	std::cout << "> --------------------------------" << std::endl;
	std::cout << ">  Wins " << std::endl;
	std::cout << "> --------------------------------" << std::endl;
	std::cout << "> Player 1 : " << playerOneWinCount << std::endl;
	std::cout << "> Player 2 : " << playerTwoWinCount << std::endl;
	std::cout << ">   Ties   : "  << tieCount         << std::endl;
	std::cout << "> --------------------------------" << std::endl;
	std::cout << "> End of Game";

	return 0;
}



