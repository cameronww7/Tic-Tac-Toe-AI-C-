/**************************************************************************
 * AUTHOR  : Cameron W
 * PROJECT : Tic Tac Toe + AI In C++
 *************************************************************************/

#include "InputValidation.h"

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
int InputValidation::IntInputCheck(const string & xMENU_FORMAT,
		 	 					   const int    & xIN_MIN,
								   const int    & xIN_MAX) {
	bool exitValue = false;	// Exit Value
	int option;				// IN & OUT	- user input choice

	do {
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

			exitValue = true;
			std::cout << std::endl << std::endl;
		} else if (option > xIN_MAX || option < xIN_MIN) {
			std::cout << std::endl;
			std::cout << "**** The number " << option << " is an invalid "
					"entry     ****\n";
			std::cout << "**** Please input a number between "
				      << xIN_MIN << " and " << xIN_MAX << " ****\n";
			std::cout << std::endl;
			exitValue = true;
		}
		std::cin.ignore(numeric_limits<streamsize>::max(), '\n');
	} while (exitValue);

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
float InputValidation::FloatInputCheck(const string & xMENU_FORMAT,
		 	 					       const float  & xIN_MIN,
								       const float  & xIN_MAX) {
	bool exitValue = false;; // PROCESSING - determines whether the menu is output
	int option;	             // IN & OUT	 - user input choice

	do {
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

			exitValue = true;
			std::cout << std::endl << std::endl;
		} else if (option > xIN_MAX || option < xIN_MIN) {
			std::cout << std::endl;
			std::cout << "**** The number " << option << " is an invalid "
					"entry     ****\n";
			std::cout << "**** Please input a number between "
				      << xIN_MIN << " and " << xIN_MAX << " ****\n";
			std::cout << std::endl;
			exitValue = true;
		}
		std::cin.ignore(numeric_limits<streamsize>::max(), '\n');
	} while (exitValue);

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
char InputValidation::CharInputCheck (const string & xPROMPT) {
	bool exitValue = false; // PROCESSING - determines whether the menu is output
	char userInput;	        // IN & OUT	 - user input choice
	char inputCheck; 		// IN - confirms user input

	do {
		std::cout << xPROMPT;
		std::cin.get(userInput);
		std::cin.ignore(numeric_limits<streamsize>::max(), '\n');

		std::cout << "Are you sure your input is correct (y or n) : ";
		std::cin.get(inputCheck);
		std::cin.ignore(numeric_limits<streamsize>::max(), '\n');
		std::tolower(inputCheck);

		if (inputCheck == 'y') {
			exitValue = false;
		} else if (inputCheck == 'n') {
			exitValue = true;
		}
	} while(exitValue);

	return userInput;
}

/************************************************************************
 *  char StringInputCheck
 * _______________________________________________________________________
 * This function outputs the menu and tracks if the user inputs an
 *	Invalid character or number within the range that was passed.
 * _______________________________________________________________________
 * PRE-CONDITIONS
 *		xPROMPT : prompt for user
 * POST-CONDITIONS
 * 		Returns a valid user choice (option) to the calling function
 ************************************************************************/
string InputValidation::StringInputCheck (const string & xPROMPT) {
	string userInput;	// IN & OUT	 - user input choice
	char   inputCheck;	// IN - confirms user input
	char   symbolsToRemove [] = {'!', '?', ',', '\'', '.', '@'};
	int    sizeOfSymbols      = sizeof(symbolsToRemove) / sizeof(char);
	bool   exitValue          = false;

	do {
		std::cout << xPROMPT;
		std::getline(std::cin,userInput);
		std::cin.ignore(numeric_limits<streamsize>::max(), '\n');

		for (int index = 0; index < sizeOfSymbols; index++) {
			std::replace(userInput.begin(), userInput.end(), symbolsToRemove[index], ' ');
		}

		std::cout << "Are you sure your input is correct (y or n) : ";
		std::cin.get(inputCheck);
		std::cin.ignore(numeric_limits<streamsize>::max(), '\n');
		inputCheck = std::tolower(inputCheck);

		if (inputCheck == 'y') {
			exitValue = false;
		} else if (inputCheck == 'n') {
			exitValue = true;
		}
	} while(exitValue);

	return userInput;
}

/************************************************************************
 *  string StringCharacterCheck
 * _______________________________________________________________________
 * This function will take in a string and then parse through it making
 * sure all valid characters are in the string and will replace the
 * invalid characters with blanks.
 * _______________________________________________________________________
 * PRE-CONDITIONS
 *		xPROMPT : prompt for user
 * POST-CONDITIONS
 * 		Returns a valid user choice (option) to the calling function
 ************************************************************************/
string InputValidation::StringCharacterCheck(const string & xStringToBeChecked) {
	string userInput = xStringToBeChecked;	// IN & OUT	 - user input choice
	char   symbolsToRemove [] = {'!', '?', ',', '\'', '.', '@'};
	int    sizeOfSymbols      = sizeof(symbolsToRemove) / sizeof(char);

	for (int index = 0; index < sizeOfSymbols; index++) {
		std::replace(userInput.begin(), userInput.end(), symbolsToRemove[index], ' ');
	}

	return userInput;
}

/************************************************************************
 *  int IntCheck
 * _______________________________________________________________________
 * This function will take in a int and then check that it is between the
 * given input ranges and if not return's a -1 as the value;
 * _______________________________________________________________________
 * PRE-CONDITIONS
 *		xIntToBeChecked - Value to be checked
 *	    xIN_MIN			- Min Value of possible input
 *		xIN_MAX			- Max value of possible input
 * POST-CONDITIONS
 * 		option - returns either the same value or -1.1 as an error
 ************************************************************************/
int InputValidation::IntCheck(const int & xIntToBeChecked,
		 	 	 	 	 	  const int & xIN_MIN,
							  const int & xIN_MAX) {
	int option = xIntToBeChecked;

	if (option > xIN_MAX || option < xIN_MIN) {
		std::cout << "error";
		option = -1;
	}

	return option;
}

/************************************************************************
 *  float FloatCheck
 * _______________________________________________________________________
 * This function will take in a float and then check that it is between the
 * given input ranges and if not return's a -1.1 as the value;
 * _______________________________________________________________________
 * PRE-CONDITIONS
 *		xFloatToBeChecked - Value to be checked
 *	    xIN_MIN			  - Min Value of possible input
 *		xIN_MAX			  - Max value of possible input
 * POST-CONDITIONS
 * 		option - returns either the same value or -1.1 as an error
 ************************************************************************/
float InputValidation::FloatCheck(const float & xFloatToBeChecked,
 	 	  	  	 	 	 	 	  const float & xIN_MIN,
								  const float & xIN_MAX) {
	int option = xFloatToBeChecked;

	if (option > xIN_MAX || option < xIN_MIN) {
		std::cout << "error";
		option = -1.1;
	}

	return option;
}
