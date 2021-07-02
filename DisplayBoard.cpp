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
* DisplayBoard
*-------------------------------------------------------------------------------
* Outputs a series of characters to create a board.
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

void DisplayBoard(const char boardAr[][3])
{
	int indexX; //indexX - keeps track of row
	int indexY; //indexY - keeps track of column

	//OUTPUT - outputs reference numbers for horizontal board positions
	cout << setw(10) << "1" << setw(8) << "2" << setw(9) << "3" << endl;

	for(indexX = 0; indexX < 3; indexX++)
	{
		/**********************************************************************
		 * OUTPUT - board coordinate display
		 * --------------------------------------------------------------------
		 * The first 3 cout statements use the variable 'indexX' in order to
		 * display every coordinate on the tictactoe grid.  The y-coordinate is
		 * pre-written in a c-string, and the only thing that changes is 'indexX'.
		 *
		 * 'indexX' changes when the loop has gone through one cycle, therefore,
		 * every time this small section is ran the correct X coordinate is
		 * displayed.
		 **********************************************************************/
		cout << setw(7)   << "[" << indexX + 1 << "][1] | " << "[" << indexX + 1;
		cout << "][2] | " << "[" << indexX + 1 << "][3] | " << endl;
		cout << setw(14)  << "|" << setw(9) << "|" << endl;

		for(indexY = 0; indexY < 3; indexY++)
		{
			/******************************************************************
			 * OUTPUT - internal board
			 * ----------------------------------------------------------------
			 * The 'for loop' increments 'indexY' which is the 'Y' coordinate
			 * of the board.  The switch statement checks 'indexY' for one of
			 * 3 numbers: 0, 1, or 2.  Each number has its own case it will
			 * output.
			 *
			 * Case 0 will output the leftmost section of the horizontal row the
			 * board is at.
			 *
			 * Case 1 will output the center section of the horizontal row the
			 * board is at.
			 *
			 * Case 3 will output the rightmost section of the horizontal row
			 * the board is at.
			 *
			 * The default case is there in the event that an error happens in
			 * the program.
			 *
			 ******************************************************************/
			switch(indexY)
			{
				case 0:  cout << indexX + 1 << setw(9) << boardAr[indexX][indexY];
						 cout << setw(4) << "|";
						 break;

				case 1:  cout << setw(4) << boardAr[indexX][indexY];
						 cout << setw(5) << "|";
						 break;

				case 2:  cout << setw(4) << boardAr[indexX][indexY] << endl;
						 break;

				default: cout << "ERROR: BOARD GENERATION FAILED! \n\n";
			}
		}//END - (indexY = 0; indexY < 3; indexY++)

		//OUTPUT - outputs final set of horizontal border lines before next row
		cout << setw(14) << "|" << setw (10) << "|\n";

		//OUTPUT - outputs the divider line between the rows as long as it
		//		   hasn't been output more than twice.  This is checked using
		//		   the variable 'indexX'

		if (indexX != 2)
		{
			cout << setw(32) << "--------------------------\n";
		}//END - (indexX != 2)
	}//END - (indexX = 0; indexX < 3; indexX++)
	cout << endl << endl;
}



















