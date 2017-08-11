/**************************************************************************
 * AUTHOR  : Cameron W
 * PROJECT : Tic Tac Toe + AI In C++
 *************************************************************************/

#ifndef PLAYER_H_
#define PLAYER_H_

#include "InputValidation.h"

#include <iostream>
#include <iomanip>
#include <string>
#include <stdlib.h>
#include <limits>
using namespace std;

class Player : public InputValidation {
public:
	Player();
	Player(string xPlayerName,
		   char   xPlayerToken);
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
