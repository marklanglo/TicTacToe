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
* GetPlayers
*-------------------------------------------------------------------------------
* This function has two primary sections.  The first section is for regular
* name entry or for two-player mode.  The second section is for one player mode,
* and it will only be used if no names have been previously entered before
* single player has been selected.
*
* ------------------------------------------------------------------------------
* INPUT:
*	playerO   - holds the name for the player with the 'X' token
*	playerX   - holds the name for the player with the 'O' token
*
* OUTPUT:
*	playToken - holds the active play token of either 'X' or 'O'
*
* PROCESSING:
*   storeName - used to store a name while playerX and playerO switch places
*
*
*******************************************************************************/

void GetPlayers(string& playerX, string& playerO)
{
	char playToken;     //CALC, OUT - holds the active play token
	string storeName;   //CALC      - used to store a name while playerX and
						//            playerO switch places

	/**************************************************************************
	 * INPUT - Two Player Name Entry
	 * ------------------------------------------------------------------------
	 * The function first checks if 'playerO' is 'Mr. X', of which is the name
	 * for the AI player.  If this is false then it will go through name entry
	 * of player one and player two.  It will ask player one after they enter
	 * their name whether they want to be 'X' or 'O'.
	 *
	 * If they choose 'X' then nothing happens and it asks the second player
	 * for a name.
	 *
	 * If they choose 'O' then the program will swap the values of playerX
	 * and playerO.  After that it asks for name entry
	 *
	 **************************************************************************/
	if(playerO != "Mr. X")
	{
		//INPUT - player one name entry
		cout << left << endl
			 << "Player One, enter your Name: ";
		getline(cin, playerX);

		//INPUT - error checking and input of desired play token
		do
		{
			cout << endl << "Do you wish to be \'X\' or \'O\'?"
				 << " (enter \'X\' or \'O\') ";
			cin.get(playToken);
			cin.ignore(1000,'\n');
			playToken = toupper(playToken);

			if(playToken != 'X' && playToken != 'O')
			{
				cout << endl << "***Please Enter an \'X\' or an \'O\'***"
					 << endl << endl;
			}

		}while(playToken != 'X' && playToken != 'O');

		//INPUT - Second player name entry if first player chose 'X'
		if(playToken == 'X')
		{
			cout << left << endl
				 << "Player Two, enter your Name: ";
			getline(cin, playerO);
			cout << endl;
		}
		//INPUT - Second player name entry if first player chose 'O'
		else
		{
			storeName = playerX;
			playerO   = playerX;

			cout << left << endl
				 << "Player Two, enter your Name: ";
			getline(cin, playerX);
			cout << endl;
		}
	}
	//INPUT - name entry for single player mode is determined by whether
	//        playerO is 'Mr. X' or not.  It outputs different messages but
	//        works similarly to two player mode name entry
	else if(playerO == "Mr. X")
	{
		//INPUT - player one name entry
		cout << left << endl
			 << "Player, enter your Name: ";
		getline(cin, playerX);

		//INPUT - error checking and input of desired play token
		do
		{
			cout << endl << "Do you wish to be \'X\' or \'O\'?"
				 << " (enter \'X\' or \'O\') ";
			cin.get(playToken);
			cin.ignore(1000,'\n');
			playToken = toupper(playToken);

			if(playToken != 'X' && playToken != 'O')
			{
				cout << endl << "***Please Enter an \'X\' or an \'O\'***"
					 << endl << endl;
			}

		}while(playToken != 'X' && playToken != 'O');

		//CALC - AI player name placement if first player chose 'O'
		if(playToken == 'O')
		{
			storeName = playerX;
			playerX   = playerO;
			playerO   = storeName;


			//OUTPUT - small message to player
			cout << left << endl
				 << "Ah, come on in " << playerX << " they chose an \'O\' this"
				 << " time. . ."
				 << endl << endl
				 << right;

			cout << "Press \'Enter\' to continue" << endl << endl;
			cin.ignore(1000, '\n');
		}
		//CALC - AI player name placement if first player chose 'X'
		else
		{
			//OUTPUT - small message to player
			cout << left << endl
				 << "Good luck, " << playerO << " they chose \'X\' this time!"
				 << endl << endl
				 << right;

			cout << "Press \'Enter\' to continue" << endl << endl;
			cin.ignore(1000, '\n');
		}
	}
	cout << right;

}


