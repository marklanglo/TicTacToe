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
* OutputInstruct
*-------------------------------------------------------------------------------
* This function outputs the title tic-tac-toe as well as basic instructions for
* the user to understand how to play this version of the game
*
* ------------------------------------------------------------------------------
* <no additional variables>
*
*
*******************************************************************************/

void OutputInstruct()
{
	const int LETTER_SPACING = 11;  //used for letter spacing
	const int WORD_SPACING   = 4;   //used for word spacing

	cout << "_________________________________________________________________";

	cout << left << endl;
	cout << setw(LETTER_SPACING) << "---------" << setw(LETTER_SPACING) << "  -----  "
		 << setw(LETTER_SPACING) << "---------" << setw(WORD_SPACING)
		 << setw(LETTER_SPACING) << "---------" << setw(LETTER_SPACING) << "    -    "
		 << setw(LETTER_SPACING) << "---------" << setw(WORD_SPACING) << endl;

	cout << setw(LETTER_SPACING) << "    -    " << setw(LETTER_SPACING) << "    -    "
		 << setw(LETTER_SPACING) << "-        " << setw(WORD_SPACING)
		 << setw(LETTER_SPACING) << "    -    " << setw(LETTER_SPACING) << "   - -   "
		 << setw(LETTER_SPACING) << "-        " << setw(WORD_SPACING) << endl;

	cout << setw(LETTER_SPACING) << "    -    " << setw(LETTER_SPACING) << "    -    "
		 << setw(LETTER_SPACING) << "-        " << setw(WORD_SPACING)
		 << setw(LETTER_SPACING) << "    -    " << setw(LETTER_SPACING) << "  -   -  "
		 << setw(LETTER_SPACING) << "-        " << setw(WORD_SPACING) << endl;

	cout << setw(LETTER_SPACING) << "    -    " << setw(LETTER_SPACING) << "    -    "
		 << setw(LETTER_SPACING) << "-        " << setw(WORD_SPACING)
		 << setw(LETTER_SPACING) << "    -    " << setw(LETTER_SPACING) << " ------- "
		 << setw(LETTER_SPACING) << "-        " << setw(WORD_SPACING) << endl;

	cout << setw(LETTER_SPACING) << "    -    " << setw(LETTER_SPACING) << "    -    "
		 << setw(LETTER_SPACING) << "-        " << setw(WORD_SPACING)
		 << setw(LETTER_SPACING) << "    -    " << setw(LETTER_SPACING) << "-       -"
		 << setw(LETTER_SPACING) << "-        " << setw(WORD_SPACING) << endl;

	cout << setw(LETTER_SPACING) << "    -    " << setw(LETTER_SPACING) << "    -    "
		 << setw(LETTER_SPACING) << "-        " << setw(WORD_SPACING)
		 << setw(LETTER_SPACING) << "    -    " << setw(LETTER_SPACING) << "-       -"
		 << setw(LETTER_SPACING) << "-        " << setw(WORD_SPACING) << endl;

	cout << setw(LETTER_SPACING) << "    -    " << setw(LETTER_SPACING) << "  -----  "
		 << setw(LETTER_SPACING) << "---------" << setw(WORD_SPACING)
		 << setw(LETTER_SPACING) << "    -    " << setw(LETTER_SPACING) << "-       -"
		 << setw(LETTER_SPACING) << "---------" << setw(WORD_SPACING) << endl;
	cout << right;

	cout << endl;

	cout << left;
	cout << setw(15) << " ";
	cout << setw(LETTER_SPACING) << "---------" << setw(LETTER_SPACING) << "---------"
		 << setw(LETTER_SPACING) << "---------" << endl;

	cout << setw(15) << " ";
	cout << setw(LETTER_SPACING) << "    -    " << setw(LETTER_SPACING) << "-       -"
		 << setw(LETTER_SPACING) << "-        " << endl;

	cout << setw(15) << " ";
	cout << setw(LETTER_SPACING) << "    -    " << setw(LETTER_SPACING) << "-       -"
		 << setw(LETTER_SPACING) << "-        " << endl;

	cout << setw(15) << " ";
	cout << setw(LETTER_SPACING) << "    -    " << setw(LETTER_SPACING) << "-       -"
		 << setw(LETTER_SPACING) << "---------" << endl;

	cout << setw(15) << " ";
	cout << setw(LETTER_SPACING) << "    -    " << setw(LETTER_SPACING) << "-       -"
		 << setw(LETTER_SPACING) << "-        " << endl;

	cout << setw(15) << " ";
	cout << setw(LETTER_SPACING) << "    -    " << setw(LETTER_SPACING) << "-       -"
		 << setw(LETTER_SPACING) << "-        " << endl;

	cout << setw(15) << " ";
	cout << setw(LETTER_SPACING) << "    -    " << setw(LETTER_SPACING) << "---------"
		 << setw(LETTER_SPACING) << "---------" << endl;

	cout << "_________________________________________________________________";

	cout << endl;

	cout << left;
	cout << "Welcome to Tic-Tac-Toe!  The game is simple, 3 in a row in" << endl
	     << "any direction will result in winning the game." << endl << endl;

	cout << "In order to play you must select a gamemode, one-player" << endl
		 <<	"or two-player.  Enter the correct row & column coordinates, " << endl
		 << "row first, a space, then the column. Example: \"1 3\"" << endl
		 << "Choose your moves carefully..." << endl << endl

		 << "Single Player you face the computer." << endl << endl
		 << "Two Player Mode, \'X\' goes first, and from then on the" << endl
		 << "loser goes first, or if it ties then whoever was second" << endl
		 << "will go first."<< endl << endl << endl

		 << "Good Luck!!" << endl << endl;
}

