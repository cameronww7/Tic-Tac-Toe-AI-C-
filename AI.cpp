/**************************************************************************
 * AUTHOR  : Cameron W
 * PROJECT : C++ Practice
 *************************************************************************/

#include "AI.h"

namespace {

} // Anonymous Namespace

AI::AI() {
	mMe.SetPlayerNameAndToken("Jim", 'x');
	mOpp.SetPlayerNameAndToken("Sam", 'o');
	mTicTacToeGame.SetPlayerOneToken(mMe.GetPlayerToken());
	mTicTacToeGame.SetPlayerTwoToken(mOpp.GetPlayerToken());
}

AI::AI(Player & xPlayerOne,
	   Player & xPlayerTwo,
	   TicTacToe & xTicTacToeGame) {
	mMe 	       = xPlayerOne;
	mOpp 	       = xPlayerTwo;
	mTicTacToeGame = xTicTacToeGame;
}

AI::~AI() {

}

/************************************************************************
 *  void MakeAMove
 * _______________________________________________________________________
 *
 * _______________________________________________________________________
 * PRE-CONDITIONS
 *
 * POST-CONDITIONS
 *
 ************************************************************************/
void AI::MakeAMove() {

	// Check For Win Or Tie

	//

}

bool AI::DidSomeoneWin() {
	bool didSomeoneWin = false;

	if(mTicTacToeGame.CheckWin() == "C" && mTicTacToeGame.CheckForTie()){
		didSomeoneWin = true;
	}

	return didSomeoneWin;
}

/************************************************************************
 *  bool IsThereAMove
 * _______________________________________________________________________
 * This function will find in the board if there is a possible move and
 * return a true or false depending if it finds one.
 * _______________________________________________________________________
 * PRE-CONDITIONS
 *		mTicTacToeGame : must be made
 * POST-CONDITIONS
 * 		isThereAMove - returns either True or False
 ************************************************************************/
bool AI::IsThereAMove(TicTacToe xTicTacToeGame) {
	bool isThereAMove = false;

	for (int rows = 0; rows < NUM_ROWS && isThereAMove != true; rows++) {
		for (int cols = 0; cols < NUM_COLS && isThereAMove != true; cols++) {
			if (xTicTacToeGame.GetBoard()[rows][cols] == ' ') {
				isThereAMove = true;
			}
		}
	}

	return isThereAMove;
}

/************************************************************************
 *  int HowManyPossibleMoves
 * _______________________________________________________________________
 * This function will count how many possible moves are left on the board.
 * _______________________________________________________________________
 * PRE-CONDITIONS
 *		mTicTacToeGame : must be made
 * POST-CONDITIONS
 * 		howManyPossibleMoves - returns either True or False
 ************************************************************************/
int AI::HowManyPossibleMoves(TicTacToe xTicTacToeGame) {
	int howManyPossibleMoves = 0;

	for (int rows = 0; rows < NUM_ROWS; rows++) {
		for (int cols = 0; cols < NUM_COLS; cols++) {
			if (xTicTacToeGame.GetBoard()[rows][cols] == ' ') {
				howManyPossibleMoves++;
			}
		}
	}

	return howManyPossibleMoves;
}

/************************************************************************
 *  int CheckStateOfBoard
 * _______________________________________________________________________
 *
 * _______________________________________________________________________
 * PRE-CONDITIONS
 *
 * POST-CONDITIONS
 *
 ************************************************************************/
int AI::CheckStateOfBoard(TicTacToe xTicTacToeGame) {
	int stateOfBoard = 0;

	if (xTicTacToeGame.CheckWin() == 'C') {
		stateOfBoard = 0;
	} else if (xTicTacToeGame.CheckWin() ==  mMe.GetPlayerToken()) {
		stateOfBoard = 10;
	} else if (xTicTacToeGame.CheckWin() ==  mOpp.GetPlayerToken()) {
		stateOfBoard = -10;
	}

	return stateOfBoard;
}

/************************************************************************
 *  int MiniMax
 * _______________________________________________________________________
 * This is the MiniMax function. It considers all the possible ways the
 * game can go and returns the value of the board
 * _______________________________________________________________________
 * PRE-CONDITIONS
 *
 * POST-CONDITIONS
 *
 ************************************************************************/
int AI::MiniMax(TicTacToe xTicTacToeGame,
			int 	  xDepth,
			bool 	  xIsMax,
			const int NUM_ROWS,
			const int NUM_COLS) {
    int score = CheckStateOfBoard(xTicTacToeGame);

    // If Maximizer has won the game return his/her evaluated score
    if (score == 10) {
        return score;
    }
    // If Minimizer has won the game return his/her evaluated score
    if (score == -10) {
        return score;
    }
    // If there are no more moves and no winner then it is a tie
    if (IsThereAMove(xTicTacToeGame)==false) {
        return 0;
    }
    // If this maximizer's move
    if (xIsMax) {
        int best = -1000;

        // Traverse all cells
    	for (int rows = 0; rows < NUM_ROWS; rows++) {
    		for (int cols = 0; cols < NUM_COLS; cols++) {
                // Check if cell is empty
                if (xTicTacToeGame.GetBoard()[rows][cols] == ' ') {
                    // Make the move
                	xTicTacToeGame.GetBoard()[rows][cols] = mMe.GetPlayerToken();

                    // Call MiniMax recursively and choose the maximum value
                    best = max( best, MiniMax(xTicTacToeGame, xDepth+1, !xIsMax, NUM_ROWS, NUM_COLS) );

                    // Undo the move
                    xTicTacToeGame.GetBoard()[rows][cols] = ' ';
                }
            }
        }
        return best;
    } else {
        int best = 1000;

        // Traverse all cells
    	for (int rows = 0; rows < NUM_ROWS; rows++) {
    		for (int cols = 0; cols < NUM_COLS; cols++) {
                // Check if cell is empty
                if (xTicTacToeGame.GetBoard()[rows][cols] == ' ') {
                    // Make the move
                	xTicTacToeGame.GetBoard()[rows][cols] = mOpp.GetPlayerToken();

                    // Call MiniMax recursively and choose the minimum value
                    best = min(best, MiniMax(xTicTacToeGame, xDepth+1, !xIsMax,  NUM_ROWS, NUM_COLS));

                    // Undo the move
                    xTicTacToeGame.GetBoard()[rows][cols] = ' ';
                }
            }
        }
        return best;
    }
}

/************************************************************************
 *  mMove FindBestMove
 * _______________________________________________________________________
 * Traverse all cells, evaluate MiniMax function for all empty cells.
 * And return the cell with optimal value.
 * _______________________________________________________________________
 * PRE-CONDITIONS
 *
 * POST-CONDITIONS
 *
 ************************************************************************/
mMove AI::FindBestMove(TicTacToe xTicTacToeGame) {
    int   bestVal = -1000;
    mMove bestMove;
    bestMove.structRow = -1;
    bestMove.structCol = -1;

	for (int rows = 0; rows < NUM_ROWS; rows++) {
		for (int cols = 0; cols < NUM_COLS; cols++) {
            // Check if cell is empty
            if (xTicTacToeGame.GetBoard()[rows][cols] == ' ') {
                // Make the move
            	xTicTacToeGame.GetBoard()[rows][cols] = mMe.GetPlayerToken();

                // compute evaluation function for this move.
                int moveVal = MiniMax(xTicTacToeGame, 0, false, NUM_ROWS, NUM_COLS);

                // Undo the move
                xTicTacToeGame.GetBoard()[rows][cols] = ' ';

                // If the value of the current move is more than the best value,
                // then update best
                if (moveVal > bestVal) {
                    bestMove.structRow = rows;
                    bestMove.structCol = cols;
                    bestVal = moveVal;
                }
            }
        }
    }

    std::cout << "The value of the best Move is : " << bestVal;

    return bestMove;
}




