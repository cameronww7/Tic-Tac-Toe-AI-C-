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
	virtual ~Player() {};

	string GetPlayerName()  {return mPlayerName;};
	char   GetPlayerToken() {return mPlayerToken;};

	void PromptForPlayerInfo(); // Prompts User for their Information

private:
	string mPlayerName;  // Player's chosen name
	char   mPlayerToken; // Players chosen token
};

#endif /* PLAYER_H_ */
