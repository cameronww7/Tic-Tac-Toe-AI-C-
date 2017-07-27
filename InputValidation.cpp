/**************************************************************************
 * AUTHOR  : Cameron W
 * PROJECT : Tic Tac Toe + AI In C++
 *************************************************************************/

#include "InputValidation.h"

InputValidation::InputValidation() {
	// TODO Auto-generated constructor stub

}

InputValidation::~InputValidation() {
	// TODO Auto-generated destructor stub
}


/************************************************************************
 *  int IntInputCheck
 * _______________________________________________________________________
 * This function outputs the menu and tracks if the user inputs an
 *	Invalid character or number within the range that was passed.
 * _______________________________________________________________________
 * PRE-CONDITIONS
 *		MENU_FORMAT : menu format needs to be predetermined
 *		IN_MIN 		: minimum input option needs to be predetermined
 *		IN_MAX		: maximum input option needs to be predetermined
 * POST-CONDITIONS
 * 		Returns a valid user choice (option) to the calling function
 ************************************************************************/
int InputValidation::IntInputCheck(const string xMENU_FORMAT, // IN & OUT - output string
		 	 					   const int    xIN_MIN,	  // IN & OUT - minimum option
								   const int    xIN_MAX) {	  // IN & OUT - maximum option
	bool someBool;	// PROCESSING	- determines whether the menu is output
	int option;		// IN & OUT	- user input choice

	do {
		someBool = false;

		std::cout << xMENU_FORMAT;

		/*****************************************************************
		 * This is a check for the user's input. It will first check
		 * 	if the user has put in a valid number, if invalid it will
		 *	clear the input then retyped the menu until and do the
		 *	check's until the user puts in a valid entry.
		 *****************************************************************/
		if (!(cin >> option)) {
			std::cout << "\n**** Please input a NUMBER between " << xIN_MIN
				      << " and " << xIN_MAX << " ****";
			std::cin.clear();

			someBool = true;
			std::cout << std::endl << std::endl;
		} else if (option > xIN_MAX || option < xIN_MIN) {
			std::cout << std::endl;
			std::cout << "**** The number " << option << " is an invalid "
					"entry     ****\n";
			std::cout << "**** Please input a number between "
				      << xIN_MIN << " and " << xIN_MAX << " ****\n";
			std::cout << std::endl;
			someBool = true;
		}
		std::cin.ignore(numeric_limits<streamsize>::max(), '\n');
	} while(someBool);

	return option;
}

/************************************************************************
 *  float FloatInputCheck
 * _______________________________________________________________________
 * This function outputs the menu and tracks if the user inputs an
 *	Invalid character or number within the range that was passed.
 * _______________________________________________________________________
 * PRE-CONDITIONS
 *		MENU_FORMAT : menu format needs to be predetermined
 *		IN_MIN 		: minimum input option needs to be predetermined
 *		IN_MAX		: maximum input option needs to be predetermined
 * POST-CONDITIONS
 * 		Returns a valid user choice (option) to the calling function
 ************************************************************************/
float InputValidation::FloatInputCheck(const string xMENU_FORMAT,
		 	 					       const float  xIN_MIN,
								       const float  xIN_MAX) {
	bool someBool = false;; // PROCESSING - determines whether the menu is output
	int option;	            // IN & OUT	 - user input choice

	do {
		someBool = false;

		std::cout << xMENU_FORMAT;

		/*****************************************************************
		 * This is a check for the user's input. It will first check
		 * 	if the user has put in a valid number, if invalid it will
		 *	clear the input then retyped the menu until and do the
		 *	check's until the user puts in a valid entry.
		 *****************************************************************/
		if (!(cin >> option)) {
			std::cout << "\n**** Please input a NUMBER between " << xIN_MIN
				      << " and " << xIN_MAX << " ****";
			std::cin.clear();

			someBool = true;
			std::cout << std::endl << std::endl;
		} else if (option > xIN_MAX || option < xIN_MIN) {
			std::cout << std::endl;
			std::cout << "**** The number " << option << " is an invalid "
					"entry     ****\n";
			std::cout << "**** Please input a number between "
				      << xIN_MIN << " and " << xIN_MAX << " ****\n";
			std::cout << std::endl;
			someBool = true;
		}
		std::cin.ignore(numeric_limits<streamsize>::max(), '\n');
	} while(someBool);

	return option;
}

/************************************************************************
 *  char CharInputCheck
 * _______________________________________________________________________
 * This function outputs the menu and tracks if the user inputs an
 *	Invalid character or number within the range that was passed.
 * _______________________________________________________________________
 * PRE-CONDITIONS
 *		xPROMPT : prompt for user
 * POST-CONDITIONS
 * 		Returns a valid user choice (option) to the calling function
 ************************************************************************/
char InputValidation::CharInputCheck (const string xPROMPT) {
	bool someBool = false; // PROCESSING - determines whether the menu is output
	char input;	           // IN & OUT	 - user input choice
	char inputCheck;

	std::cout << xPROMPT;
	do {
		std::cout << "Are you sure your input is correct (y or n) : ";
		std::cin.get(inputCheck);

		if (inputCheck == 'y') {
			someBool = false;
		} else if (inputCheck == 'n') {
			someBool = true;
		}
		std::cin.ignore(numeric_limits<streamsize>::max(), '\n');

	} while(someBool);

	return input;
}

string InputValidation::StringInputCheck (const string xPROMPT) {
	string tmp;

	return tmp;
}
