/**************************************************************************
 * AUTHOR  : Cameron W
 * PROJECT : Tic Tac Toe + AI In C++
 *************************************************************************/

#include "Player.h"

Player::Player() {
	mPlayerName  = "xxx";
	mPlayerToken = 'x';
}

/**************************************************************************
 *
 *		 FUNCTION PromptForPlayerInfo
 * _____________________________________________________________________
 *		This function will prompt the player for their name and token
 *		the player should only pick an X or O;
 * _____________________________________________________________________
 * PRE-CONDITIONS:
 * 		N/A
 * POST-CONDITIONS:
 *		mPlayerName  - Stores the player's Name in a string variable
 *		mPlayerToken - Stores the player's Token in a char variable
 *************************************************************************/
void Player::PromptForPlayerInfo() {
	mPlayerName  = StringInputCheck("What is your name Champion? ");
	mPlayerToken = CharInputCheck("What shall your Token Be? ");

	std::cout << "May your name become legend and be known for ever!";
	std::cout << std::endl;

}

