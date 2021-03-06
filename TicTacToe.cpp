/**************************************************************************
 * AUTHOR  : Cameron W
 * PROJECT : Tic Tac Toe + AI In C++
 *************************************************************************/

#include "TicTacToe.h"

TicTacToe::TicTacToe(void) {
	for (int rowCnt = 0; rowCnt < NUM_ROWS; rowCnt++) {
		for (int colCnt = 0; colCnt < NUM_COLS; colCnt++) {
			mBoard[rowCnt][colCnt]= ' ';
		}
	}

	mWhoWon        = 'C';
	mToken         = 'C';
	mStartingToken = 'C';
	mPlayer1	   = 'C';
	mPlayer2	   = 'C';
}

TicTacToe::TicTacToe(char xPlayerOneToken,
		  	  	     char xPlayerTwoToken) {
	for (int rowCnt = 0; rowCnt < NUM_ROWS; rowCnt++) {
		for (int colCnt = 0; colCnt < NUM_COLS; colCnt++) {
			mBoard[rowCnt][colCnt]= ' ';
		}
	}

	mWhoWon        = 'C';
	mToken         = 'C';
	mStartingToken = 'C';
	mPlayer1	   = xPlayerOneToken;
	mPlayer2	   = xPlayerTwoToken;
}

TicTacToe::TicTacToe(TicTacToe & xTicTacToeGame) {
	mBoard[NUM_ROWS][NUM_COLS] = xTicTacToeGame.GetBoard()[NUM_ROWS][NUM_COLS];
	mWhoWon  	   = xTicTacToeGame.GetWhosTurnItIs();
	mToken   	   = xTicTacToeGame.GetWhoWonToken();
	mStartingToken = xTicTacToeGame.GetStartingToken();
	mPlayer1	   = xTicTacToeGame.GetPlayerOne();
	mPlayer2 	   = xTicTacToeGame.GetPlayerTwo();
}

/**************************************************************************
 *
 *		 FUNCTION DisplayInstruct
 * _____________________________________________________________________
 *		This function will output to the players the rules and how
 *		to play this version of tic tac toe
 * _____________________________________________________________________
 * PRE-CONDITIONS:
 *		none
 *
 * POST-CONDITIONS:
 *		none
 *************************************************************************/
void TicTacToe::DisplayInstruct() {
	std::cout << "Welcome Champions! You have fought bravely and your\n"
			     "strength has gotten you thus far! Can your wisdom, your\n"
				 "logic get you farther to become the alone standing\n"
				 "champion! Here, NOW in this final battle shall you\n"
				 "use all you possess to out do your opponent!\n"
				 "Now PICK YOUR SIDE!\n"
				 "Shall thou pick thou X? \n"
				 "The X clan comes from an ancient skill warriors, bend on\n"
				 "war. Their a strong foe, waiting to attack with their \n"
				 "X slice, no foe has ever be stuck and lived"
				 "Or do thou pick the O? \n"
				 "The Nobal Os, from the kingdom in the deep mountains. \n"
				 "Their know for their goal to keep peace in all the lands \n"
				 "the Circle table for all kings sit equal among each other \n"
				 "The game is simple, you must get three of your symbol in \n "
				 "a line or diagonal. The First to do this, shall win. \n"
				 "To enter your symbol you must put the spot numbers with\n"
				 "a space in between, for example ( middle spot is : 2 2 )\n"
				 "WIN and continue your walk has CHAMPION OF THE CAMPIONS\n"
				 "                  Do you Dare?";
}

/**************************************************************************
 *
 *		 FUNCTION DisplayBoard
 * _____________________________________________________________________
 *		The function displays the current board. Meaning if there are
 *		any plays it will display them through the array
 * _____________________________________________________________________
 * PRE-CONDITIONS:
 * 		mBoard[][] : the multi array of the board
 *
 * POST-CONDITIONS:
 *		RETURNS: the current plays on the board
 *************************************************************************/
void TicTacToe::DisplayBoard(void) {
	//clears the screen before the new board goes out
	system("cls");

	std::cout << std::endl;
	std::cout << std::setw(10) << "1" << std::setw(8) << "2" << std::setw(9) << "3\n";

	//first FOR loop creating the horizontal lines for the grid of the game
	for (int row = 0; row < NUM_ROWS; row++) {
		std::cout << std::setw(7)  << "[" << row + 1 << "][1] | " << "[" << row + 1;
		std::cout << "][2] | "     << "[" << row + 1 << "][3]"    << std::endl;
		std::cout << std::setw(14) << "|" << std::setw(9) << "|"  << std::endl;

		//FOR loop that prints the Lines for the grid for the game
		for (int col = 0; col < NUM_COLS; col++) {
			switch(col) {
				case 0: std::cout << row + 1 << std::setw(9) << mBoard[row][col];
						std::cout << std::setw(4) << "|";
						break;

				case 1: std::cout << std::setw(4) << mBoard[row][col];
						std::cout << std::setw(5) << "|";
						break;

				case 2: std::cout << std::setw(4) << mBoard[row][col] << std::endl;
						break;

				default: std::cout << "ERROR!\n\n";
						break;
			}
		}
		std::cout << std::setw(14) << "|" << std::setw(10) << "|\n";

		//if statement to print the lines between to create rows
		if (row != 2) {
			std::cout << std::setw(32) << "-----------------------\n";
		}
	}
	std::cout << std::endl << std::endl;
}

/**************************************************************************
 *
 *		 FUNCTION ClearBoard
 * _____________________________________________________________________
 *		This function will initialize each of the 9 spaces on the board
 *		as a white space for future X's and O's
 * _____________________________________________________________________
 * PRE-CONDITIONS:
 * 		mBoard[][] : the multi array of the board
 *
 * POST-CONDITIONS:
 * 		There is none, it just makes the spaces int he array white spaces
 *
 *************************************************************************/
void TicTacToe::ClearBoard(void) {
	for (int rowCnt = 0; rowCnt < NUM_ROWS; rowCnt++) {
		for (int colCnt = 0; colCnt < NUM_COLS; colCnt++) {
			mBoard[rowCnt][colCnt]= ' ';
		}
	}
}

/**************************************************************************
 *
 *		 FUNCTION DisplayWinner
 * _____________________________________________________________________
 *		This function will take in the char (either X or O) and output
 *		the user who won their name and say they have won the game.
 * _____________________________________________________________________
 * PRE-CONDITIONS:
 *		mWhoWon : must be either an X or O
 *		mPlayer1   : player 1's name
 *		mPlayer2   : player 2's name
 *
 * POST-CONDITIONS:
 *		outputs the current winner with their name!
 *************************************************************************/
void TicTacToe::DisplayWinner(void) {
	switch(mWhoWon) {
		case 'X' : std::cout << mPlayer1
						<< " HAS WON, his wisdom, his logic, his "
						   "unwavering determination has out done "
						   "the noble O's and now he shall go down "
						   "as history. May his name Last through "
						   "out the ages";
					break;
		case 'O' : std::cout << mPlayer2
					 	<< " Has risen to Champion, his noble "
						   "quest has given him the strength "
						   "nay the will power to over come "
						   "each and every battle to become"
						   "CHAMPION OF THE CHAMPIONS ";
					break;
		case 'C' : 	std::cout << "Your Game has ended in a bloody tie, truly"
							     " both you warriors are the best from each"
							     "land. Now rest up and do you dare to fight again"
							     "? your do you flee?";
					std::cout << endl;
					break;
	}
}

/************************************************************************
 *  bool IsThereAMove
 * _______________________________________________________________________
 * This function will find in the board if there is a possible move and
 * return a true or false depending if it finds one.
 * _______________________________________________________________________
 * PRE-CONDITIONS
 *		mBoard : must be made
 *
 * POST-CONDITIONS
 * 		isThereAMove - returns either True or False
 ************************************************************************/
bool TicTacToe::IsThereAMove(void) {
	bool isThereAMove = false;

	for (int rows = 0; rows < NUM_ROWS && isThereAMove != true; rows++) {
		for (int cols = 0; cols < NUM_COLS && isThereAMove != true; cols++) {
			if (mBoard[rows][cols] == ' ') {
				isThereAMove = true;
			}
		}
	}

	return isThereAMove;
}

/**************************************************************************
 *
 *		 FUNCTION CheckWin
 * _____________________________________________________________________
 *		This function will take in the current play's and compare them to
 *		the other places to find if there is a win, either up and down
 *		or side to side, or diagonal
 * _____________________________________________________________________
 * PRE-CONDITIONS:
 *		mBoard[][] : the multi array of the board
 *
 * POST-CONDITIONS:
 * 		winnerWinner : sends back who won if their is a winner or just a tie
 *************************************************************************/
char TicTacToe::CheckWin(void) {
	char winnerWinner = 'C';
	int  index = 0;

	// enter the do while loop checking if their is a win and will exit
	// if there is either a win or index is three
	do {
		//checks if there is a horizontal win
		if(mBoard[index][0] != ' ' &&
		   mBoard[index][0] == mBoard[index][1] &&
		   mBoard[index][0] == mBoard[index][2]) {
			winnerWinner = mBoard[index][0];
		}

		//checks if there is a vertical win
		if(mBoard[0][index] != ' ' &&
		   mBoard[0][index] == mBoard[1][index] &&
		   mBoard[0][index] == mBoard[2][index]) {
			winnerWinner = mBoard[0][index];
		}

		//increase index so it will check new horizontal and vertical wins
		index = index + 1;
	} while(winnerWinner == 'C' && index < 3);

	// checks if there is a diagonal win from left to right
	if(winnerWinner == 'C') {
		if(mBoard[0][0] != ' ' &&
		   mBoard[0][0] == mBoard[1][1] &&
		   mBoard[0][0] == mBoard[2][2]) {
			winnerWinner = mBoard[0][0];
		}

		// checks if there is a diagonal win from right to left
		if(mBoard[0][2] != ' ' &&
		   mBoard[0][2] == mBoard[1][1] &&
		   mBoard[0][2] == mBoard[2][0]) {
			winnerWinner = mBoard[0][2];
		}
	}
	//returns the winner or the C for no win or tie
	return winnerWinner;
}

/**************************************************************************
 *
 *		 FUNCTION CheckForAWin
 * _____________________________________________________________________
 *		Checks to see if there is a win and then checks for a if there
 *		are any moves and if there is no win or moves its a tie.
 * _____________________________________________________________________
 * PRE-CONDITIONS:
 *		mBoard[][] : the multi array of the board
 *
 * POST-CONDITIONS:
 * 		winnerWinner : sends back who won if their is a winner or just a tie
 *************************************************************************/
bool TicTacToe::CheckForAWin(void) {
	bool thereIsATie = false;

	if(CheckWin() == 'C') {
		thereIsATie = true;
	}

	return thereIsATie;
}

/**************************************************************************
 *
 *		 FUNCTION CheckForTie
 * _____________________________________________________________________
 *		Checks to see if there is a win and then checks for a if there
 *		are any moves and if there is no win or moves its a tie.
 * _____________________________________________________________________
 * PRE-CONDITIONS:
 *		mBoard[][] : the multi array of the board
 *
 * POST-CONDITIONS:
 * 		winnerWinner : sends back who won if their is a winner or just a tie
 *************************************************************************/
bool TicTacToe::CheckForTie(void) {
	bool thereIsATie = false;

	if(CheckWin() == 'C' && !IsThereAMove()) {
		thereIsATie = true;
	}

	return thereIsATie;
}

/**************************************************************************
 *
 *		 FUNCTION SwitchToken
 * _____________________________________________________________________
 *		Takes in the current token and then switches it to the other
 *		player. If an X comes in an O will go out
 * _____________________________________________________________________
 * PRE-CONDITIONS:
 *		mToken : the current player
 *
 * POST-CONDITIONS:
 *		mToken : switches to the other player
 *************************************************************************/
char TicTacToe::SwitchToken (void) {
	if(mToken == mPlayer1) {
		mToken = mPlayer2;
	} else {
		mToken = mPlayer1;
	}
	return mToken;
}

/**************************************************************************
 *
 *		 FUNCTION StartingToken
 * _____________________________________________________________________
 *		Takes in a starting to token, this is used to define who will
 *		go first but makes it easy to switch.
 * _____________________________________________________________________
 * PRE-CONDITIONS:
 *		xToken : Passed in token
 *
 * POST-CONDITIONS:
 *		mStartingToken : Starting token
 *************************************************************************/
void TicTacToe::StartingToken(char xToken) {
	mStartingToken = xToken;
}
