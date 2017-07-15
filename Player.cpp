/**************************************************************************
 * AUTHOR  : Cameron W
 * PROJECT : Tic Tac Toe + AI In C++
 *************************************************************************/

#include "Player.h"

Player::Player() {
	// TODO Auto-generated constructor stub
	mPlayerName = "xxx";
}

Player::~Player() {
	// TODO Auto-generated destructor stub
}

/**************************************************************************
 *
 *		 FUNCTION GetPlayers
 * _____________________________________________________________________
 *		This function will prompt each user for their name, then store
 *		them to either X or O depending on who went first. Player 1 is X
 *		player 2 is O's.
 * _____________________________________________________________________
 * PRE-CONDITIONS:
 * 		player1   : player 1's name
 *		player2   : player 2's name
 * POST-CONDITIONS:
 *		stores the players names in strings for later use.
 *************************************************************************/
void Player::GetPlayers() {
	std::cout << "what is your name Champion? ";
	std::getline(std::cin, mPlayerName);

	std::cout << "May your names become legend and be known for ever!";
	std::cout << std::endl;

}

