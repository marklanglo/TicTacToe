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
* TwoPlayerMode
*-------------------------------------------------------------------------------
* This function carries out the two player mode of this tic-tac-toe program. If
* names haven't been selected when they select the mode then it will prompt the
* players and ask if they wish to choose names.  The function then displays the
* board, and after round 5 it will begin to check if a win condition has been
* met.  It also keeps track of how many times either player has won in a row.
*
* After the game ends it asks if the players wish to return to the menu or play
* again.
*
* ------------------------------------------------------------------------------
* INPUT:
*	boardAr    - holds the characters for the board
*	playerO    - holds the name for the player with the 'X' token
*	playerX    - holds the name for the player with the 'O' token
*	nameEnter  - used for optional name entry
*	menuSelect - used to exit to menu or play again
*
* OUTPUT:
*	token - holds the active play token of either 'X' or 'O'
*
* PROCESSING:
*   winToken  - character to track if 'X' or 'O' has won
*   playCount - tracks the number of moves that have been played
*   winsX     - used for playerX winstreak
*   winsO     - used for playerO winstreak
*
*******************************************************************************/

int TwoPlayerMode(char boardAr[][3], char token, string &playerX, string &playerO)
{
	char nameEnter;  //IN,CALC - used for optional name entry
	char winToken;   //CALC    - character to track if 'X' or 'O' has won
	char menuSelect; //IN,CALC - used to exit to menu or play again
	int  playCount;  //CALC    - tracks the number of moves that have been played
	int  winsX;      //CALC    - used for playerX winstreak
	int  winsO;      //CALC    - used for playerO winstreak

	//INITIALIZED VARIABLES
	winsX = 0;         //sets winsX and winsO to 0
	winsO = 0;
	menuSelect = 'A';  //allows for program to enter main two player mode
	//

	while(menuSelect == 'A')
	{
		//resets playCount and winToken with every run
		if(menuSelect == 'A')
		{
			playCount = 0;   //sets playCount to 0
			winToken = 'T';  //sets winToken to a neutral character
		}

		InitBoard(boardAr);  //clears the board

		//INPUT - asks players if they want to enter names if they haven't yet
		if(playerX == "Player1" && playerO == "Player2")
		{
			do
			{
				cout << "Would you like to enter player names? (Yes/No) ";
				cin.get(nameEnter);
				cin.ignore(1000,'\n');
				nameEnter = toupper(nameEnter);

				if(nameEnter == 'Y')
				{
					GetPlayers(playerX, playerO);
				}
				else if(nameEnter != 'Y' && nameEnter != 'N')
				{
					cout << endl << "***Please Enter \"Yes\" or \"No\" "
						 << "to continue***" << endl << endl;
				}
			}while(nameEnter != 'Y' && nameEnter != 'N');

		}
		system("cls");

		DisplayBoard(boardAr); //displays tic-tac-toe board for players to see

	/**************************************************************************
	 * INPUT, CALC - Two Player Play
	 * ------------------------------------------------------------------------
	 * The program enters a while loop with two conditions, if one is broken
	 * then it exits and the game ends.  'winToken' being equal to 'X' or 'O'
	 * means that somebody has won.  If playCount equals 9 then that means the
	 * whole board has been filled and the game ends.
	 *
	 * The player choose their moves with GetAndCheckInp, then the board is
	 * updated with DisplayBoard.  'playCount' is then incremented, and the
	 * 'token' is switched so the next player will be able to go.
	 *
	 * Once the 'playCount' is incremented to 5 then CheckWin will update the
	 * variable 'winToken' to determine if a player won with their move.  If a
	 * player wins then it will go to the WinStreak function to update the
	 * winstreaks.  It will also output a big win message if somebody won, or if
	 * it tied then it will output otherwise.
	 *
	 * Finally, it asks if the player wishes to play again.
	 *
	 **************************************************************************/
		while(winToken == 'T' && playCount < 9)
		{
			GetAndCheckInp(boardAr, token, playerX, playerO); //gets user moves
			system("cls");

			DisplayBoard(boardAr);

			playCount++;

			token = SwitchToken(token);

			//CALC - checks if any player won
			if(playCount >= 5)
			{
				winToken = CheckWin(boardAr);

				if(winToken == 'X' || winToken == 'O')
				{
					OutputWinner(winToken, playerX, playerO);

					switch(winToken)
					{
						case 'X': WinStreak(winsX, winsO, playerX, playerO);
								  break;
						case 'O': WinStreak(winsO, winsX, playerO, playerX);
								  break;
						case 'T': break;
					}
				}
			}
		}

		//OUT - outputs if no player won
		if(winToken == 'T')
		{
			OutputWinner(winToken, playerX, playerO);
		}

		//IN, OUT - asks if players wish to play again
		do
		{
			cout << endl
				 << "Do you wish to play again, or return to menu? (Again/Menu) ";
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









