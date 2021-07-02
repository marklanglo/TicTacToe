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
* TicTacToeAI - top layer of the ai
*-------------------------------------------------------------------------------
* This function carries out the logic of the AI referred to in other functions
* as 'Mr. X'.  The AI works by first checking for empty spaces and directly adding
* moves to the board.  Once it has added this first move it then calls the
* 'MiniMaxPlay' function of which returns an int.
*
* The int is determined by whether the chain of moves will win (10), allow the
* human player to win(-10), or if it will result in nothing (0).  The
* 'MiniMaxPlay' will then call on 'MiniMaxAI' and this will continue recursively
* until the chain of moves ends in win, loss, nothing, or all the spaces being
* filled.
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
*
*******************************************************************************/

void TicTacToeAI(char boardAr[][3], char token)
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

	//assigns tokens to variables for readability
	aiPlayer = token;
	humanPlayer = SwitchToken(token);

	//INITIALIZED VARIABLES
	bestMove = -1000; //set to -1000 to ensure that it picks a move on the board
	//

	//These two for loops check through 'boardAr' to see if there are any empty
	//spaces left
	for(row = 0; row < 3; row++)
	{
		for(column = 0; column < 3; column++)
		{
			if(boardAr[row][column] == ' ')
			{
				//The first empty space it finds it puts the ai character
				boardAr[row][column] = aiPlayer;

				//MiniMaxPlay generates a temporary move of the human player
				tempMove = MiniMaxPlay(boardAr, humanPlayer);

				//swaps tempMove into the position of bestMove if tempMove is
				//better
				if(tempMove > bestMove)
				{
					bestMove   = tempMove;
					bestRow    = row;
					bestColumn = column;
				}

				//removes the move and continues to test the rest if the board
				boardAr[row][column] = ' ';
			}
		}
	}

	//best possible move is assigned to the board
	boardAr[bestRow][bestColumn] = aiPlayer;

}












