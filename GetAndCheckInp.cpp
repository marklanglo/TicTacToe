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
* GetAndCheckInp
*-------------------------------------------------------------------------------
* This function checks player names in order to see if the program is running
* single player or two player.  It then will either prompt the user to enter a
* position on the board or it will run the ai and make the ai do a move.
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
*   row	  	    - keeps track of row
*	column 		- keeps track of column
*
*******************************************************************************/

void GetAndCheckInp(char boardAr[][3], char token, string playerX, string playerO)
{
	int row;     //CALC - keeps track of row
	int column;  //CALC - keeps track of column

	//INPUT - runs during two player mode
	if(playerO != "Mr. X" && playerX != "Mr. X")
	{
		if(token == 'X')
		{
			//INPUT - input from keyboard for the move for 'X'
			do
			{
				cout << playerX << "\'s turn! What\'s your play?: ";
				cin  >> row;
				cin  >> column;
				cin.ignore(1000,'\n');

				row--;
				column--;

				//PROC - checks if the space is within the tictactoe grid
				if((row > 2 || row < 0) || (column > 2 || column < 0))
				{
					cout << endl << "***Please Enter A Valid Space***"
						 << endl << endl;
				}
				//PROC - checks if the space is empty
				else if(boardAr[row][column] == 'X'
					    || boardAr[row][column] == 'O')
				{
					cout << endl << "***Please Choose An Empty Space***"
						 << endl << endl;
				}
			}while(((row > 2 || row < 0) || (column > 2 || column < 0))
					 || (boardAr[row][column] == 'X'
					 || boardAr[row][column] == 'O'));


				boardAr[row][column] = 'X';

		}
		else if(token == 'O')
		{
			//INPUT - input from keyboard for the move for 'O'
			do
			{
				cout << playerO << "\'s turn! What\'s your play?: ";
				cin  >> row;
				cin  >> column;
				cin.ignore(1000,'\n');

				row--;
				column--;

				//PROC - checks if the space is within the tictactoe grid
				if((row > 2 || row < 0) || (column > 2 || column < 0))
				{
					cout << "***Please Enter A Valid Space***" << endl;
				}
				//PROC - checks if the space is empty
				else if(boardAr[row][column] == 'X'
					    || boardAr[row][column] == 'O')
				{
					cout << "***Please Choose An Empty Space***" << endl;
				}
			}while(((row > 2 || row < 0) || (column > 2 || column < 0))
					 || (boardAr[row][column] == 'X'
					 || boardAr[row][column] == 'O'));


			boardAr[row][column] = 'O';


		}
		else
		{

			cout << "\nError: Play Token Lost\n";

		}

	}
	//INPUT - Runs during single player mode
	else if(playerO == "Mr. X" || playerX == "Mr. X")
	{
		//PROC - checks if Ai is playing 'O'
		if(playerO == "Mr. X")
		{
			if(token == 'X')
			{
				//INPUT - input from keyboard for the move for 'X'
				do
				{
					cout << playerX << "\'s turn! What\'s your play?: ";
					cin  >> row;
					cin  >> column;
					cin.ignore(1000,'\n');

					row--;
					column--;

					//PROC - checks if the space is within the tictactoe grid
					if((row > 2 || row < 0) || (column > 2 || column < 0))
					{
						cout << endl << "***Please Enter A Valid Space***"
							 << endl << endl;
					}
					//PROC - checks if the space is empty
					else if(boardAr[row][column] == 'X'
						    || boardAr[row][column] == 'O')
					{
						cout << endl << "***Please Choose An Empty Space***"
							 << endl << endl;
					}
				}while(((row > 2 || row < 0) || (column > 2 || column < 0))
						 || (boardAr[row][column] == 'X'
						 || boardAr[row][column] == 'O'));


					boardAr[row][column] = 'X';

			}
			else if(token == 'O')
			{
				//Runs AI
				TicTacToeAI(boardAr, token);
			}
		}
		//PROC - checks if Ai is playing 'X'
		else if(playerX == "Mr. X")
		{
			if(token == 'X')
			{
				//Runs AI
				TicTacToeAI(boardAr, token);
			}
			else if(token == 'O')
			{
				//INPUT - input from keyboard for the move for 'O'
				do
				{
					cout << playerO << "\'s turn! What\'s your play?: ";
					cin  >> row;
					cin  >> column;
					cin.ignore(1000,'\n');

					row--;
					column--;

					//PROC - checks if the space is within the tictactoe grid
					if((row > 2 || row < 0) || (column > 2 || column < 0))
					{
						cout << "***Please Enter A Valid Space***" << endl;
					}
					//PROC - checks if the space is empty
					else if(boardAr[row][column] == 'X'
							|| boardAr[row][column] == 'O')
					{
						cout << "***Please Choose An Empty Space***" << endl;
					}
				}while(((row > 2 || row < 0) || (column > 2 || column < 0))
						 || (boardAr[row][column] == 'X'
						 || boardAr[row][column] == 'O'));


				boardAr[row][column] = 'O';

			}
		}
		else
		{
			cout << endl << "***ERROR: AI NOT FOUND***" << endl;
		}
	}

}
