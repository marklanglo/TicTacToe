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
* WinStreak
*-------------------------------------------------------------------------------
* This function outputs a message whenever a streak ends or begins depending
* how long it is.  This is only ever used in two player mode.  It also changes
* the number of wins for the loser to 0 and increments the number of wins for
* the winner.
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
*   winsWinner     - used for player with winstreak
*   winsLoser      - used for player losing a streak
*
*******************************************************************************/

void WinStreak(int &winsWinner, int &winsLoser, string winName, string loseName)
{
	//OUTPUT - losing a streak
	if(winsLoser >= 2 && winsLoser < 3)
	{
		cout << endl << loseName << "\'s streak has ended abruptly.." << endl;
	}
	else if(winsLoser >= 3 && winsLoser <= 4)
	{
		cout << endl << loseName << "\'s hotstreak is finally finished."
			 << endl;
	}
	else if(winsLoser >= 8)
	{
		cout << endl << "Oh... I guess " << winName << " is just terrible at"
			 << " this game." << endl << "Sorry for insulting you earlier "
			 << loseName << "." << endl;
	}

	winsLoser = 0;  //resets winstreak to 0 for loser
	winsWinner++;   //increments wins for winner

	//OUTPUT - win streaks
	if(winsWinner == 2)
	{
		cout << endl << "Nice Job " << winName << " two games in a row."
			 << endl;
	}
	else if(winsWinner == 3)
	{
		cout << endl << "Three win streak " << winName << ", pretty good!"
			 << endl;
	}
	else if(winsWinner == 4)
	{
		cout << "Ok buddy, cool the jets " << loseName << " is gonna leave"
		     << " at this rate. " << endl
			 << "For my sake let "<< loseName << " win one. Isn't 4 enough?"
			 << endl;
	}
	else if(winsWinner == 8)
	{
		cout << winName << " are you really playing by yourself, tic-tac-toe really?"
			 << endl << "Why don\'t you go and play literally anything else, dare I say Anthem."
			 << endl << "Almost anything is better." << endl;
	}
	else if(winsWinner == 20)
	{
		cout << "Twenty wins, probably against yourself, or for demonstration."
			 << endl << "Well " << winName
			 << ", either way I'm done counting for you." << endl;
	}

}
