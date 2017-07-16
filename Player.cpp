/**************************************************************************
 * AUTHOR  : Cameron W
 * PROJECT : Tic Tac Toe + AI In C++
 *************************************************************************/

#include "Player.h"

namespace {  // anonymous namespace Start
/************************************************************************
 *  int CharInputCheck
 * _______________________________________________________________________
 * This function outputs the menu and tracks if the user inputs an
 *	invaild character or number within the range that was passed.
 * _______________________________________________________________________
 * PRE-CONDITIONS
 *		xPROMPT : prompt for user
 * POST-CONDITIONS
 * 		Returns a valid user choice (option) to the calling function
 ************************************************************************/
char CharInputCheck (const string xPROMPT) {
	bool someBool;					// PROCESSING	- determines whether
									// 				  the menu is output
	char input;						// IN & OUT		- user input choice

	do {
		someBool = false;

		// OUTPUT - the menu
		std::cout << xPROMPT;
		std::cin.get(input);
		std:cin.ignore(numeric_limits<streamsize>::max(), '\n');
	} while(someBool);

	return input;
}
} // anonymous namespace end

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
	std::cout << "What is your name Champion? ";
	std::getline(std::cin, mPlayerName);

	mPlayerToken = CharInputCheck ("What shall your Token Be? ");

	std::cout << "May your name become legend and be known for ever!";
	std::cout << std::endl;

}

