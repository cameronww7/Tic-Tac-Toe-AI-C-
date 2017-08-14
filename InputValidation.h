/**************************************************************************
 * AUTHOR  : Cameron W
 * PROJECT : Tic Tac Toe + AI In C++
 *************************************************************************/

#ifndef INPUTVALIDATION_H_
#define INPUTVALIDATION_H_

// Preprocessor Directives
#include <iostream>
#include <iomanip>
#include <string>
#include <stdlib.h>
#include <limits>
#include <algorithm>
using namespace std;

/**************************************************************************
 *
 *		Class :: InputValidation
 * _____________________________________________________________________
 *
 *		Objective :
 *		The goal of this class is to check any kind of user input and
 *		either make sure the input is correct and if not provide a way
 *		to get correct user input.
 * _____________________________________________________________________
 *
 *************************************************************************/

class InputValidation {
public:
	InputValidation() {};
	virtual ~InputValidation() {};

	// Input Check
	int IntInputCheck(const string & xMENU_FORMAT, 	// IN & OUT - Prompt for User
			 	 	  const int    & xIN_MIN,	    // IN & OUT - minimum option
			 	 	  const int    & xIN_MAX);	 	// IN & OUT - maximum option

	float FloatInputCheck(const string & xMENU_FORMAT, // IN & OUT - Prompt for User
	 	 	  	  	  	  const float  & xIN_MIN,	   // IN & OUT - minimum option
						  const float  & xIN_MAX);	   // IN & OUT - maximum option

	char CharInputCheck(const string & xPROMPT); // IN & OUT - Prompt for User

	string StringInputCheck(const string & xPROMPT); // IN & OUT - Prompt for User

	// Variable Check
	int IntCheck(const int & xIntToBeChecked, // IN - Int to be Checked
			 	 const int & xIN_MIN,	      // IN - minimum option
			 	 const int & xIN_MAX);	 	  // IN - maximum option

	float FloatCheck(const float & xFloatToBeChecked, // IN - Float to be Checked
	 	 	  	  	 const float & xIN_MIN,	   		  // IN - minimum option
					 const float & xIN_MAX);	   	  // IN - maximum option

	string StringCharacterCheck(const string & xStringToBeChecked); // IN  - String to be checked
};

#endif /* INPUTVALIDATION_H_ */
