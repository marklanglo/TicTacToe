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
* OutputWinner
*-------------------------------------------------------------------------------
* This function checks who won based on the character that is passed in, then it
* outputs a message that they won as well as large text saying their character
* won.
*
* ------------------------------------------------------------------------------
* INPUT:
*	playerO    - holds the name for the player with the 'X' token
*	playerX    - holds the name for the player with the 'O' token
*
* OUTPUT:
* <no additional variables for output>
*
* PROCESSING:
*   whoWon  - character to track if 'X' or 'O' has won
*
*******************************************************************************/

void OutputWinner(char whoWon, string playerX, string playerO)
{
	const int LETTER_SPACING = 11; //used for large letter spacing

	switch(whoWon)
	{
		//OUTPUT - tie
		case 'T': cout << "Cat Scratch, looks like you two tied :(" << endl;
				  break;
	    //OUTPUT - playerX won
		case 'X': cout << playerX << " WON! TIC-TAC-TOE, 3 IN A ROW!!"
					   << " Congratulations!" << endl << endl
					   << setw(LETTER_SPACING) << "-       -"
					   << setw(5) << " "
					   << setw(LETTER_SPACING) << "-   -   -"
					   << setw(LETTER_SPACING) << "  -----  "
					   << setw(LETTER_SPACING) << "--      -"
					   << setw(LETTER_SPACING) << "---------" << endl;

				  cout << setw(LETTER_SPACING) << " -     - "
					   << setw(5) << " "
					   << setw(LETTER_SPACING) << "-   -   -"
					   << setw(LETTER_SPACING) << "    -    "
					   << setw(LETTER_SPACING) << "- -     -"
					   << setw(LETTER_SPACING) << "-        " << endl;

				  cout << setw(LETTER_SPACING) << "  -   -  "
					   << setw(5) << " "
					   << setw(LETTER_SPACING) << "-   -   -"
					   << setw(LETTER_SPACING) << "    -    "
					   << setw(LETTER_SPACING) << "-  -    -"
					   << setw(LETTER_SPACING) << "-        " << endl;

				  cout << setw(LETTER_SPACING) << "   ---   "
					   << setw(5) << " "
					   << setw(LETTER_SPACING) << "-   -   -"
					   << setw(LETTER_SPACING) << "    -    "
					   << setw(LETTER_SPACING) << "-   -   -"
					   << setw(LETTER_SPACING) << "---------" << endl;

				  cout << setw(LETTER_SPACING) << "  -   -  "
					   << setw(5) << " "
					   << setw(LETTER_SPACING) << "-   -   -"
					   << setw(LETTER_SPACING) << "    -    "
					   << setw(LETTER_SPACING) << "-    -  -"
					   << setw(LETTER_SPACING) << "        -" << endl;

				  cout << setw(LETTER_SPACING) << " -     - "
					   << setw(5) << " "
					   << setw(LETTER_SPACING) << "-   -   -"
					   << setw(LETTER_SPACING) << "    -    "
					   << setw(LETTER_SPACING) << "-     - -"
					   << setw(LETTER_SPACING) << "        -" << endl;

				  cout << setw(LETTER_SPACING) << "-       -"
					   << setw(5) << " "
					   << setw(LETTER_SPACING) << " ------- "
					   << setw(LETTER_SPACING) << "  -----  "
					   << setw(LETTER_SPACING) << "-      --"
					   << setw(LETTER_SPACING) << "---------" << endl;
				  break;
		//OUTPUT - playerO won
		case 'O': cout << playerO << " WON! TIC-TAC-TOE, 3 IN A ROW!!"
				   	   << " Congratulations!" << endl << endl
					   << setw(LETTER_SPACING) << "---------"
					   << setw(5) << " "
					   << setw(LETTER_SPACING) << "-   -   -"
					   << setw(LETTER_SPACING) << "  -----  "
					   << setw(LETTER_SPACING) << "--      -"
					   << setw(LETTER_SPACING) << "---------" << endl;

				  cout << setw(LETTER_SPACING) << "-       -"
					   << setw(5) << " "
					   << setw(LETTER_SPACING) << "-   -   -"
					   << setw(LETTER_SPACING) << "    -    "
					   << setw(LETTER_SPACING) << "- -     -"
					   << setw(LETTER_SPACING) << "-        " << endl;

				  cout << setw(LETTER_SPACING) << "-       -"
					   << setw(5) << " "
					   << setw(LETTER_SPACING) << "-   -   -"
					   << setw(LETTER_SPACING) << "    -    "
					   << setw(LETTER_SPACING) << "-  -    -"
					   << setw(LETTER_SPACING) << "-        " << endl;

				  cout << setw(LETTER_SPACING) << "-       -"
					   << setw(5) << " "
					   << setw(LETTER_SPACING) << "-   -   -"
					   << setw(LETTER_SPACING) << "    -    "
					   << setw(LETTER_SPACING) << "-   -   -"
					   << setw(LETTER_SPACING) << "---------" << endl;

				  cout << setw(LETTER_SPACING) << "-       -"
					   << setw(5) << " "
					   << setw(LETTER_SPACING) << "-   -   -"
					   << setw(LETTER_SPACING) << "    -    "
					   << setw(LETTER_SPACING) << "-    -  -"
					   << setw(LETTER_SPACING) << "        -" << endl;

				  cout << setw(LETTER_SPACING) << "-       -"
					   << setw(5) << " "
					   << setw(LETTER_SPACING) << "-   -   -"
					   << setw(LETTER_SPACING) << "    -    "
					   << setw(LETTER_SPACING) << "-     - -"
					   << setw(LETTER_SPACING) << "        -" << endl;

				  cout << setw(LETTER_SPACING) << "---------"
					   << setw(5) << " "
					   << setw(LETTER_SPACING) << " ------- "
					   << setw(LETTER_SPACING) << "  -----  "
					   << setw(LETTER_SPACING) << "-      --"
					   << setw(LETTER_SPACING) << "---------" << endl;


	}

}



