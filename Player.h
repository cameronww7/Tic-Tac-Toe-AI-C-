/**************************************************************************
 * AUTHOR  : Cameron W
 * PROJECT : Tic Tac Toe + AI In C++
 *************************************************************************/

#ifndef PLAYER_H_
#define PLAYER_H_

// Class Directives
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
 *		Class :: Player
 * _____________________________________________________________________
 *
 *		Objective :
 *		The goal of this class is to create a player meaning it must have
 *		the attributes a player has, such as a name and token. It must
 *		also be able to return the attributes of the player if needed.
 * _____________________________________________________________________
 *
 *************************************************************************/

class Player : public InputValidation {
public:
	Player(); 					 // Base Constructor
	Player(string xPlayerName,
		   char   xPlayerToken); // Input Constructor
	Player(Player & xPlayer); 	 // Copy Constructor
	virtual ~Player() {};

	// Getters
	string GetPlayerName()  {return mPlayerName;};
	char   GetPlayerToken() {return mPlayerToken;};

	// Setters
	void SetPlayerName(const string & xName);
	void SetPlayerToken(const char & xToken);
	void SetPlayerNameAndToken(const string & xName,
							   const char   & xToken);

	// Other Stuff
	void PromptForPlayerInfo();

private:
	string mPlayerName;  // Player's chosen name
	char   mPlayerToken; // Players chosen token
};

#endif /* PLAYER_H_ */
