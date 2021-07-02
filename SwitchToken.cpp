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
* SwitchToken
*-------------------------------------------------------------------------------
* Switches the active token using a switch and returns the token
*
* ------------------------------------------------------------------------------
* INPUT:
* <no additional variables for input>
*
* OUTPUT:
* <no additional variables for output>
*
* PROCESSING:
* token - holds the active play token of either 'X' or 'O'
*
*******************************************************************************/

char SwitchToken(char token)
{
	switch(token)
	{
	case 'X': token = 'O';
			  break;
	case 'O': token = 'X';
			  break;
	default : token = 'O';  //defaults to 'O' in case of error
	}

	return token;
}




