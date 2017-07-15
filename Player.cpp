/**************************************************************************
 * AUTHOR  : Cameron W
 * PROJECT : Tic Tac Toe + AI In C++
 *************************************************************************/

#include "Player.h"

Player::Player() {
	// TODO Auto-generated constructor stub
	mPlayerName  = "xxx";
	mPlayerToken ='x';
}

Player::~Player() {
	// TODO Auto-generated destructor stub
}

/**************************************************************************
 *
 *		 FUNCTION GetPlayer
 * _____________________________________________________________________
 *		This function will prompt the player for their name and token
 *		the player should only pick an X or O;
 * _____________________________________________________________________
 * PRE-CONDITIONS:
 * 		mPlayerName   : player 1's name
 * POST-CONDITIONS:
 *		stores the players names in strings for later use.
 *************************************************************************/
void Player::GetPlayer() {
	std::cout << "what is your name Champion? ";
	std::getline(std::cin, mPlayerName);

	std::cout << "May your names become legend and be known for ever!";
	std::cout << std::endl;

}

