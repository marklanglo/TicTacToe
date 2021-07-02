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
* InitBoard
*-------------------------------------------------------------------------------
* Runs through the boardAr variable and sets everything to a space, effectively
* clearing it.
*
* ------------------------------------------------------------------------------
* INPUT:
*	boardAr    - holds the characters for the board
*
* OUTPUT:
* <no additional variables for output>
*
* PROCESSING:
*   indexX	    - keeps track of row
*	indexY 		- keeps track of column
*
*******************************************************************************/

void InitBoard(char boardAr[][3])
{
	int indexX; //CALC - keeps track of row
	int indexY; //CALC - keeps track of column

	for(indexY = 0; indexY < 3; indexY++)
		for(indexX = 0; indexX < 3; indexX++)
		{
			boardAr[indexX][indexY] = ' ';
		}

}



