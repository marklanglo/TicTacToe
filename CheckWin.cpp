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
* CheckWin
*-------------------------------------------------------------------------------
* This function checks if a win condition has been met by using a for loop to
* check through all the columns and rows, then two specific coordinate sets to
* check the diagonals.  If will output a character of 'T' for no win,  'X' for
* X winning, and 'O' for O winning.
*
* ------------------------------------------------------------------------------
* INPUT:
*	boardAr    - holds the characters for the board
*	playerO    - holds the name for the player with the 'X' token
*	playerX    - holds the name for the player with the 'O' token
*
* OUTPUT:
*	token - holds the active play token of either 'X' or 'O'
*
* PROCESSING:
*   winToken    - character to track if 'X' or 'O' has won
*   incCheck	- increments either a row or a column coordinate of 'boardAr'
*
*******************************************************************************/

char CheckWin(const char boardAr[][3])
{
	char winToken; //CALC      - character that is used to keep track of whether
				   //			 3 'X' characters or 'O' characters are in a row
	int  incCheck; //CALC 	   - increments with each check

	//INITIALIZED VARIABLES
	winToken = 'T';    //sets 'winToken' to 'T'
	incCheck = 0;      //resets incCheck to 0
	//

	while(incCheck < 3 && winToken == 'T')
	{
		//PROCESSING - these if statements check the columns
		if(boardAr[0][incCheck] == 'X' && boardAr[1][incCheck] == 'X'
		   && boardAr[2][incCheck] == 'X')
		{
			winToken = 'X';
		}
		else if(boardAr[0][incCheck] == 'O' && boardAr[1][incCheck] == 'O'
				&& boardAr[2][incCheck] == 'O')
		{
			winToken = 'O';
		}
		//PROCESSING - these if statements check the rows
		else if(boardAr[incCheck][0] == 'X' && boardAr[incCheck][1] == 'X'
				&& boardAr[incCheck][2] == 'X')
		{
			winToken = 'X';
		}
		else if(boardAr[incCheck][0] == 'O' && boardAr[incCheck][1] == 'O'
				&& boardAr[incCheck][2] == 'O')
		{
			winToken = 'O';
		}

		incCheck++;
	}

	if(winToken == 'T')
	{
		//PROCESSING - these if statements check the diagonals
		if(boardAr[0][0] == 'X' && boardAr[1][1] == 'X' && boardAr[2][2] == 'X')
		{
			winToken = 'X';
		}
		else if(boardAr[0][0] == 'O' && boardAr[1][1] == 'O' && boardAr[2][2] == 'O')
		{
			winToken = 'O';
		}
		else if(boardAr[0][2] == 'X' && boardAr[1][1] == 'X' && boardAr[2][0] == 'X')
		{
			winToken = 'X';
		}
		else if(boardAr[0][2] == 'O' && boardAr[1][1] == 'O' && boardAr[2][0] == 'O')
		{
			winToken = 'O';
		}
	}
	return winToken;
}
