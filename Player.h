/**************************************************************************
 * AUTHOR  : Cameron W
 * PROJECT : Tic Tac Toe + AI In C++
 *************************************************************************/

#ifndef PLAYER_H_
#define PLAYER_H_

#include <iostream>
#include <iomanip>
#include <string>
#include <stdlib.h>
#include <limits>
using namespace std;

class Player {
public:
	Player();
	virtual ~Player() {};

	string GetPlayerName()  {return mPlayerName;};
	char   GetPlayerToken() {return mPlayerToken;};

	void PromptForPlayerInfo();

private:
	string mPlayerName;
	char   mPlayerToken;
};

#endif /* PLAYER_H_ */
