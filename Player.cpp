/**************************************************************************
 * AUTHOR  : Cameron W
 * PROJECT : Tic Tac Toe + AI In C++
 *************************************************************************/

#include "Player.h"

Player::Player() {
	mPlayerName  = "xxx";
	mPlayerToken = 'x';
}

Player::Player(string xPlayerName,
			   char   xPlayerToken) {
	mPlayerName  = xPlayerName;
	mPlayerToken = xPlayerToken;
}

Player::Player(Player & xPlayer) {
	mPlayerName = xPlayer.GetPlayerName();
	mPlayerToken = xPlayer.GetPlayerToken();
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

/**************************************************************************
 *
 *		 FUNCTION SetPlayerName
 * _____________________________________________________________________
 *		This function will prompt the player for their name and token
 *		the player should only pick an X or O;
 * _____________________________________________________________________
 * PRE-CONDITIONS:
 * 		xName - Player name to be stored in mPlayerName
 * POST-CONDITIONS:
 *		mPlayerName  - Stores the player's Name in a string variable
 *************************************************************************/
void Player::SetPlayerName(const string & xName) {
	mPlayerName = StringCharacterCheck(xName);
}

/**************************************************************************
 *
 *		 FUNCTION SetPlayerToken
 * _____________________________________________________________________
 *		This function will prompt the player for their name and token
 *		the player should only pick an X or O;
 * _____________________________________________________________________
 * PRE-CONDITIONS:
 * 		xToken - Player token to be stored in mPlayerToken
 * POST-CONDITIONS:
 *		mPlayerToken - Stores the player's Token in a char variable
 *************************************************************************/
void Player::SetPlayerToken(const char & xToken) {
	mPlayerToken = xToken;
}

/**************************************************************************
 *
 *		 FUNCTION SetPlayerNameAndToken
 * _____________________________________________________________________
 *		This function will prompt the player for their name and token
 *		the player should only pick an X or O;
 * _____________________________________________________________________
 * PRE-CONDITIONS:
 * 		xName - Player name to be stored in mPlayerName
 * 		xToken - Player token to be stored in mPlayerToken
 * POST-CONDITIONS:
 *		mPlayerName  - Stores the player's Name in a string variable
 *		mPlayerToken - Stores the player's Token in a char variable
 *************************************************************************/
void Player::SetPlayerNameAndToken(const string & xName,
						           const char   & xToken) {
	mPlayerName = StringCharacterCheck(xName);
	mPlayerToken = xToken;
}
