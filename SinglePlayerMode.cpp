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
* SinglePlayerMode
*-------------------------------------------------------------------------------
* This function carries out the one player mode of this tic-tac-toe program. If
* names haven't been selected when they select the mode then it will prompt the
* player and ask if they wish to choose a name.  The function then displays the
* board, and after round 5 it will begin to check if a win condition has been
* met.  This does not keep track of wins like two player does.
*
* The player plays against an AI.
*
* After the game ends it asks if the player wishes to return to the menu or play
* again.
*
* ------------------------------------------------------------------------------
* INPUT:
*	boardAr    - holds the characters for the board
*	playerO    - holds the name for the player with the 'X' token
*	playerX    - holds the name for the player with the 'O' token
*	getName    - used for optional name entry
*	menuSelect - used to exit to menu or play again
*
* OUTPUT:
*	token - holds the active play token of either 'X' or 'O'
*
* PROCESSING:
*   winToken  - character to track if 'X' or 'O' has won
*   playCount - tracks the number of moves that have been played
*
*******************************************************************************/

int SinglePlayerMode(char boardAr[][3], char token,
					 string &playerX, string &playerO)
{
	char getName;    //IN,CALC - token used for optional name entry
	char menuSelect; //IN,CALC - used to exit to menu or play again
	char winToken;   //CALC    - character to track if 'X' or 'O' has won

	int playCount;   //CALC    - tracks the number of moves that have been played

	//INITIALIZED VARIABLES
	menuSelect = 'A';   //allows for user to access single player
	//

	while(menuSelect == 'A')
	{
		if(menuSelect == 'A')
		{
			playCount = 0;
			winToken  = 'T';
		}

		InitBoard(boardAr);

		//INPUT - asks player if they want to insert if they haven't
		if(playerX == "Player1")
		{
			do
			{
				cout << "Would you like to select a name? (Yes/No) ";
				cin.get(getName);
				cin.ignore(1000,'\n');

				getName = toupper(getName);

				if(getName != 'Y' && getName != 'N')
				{
					cout << endl << "***Please Enter \"Yes\" or \"No\" "
						 << "to continue***" << endl << endl;
				}

			}while(getName != 'Y' && getName != 'N');

			if(getName == 'Y')
			{
				GetPlayers(playerX, playerO);
			}
		}//END - if(playerX == "Player1")

		cout << right;
		DisplayBoard(boardAr);

		//works the same way as two player but with an AI making the second
		//players moves.  Consult TwoPlayerMode function for info
		while(winToken == 'T' && playCount < 9)
		{
			GetAndCheckInp(boardAr, token, playerX, playerO);
			system("cls");

			cout << right;
			DisplayBoard(boardAr);

			playCount++;

			token = SwitchToken(token);

			if(playCount >= 5)
			{
				winToken = CheckWin(boardAr);

				if(winToken == 'X' || winToken == 'O')
				{
					OutputWinner(winToken, playerX, playerO);
				}
			}
		}//END - while(winToken == 'T' && playCount < 9)

		//OUTPUT - in event of tie
		if(winToken == 'T')
		{
			OutputWinner(winToken, playerX, playerO);
		}

		//INPUT - asks user if they want to play again
		do
		{
			cout << endl
				 << "Do you wish to play again, "
				 << "or return to menu? (Again/Menu) ";
			cin.get(menuSelect);
			cin.ignore(1000,'\n');

			menuSelect = toupper(menuSelect);

			if(menuSelect != 'A' && menuSelect != 'M')
			{
				cout << endl << "***Please Enter \"Again\" or \"Menu\""
					 << endl << endl;
			}
		}while(menuSelect != 'A' && menuSelect != 'M');

		system("cls");

	}
	return 0;
}



