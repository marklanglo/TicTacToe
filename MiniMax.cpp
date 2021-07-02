/******************************************************************************
 * AUTHOR        : Mark Wiedeman
 * STUDENT ID    : 1081322
 * Assignment #2 : Multi-dimensional Array Tic-Tac-Toe
 * CLASS         : CS1B
 * SECTION       : MW: 7:30pm - 9:50pm
 * DUE DATE      : 03/14/19
 *****************************************************************************/

#include "header.h"

/*******************************************************************************
* MiniMaxPlay
*-------------------------------------------------------------------------------
* This function carries out the logic of the AI referred to in other functions
* as 'Mr. X'.  The AI works by first checking for empty spaces and directly adding
* moves to the board.  Once it has added this first move it then calls the
* 'MiniMaxPlay' function of which returns an int based on an artificial human play.
*
* The int is determined by whether the chain of moves will win (10), allow the
* human player to win(-10), or if it will result in nothing (0).  The
* 'MiniMaxPlay' will then call on 'MiniMaxAI' and this will continue recursively
* until the chain of moves ends in win, loss, nothing, or all the spaces being
* filled.  'MiniMaxAI' handles the artificial computer moves.
*
* It checks if it won, lost, etc.. by using the 'CheckWin' function.  This top
* layer function will save the 'row' and 'column' of the move with the highest
* number.  The row and column are saved into 'bestRow' and 'bestColumn'.  Once
* the program has finished checking every possible move, it will then output
* the best move into the 'boardAr' like so.
*
*            boardAr[bestRow][bestColumn] = aiPlayer;
*
* 'aiPlayer' is just a char variable that was assigned the token of the computer
* at the very beginning of the function.
*
* Theoretically with the AI checking all possible outcomes and picking the best
* one based on an integer value, the AI known as 'Mr. X' can NEVER LOSE A GAME.
*
* ------------------------------------------------------------------------------
* INPUT:
*	boardAr    - holds the characters for the board
*
* OUTPUT:
*	aiPlayer  - token for the ai player
*   token     - holds the active play token of either 'X' or 'O'
*
* PROCESSING:
*   bestMove    - stores the number of the best move
*   bestRow     - stores the row of the best move
*   bestColumn  - stores the column of the best move
*   tempMove    - stores the temporary move that is a candidate for the best
*   			  move if it has a higher value than the current best move
*   row         - keeps track of the row
*   column      - keeps track of the column
*   checkWinner - character to check if the ai or player would win from the
*   			  outcome
*   openSpots   - checks if there are any open spots left
*
*******************************************************************************/

int MiniMaxPlay(char boardAr[][3], char token)
{
	int bestMove;    //CALC - stores the number of the best move
	int bestRow;     //CALC - stores the row of the best move
	int bestColumn;  //CALC - stores the column of the best move
	int tempMove;    //CALC - stores the temporary move that is a candidate for
				     //		  the best move if it has a higher value than the
					 //       current best move

	int row;	     //CALC - keeps track of the row
	int column;      //CALC - keeps track of the column

	char aiPlayer;       //CALC, OUT - token for the ai player
	char humanPlayer;    //CALC      - token for the human player
	char checkWinner;    //CALC      - character to check if the ai or player
						 //            would win from the outcome

	bool openSpots;      //CALC      - checks if there are any open spots left

    //assigns player and ai to respective tokens
	humanPlayer = token;
	aiPlayer    = SwitchToken(token);

	bestMove = 1000;   //set to very high value to ensure valid move is chose
	openSpots = false;

	//CALC - checks for open spaces in the tictactoe grid
	for(row = 0; row < 3; row++)
	{
		for(column = 0; column < 3; column++)
		{
			if(boardAr[row][column] == ' ')
			{
				openSpots = true;
			}
		}
	}

	//runs CheckWin function in order to see if the result if this play occurred
	checkWinner = CheckWin(boardAr);

	//assigns high value if the ai would win
	if(checkWinner == aiPlayer)
	{
		bestMove = 10;
	}
	//assigns low value if the ai would lose
	else if(checkWinner == humanPlayer)
	{
		bestMove = -10;
	}
	//assigns a neutral value if there are no more spots left
	else if(!openSpots)
	{
		bestMove = 0;
	}
	//does another layer of checking through the grid for possible moves
	else
	{
		//for loops check through entire array for empty spaces
		for(row = 0; row < 3; row++)
		{
			for(column = 0; column < 3; column++)
			{
				if(boardAr[row][column] == ' ')
				{
					//does artificial human move
					boardAr[row][column] = humanPlayer;
					//runs MiniMaxAI function
					tempMove = MiniMaxAI(boardAr, aiPlayer);

					//checks for lowest possible value since this is the player
					//artificial move
					if(tempMove < bestMove)
					{
						bestMove   = tempMove;
						bestRow    = row;
						bestColumn = column;
					}

					//resets board position
					boardAr[row][column] = ' ';
				}
			}
		}
	}

	return bestMove;


}


