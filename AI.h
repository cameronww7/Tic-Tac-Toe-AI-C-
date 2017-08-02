/**************************************************************************
 * AUTHOR  : Cameron W
 * PROJECT : Tic Tac Toe + AI In C++
 *************************************************************************/

#ifndef AI_H_
#define AI_H_

#include "Player.h"
#include "InputValidation.h"
#include "TicTacToe.h"

#include <iostream>
#include <iomanip>
#include <string>
#include <stdlib.h>
#include <limits>
using namespace std;

class AI {
public:
	AI();
	virtual ~AI();

private:
	static const int NUM_ROWS = 3; // the size of the columns in the array
	static const int NUM_COLS = 3; // the size of the rows in the array

	TicTacToe mTicTacToeGame;
	Player mPlayerOne;
	Player mPlayerTwo;


};

#endif /* AI_H_ */
