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
* PrintHeader
*-------------------------------------------------------------------------------
* Prints the Header to the console
*
* ------------------------------------------------------------------------------
* INPUT:
*	<no additional variables for input>
*
* OUTPUT:
*	<no additional variables for output>
*
* PROCESSING:
*	projectType - determines whether project is a lab, 'L', or an assignment, 'A'
*
*******************************************************************************/

void PrintHeader()
{
	/**************************************************************************
	 * CONSTANTS
	 * ------------------------------------------------------------------------
	 * USED FOR CLASS HEADING - ALL WLL BE OUTPUT
	 * ------------------------------------------------------------------------
	 * PROGRAMMER           : Programmer's Name
	 * CLASS                : Student's Course
	 * SECTION              : Class Days and Times
	 * PROJECT_NUM          : Project Number
	 * PROJECT_NAME         : Title of the Project
	 *
	 *************************************************************************/

	const string PROGRAMMER        = "Mark Wiedeman";
	const string CLASS             = "CS1B";
	const string SECTION           = "MW: 7:30pm - 9:50pm";
	const int    PROJECT_NUM       = 2;
	const string PROJECT_NAME      = "Multi-dimensional Array Tic-Tac-Toe";

	char projectType;    //CALC - project is a lab, 'L', or an assignment, 'A'

	projectType = 'A';  //altered only by programmer, not by user

	// OUTPUT - Class Heading
	if(projectType == 'L')
	{
		cout << left;
		cout << "*********************************************************\n";
		cout << "*  PROGRAMMED BY : "  << PROGRAMMER << endl;
		cout << "*  "      << setw(14) << "CLASS"    << ": " << CLASS    << endl;
		cout << "*  "      << setw(14) << "SECTION"  << ": " << SECTION  << endl;
		cout << "*  LAB #" << setw(9)  <<  PROJECT_NUM   << ": ";
		cout << PROJECT_NAME << endl;
		cout << "*********************************************************\n\n";
		cout << right;
	}//END - if(projectType == 'L')
	else if (projectType == 'A')
	{
		cout << left;
		cout << "*********************************************************\n";
		cout << "*  PROGRAMMED BY : "  << PROGRAMMER << endl;
		cout << "*  "     << setw(14) << "CLASS"    << ": " << CLASS    << endl;
		cout << "*  "     << setw(14) << "SECTION"  << ": " << SECTION  << endl;
		cout << "*  Assignment #" << setw(2) <<  PROJECT_NUM << ": ";
		cout << PROJECT_NAME << endl;
		cout << "*********************************************************\n\n";
		cout << right;
	}//END - else if (projectType == 'A')

}



