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
* MULTI-DIMENSIONAL ARRAY TIC-TAC-TOE
*-------------------------------------------------------------------------------
* This program allows the user to play a game of tic-tac-toe in two-player, or
* against the computer.
*
* ------------------------------------------------------------------------------
* INPUT:
*	board   - holds the characters for the board
*	menuOption - used to select menu options
*
*
*	playerOne     - holds the name for player1
*	playerTwo     - holds the name for player2
*	superComputer - holds the name for the computer
*
* OUTPUT:
*	playToken - holds the active play token of either 'X' or 'O'
*
* PROCESSING:
* <no additional variables for processing>
*
*
*******************************************************************************/

int main ()
{

	char board[3][3]; //IN, OUT   - holds the characters for the board

	char menuOption;  //IN, CALC  - used to select menu options
	char playToken;   //CALC, OUT - holds the active play token

	string playerOne; //IN, CALC, OUT    - holds the name for player1
	string playerTwo; //IN, CALC, OUT    - holds the name for player2
	string superComputer; //IN, CALC, OUT - holds the name for the computer


	//INITIALIZED VARIABLES
	superComputer = "Mr. X";   //sets default names
	playerOne     = "Player1";
	playerTwo     = "Player2";

	playToken = 'X';           //sets first playToken to 'X'
	//

	/**************************************************************************
	 * INPUT & PROCESSING - Menu
	 * ------------------------------------------------------------------------
	 * The menu allows for four different options, the first is to exit the game.
	 * The second option allows for the user to set two player names.  The third
	 * option allows the user to play in two player mode, and the final one is
	 * one player mode.
	 *
	 * This menu works based off of a switch statement that will send the user
	 * to the respective function that they desire.  The exit option simply
	 * ejects the user from the switch statement, therefore ending the program.
	 *
	 **************************************************************************/

	PrintHeader();

	while(menuOption != 'A')
	{
		OutputInstruct();

		cout << left
			 << "===Main Menu===" << endl
			 << "a. Exit" << endl
			 << "b. Set Player Names" << endl
			 << "c. Play in Two Player Mode" << endl
			 << "d. Play in One Player Mode" << endl
			 << "Menu Option: "
			 << right;

		cin.get(menuOption);
		menuOption = toupper(menuOption);
		cin.ignore(1000, '\n');

		switch(menuOption)
		{
			case 'A' : break;
			case 'B' : system("cls");
					   GetPlayers(playerOne, playerTwo);
					   break;
			case 'C' : system("cls");
					   TwoPlayerMode(board, playToken, playerOne, playerTwo);
					   break;
			case 'D' : system("cls");
					   SinglePlayerMode(board, playToken,
							   	   	    playerOne, superComputer);
					   break;
			default  : break;
		}
	}

	return 0;
}
