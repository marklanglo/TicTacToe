/******************************************************************************
 * AUTHOR        : Mark Wiedeman
 * STUDENT ID    : 1081322
 * Assignment #2 : Multi-dimensional Array Tic-Tac-Toe
 * CLASS         : CS1B
 * SECTION       : MW: 7:30pm - 9:50pm
 * DUE DATE      : 03/14/19
 *****************************************************************************/

#ifndef HEADER_H_
#define HEADER_H_

#include <string>
#include <iostream>
#include <iomanip>
#include <cstdlib>

using namespace std;

/******************************************************************************
 * PrintHeader
 *   This function outputs the header for the programmer, class, class section,
 *   lab or project number, and finally the project name.
 *
 * RETURNS: nothing
 * -> Displays the header
 *****************************************************************************/
void PrintHeader();


/******************************************************************************
 * OutputInstruct
 *   This function outputs instructions to the users.  There are no input
 *   or output parameters for this function as it only displays text to
 *   the screen.
 *
 * RETURNS: nothing
 * -> Displays the instructions to the user
 *****************************************************************************/
void OutputInstruct();


/******************************************************************************
 * InitBoard
 *   This function initializes each spot in the board to a space ' '.
 *
 * RETURNS: Board initialized with all spaces
 *****************************************************************************/
void InitBoard(char boardAr[][3]);   // OUT - tic tac toe board


/*******************************************************************************
 *
 * DisplayBoard
 *   This function outputs the tic tac toe board including the tokens
 *   played in the proper format (as described below).
 *
 *           1       2       3
 *       [1][1] | [1][2] | [1][3]
 *              |        |
 * 1            |        |
 *              |        |
 *      --------------------------
 *       [2][1] | [2][2] | [2][3]
 *              |        |
 * 2            |        |
 *              |        |
 *      --------------------------
 *       [3][1] | [3][2] | [3][3]
 *              |        |
 * 3            |        |
 *              |        |
 *
 * RETURNS: nothing
 * -> outputs the current state of the board
 *****************************************************************************/
void DisplayBoard(const char boardAr[][3]); // IN - tic tac toe board


 /******************************************************************************
  * GetPlayers
  *   This function prompts the user and gets the input for the players’ names.
  *   playerX will always contain the name of the player that is using the X token.
  *   playerO will always contain the name of the player that is using the O token.
  *
  * RETURNS: the players names through the variables playerX and playerO.
  *****************************************************************************/
void GetPlayers(string& playerX,   // OUT - player X’s name
		        string& playerO);  // OUT - player O’x name


/*******************************************************************************
* GetAndCheckInp
*-------------------------------------------------------------------------------
* This function checks player names in order to see if the program is running
* single player or two player.  It then will either prompt the user to enter a
* position on the board or it will run the ai and make the ai do a move.
*
*******************************************************************************/
void GetAndCheckInp(char boardAr[][3], char token, string playerX, string playerO);


/******************************************************************************
 * SwitchToken
 *   This function switches the active player.
 *   It takes in a parameter representing the current player's token
 *   as a character value (either an X or an O) and returns the opposite.
 *   For example, if this function receives an X it returns an 0. If it
 *   receives and O it returns and X.
 *
 * RETURNS: the token opposite of the one in which it receives.
 *****************************************************************************/
char SwitchToken(char token);  // IN - current player’s token ('X' or 'O')

/******************************************************************************
 * CheckWin
 *   This function checks to see if either player has won. Once it is
 *     possible for a win condition to exist, this should run after each a
 *     player makes a play.
 *
 * RETURNS the character value of the player that won or a value that
 *   indicates a tie.
 *****************************************************************************/
char CheckWin(const char boardAr[][3]); // IN - tic tac toe board


/******************************************************************************
 * OutputWinner
 *   This function receives as input a character indicating which player won
 *   or if the game was a tie and outputs an appropriate message. This function
 *   does not return anything as it simply outputs the appropriate message to
 *   the screen.
 *
 * RETURNS: nothing
 * -> Displays the winner’s name
 *****************************************************************************/
void OutputWinner(char whoWon,     // IN  - represents the winner or a value
								   //      indicating a tied game.
				  string playerX,  // OUT - player X’s name
				  string playerO); // OUT - player O’x name

/******************************************************************************
 * TwoPlayerMode
 * This function carries out the two player mode of this tic-tac-toe program. If
 * names haven't been selected when they select the mode then it will prompt the
 * players and ask if they wish to choose names.  The function then displays the
 * board, and after round 5 it will begin to check if a win condition has been
 * met.  It also keeps track of how many times either player has won in a row.
 *
 * After the game ends it asks if the players wish to return to the menu or play
 * again.
 *
 *****************************************************************************/
int TwoPlayerMode(char boardAr[][3], char token, string &playerX, string &playerO);

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
*******************************************************************************/
int SinglePlayerMode(char boardAr[][3], char token,
					 string &playerX, string &playerO);

/*******************************************************************************
* WinStreak
*-------------------------------------------------------------------------------
* This function outputs a message whenever a streak ends or begins depending
* how long it is.  This is only ever used in two player mode.  It also changes
* the number of wins for the loser to 0 and increments the number of wins for
* the winner.
*
*******************************************************************************/
void WinStreak(int &winsWinner, int &winsLoser, string winName, string loseName);

/*******************************************************************************
* TicTacToeAI - top layer of the ai
*-------------------------------------------------------------------------------
* This function carries out the logic of the AI referred to in other functions
* as 'Mr. X'.  The AI works by first checking for empty spaces and directly adding
* moves to the board.  Once it has added this first move it then calls the
* 'MiniMaxPlay' function of which returns an int.
*
* The int is determined by whether the chain of moves will win (10), allow the
* human player to win(-10), or if it will result in nothing (0).  The
* 'MiniMaxPlay' will then call on 'MiniMaxAI' and this will continue recursively
* until the chain of moves ends in win, loss, nothing, or all the spaces being
* filled.
*
* It checks if it won, lost, etc.. by using the 'CheckWin' function.  This top
* layer function will save the 'row' and 'column' of the move with the highest
* number.  The row and column are saved into 'bestRow' and 'bestColumn'.  Once
* the program has finished checking every possible move, it will then output
* the best move into the 'boardAr' like so.
*
*            boardAr[bestRow][bestColumn] = aiPlayer;
*
* 'aiPlayer' is just a char variable that was assigned the token of the computer
* at the very beginning of the function.
*
* Theoretically with the AI checking all possible outcomes and picking the best
* one based on an integer value, the AI known as 'Mr. X' can NEVER LOSE A GAME.
*
*******************************************************************************/
void TicTacToeAI(char boardAr[][3], char token);

/*******************************************************************************
* MiniMaxPlay
*-------------------------------------------------------------------------------
* This function carries out the logic of the AI referred to in other functions
* as 'Mr. X'.  The AI works by first checking for empty spaces and directly adding
* moves to the board.  Once it has added this first move it then calls the
* 'MiniMaxPlay' function of which returns an int based on an artificial human play.
*
* The int is determined by whether the chain of moves will win (10), allow the
* human player to win(-10), or if it will result in nothing (0).  The
* 'MiniMaxPlay' will then call on 'MiniMaxAI' and this will continue recursively
* until the chain of moves ends in win, loss, nothing, or all the spaces being
* filled.  'MiniMaxAI' handles the artificial computer moves.
*
* It checks if it won, lost, etc.. by using the 'CheckWin' function.  This top
* layer function will save the 'row' and 'column' of the move with the highest
* number.  The row and column are saved into 'bestRow' and 'bestColumn'.  Once
* the program has finished checking every possible move, it will then output
* the best move into the 'boardAr' like so.
*
*            boardAr[bestRow][bestColumn] = aiPlayer;
*
* 'aiPlayer' is just a char variable that was assigned the token of the computer
* at the very beginning of the function.
*
* Theoretically with the AI checking all possible outcomes and picking the best
* one based on an integer value, the AI known as 'Mr. X' can NEVER LOSE A GAME.
*
*******************************************************************************/
int MiniMaxPlay(char boardAr[][3], char token);

/*******************************************************************************
* MiniMaxPlay
*-------------------------------------------------------------------------------
* This function carries out the logic of the AI referred to in other functions
* as 'Mr. X'.  The AI works by first checking for empty spaces and directly adding
* moves to the board.  Once it has added this first move it then calls the
* 'MiniMaxPlay' function of which returns an int based on an artificial human play.
*
* The int is determined by whether the chain of moves will win (10), allow the
* human player to win(-10), or if it will result in nothing (0).  The
* 'MiniMaxPlay' will then call on 'MiniMaxAI' and this will continue recursively
* until the chain of moves ends in win, loss, nothing, or all the spaces being
* filled.  'MiniMaxAI' handles the artificial computer moves.
*
* It checks if it won, lost, etc.. by using the 'CheckWin' function.  This top
* layer function will save the 'row' and 'column' of the move with the highest
* number.  The row and column are saved into 'bestRow' and 'bestColumn'.  Once
* the program has finished checking every possible move, it will then output
* the best move into the 'boardAr' like so.
*
*            boardAr[bestRow][bestColumn] = aiPlayer;
*
* 'aiPlayer' is just a char variable that was assigned the token of the computer
* at the very beginning of the function.
*
* Theoretically with the AI checking all possible outcomes and picking the best
* one based on an integer value, the AI known as 'Mr. X' can NEVER LOSE A GAME.
*
*******************************************************************************/
int MiniMaxAI(char boardAr[][3], char token);


#endif HEADER_H_
