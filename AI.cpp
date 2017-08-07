/**************************************************************************
 * AUTHOR  : Cameron W
 * PROJECT : Tic Tac Toe + AI In C++
 *************************************************************************/

#include "AI.h"

namespace {

} // Anonymous Namespace


AI::AI() {
	mPlayerOne.SetPlayerNameAndToken("Jim", 'x');
	mPlayerTwo.SetPlayerNameAndToken("Sam", 'o');
	mTicTacToeGame.SetPlayerOneToken(mPlayerOne.GetPlayerToken());
	mTicTacToeGame.SetPlayerTwoToken(mPlayerTwo.GetPlayerToken());
}

AI::~AI() {

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


void AI::MakeAMove() {

	// Check For Win Or Tie

	//

}

int AI::CheckStateOfBoard(TicTacToe xTicTacToeGame) {
	int stateOfBoard = 0;

	if (xTicTacToeGame.CheckWin() == 'C') {
		stateOfBoard = 0;
	} else if (xTicTacToeGame.CheckWin() ==  mPlayerOne.GetPlayerToken()) {
		stateOfBoard = 10;
	} else if (xTicTacToeGame.CheckWin() ==  mPlayerOne.GetPlayerToken()) {
		stateOfBoard = -10;
	}

	return stateOfBoard;
}

// This is the minimax function. It considers all
// the possible ways the game can go and returns
// the value of the board
int AI::MiniMax(TicTacToe xTicTacToeGame,
			int 	  xDepth,
			bool 	  xIsMax,
			const int NUM_ROWS,
			const int NUM_COLS)
{
    int score = CheckStateOfBoard(xTicTacToeGame);

    // If Maximizer has won the game return his/her
    // evaluated score
    if (score == 10) {
        return score;
    }
    // If Minimizer has won the game return his/her
    // evaluated score
    if (score == -10) {
        return score;
    }
    // If there are no more moves and no winner then
    // it is a tie
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
                	xTicTacToeGame.GetBoard()[rows][cols] = mPlayerOne.GetPlayerToken();

                    // Call MiniMax recursively and choose
                    // the maximum value
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
                	xTicTacToeGame.GetBoard()[rows][cols] = mPlayerTwo.GetPlayerToken();

                    // Call MiniMax recursively and choose
                    // the minimum value
                    best = min(best, MiniMax(xTicTacToeGame, xDepth+1, !xIsMax,  NUM_ROWS, NUM_COLS));

                    // Undo the move
                    xTicTacToeGame.GetBoard()[rows][cols] = ' ';
                }
            }
        }
        return best;
    }
    return 0;
}

mMove AI::FindBestMove(TicTacToe xTicTacToeGame) {
    int bestVal = -1000;
    mMove bestMove;
    bestMove.row = -1;
    bestMove.col = -1;

    // Traverse all cells, evalutae minimax function for
    // all empty cells. And return the cell with optimal
    // value.
	for (int rows = 0; rows < NUM_ROWS; rows++) {
		for (int cols = 0; cols < NUM_COLS; cols++) {
            // Check if cell is empty
            if (xTicTacToeGame.GetBoard()[rows][cols] == ' ') {
                // Make the move
            	xTicTacToeGame.GetBoard()[rows][cols] = mPlayerOne.GetPlayerToken();

                // compute evaluation function for this
                // move.
                int moveVal = MiniMax(xTicTacToeGame, 0, false, NUM_ROWS, NUM_COLS);

                // Undo the move
                xTicTacToeGame.GetBoard()[rows][cols] = ' ';

                // If the value of the current move is
                // more than the best value, then update
                // best/
                if (moveVal > bestVal) {
                    bestMove.row = rows;
                    bestMove.col = cols;
                    bestVal = moveVal;
                }
            }
        }
    }

    std::cout << "The value of the best Move is : " << bestVal;

    return bestMove;
}




