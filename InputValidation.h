/**************************************************************************
 * AUTHOR  : Cameron W
 * PROJECT : Tic Tac Toe + AI In C++
 *************************************************************************/

#ifndef INPUTVALIDATION_H_
#define INPUTVALIDATION_H_

#include <iostream>
#include <iomanip>
#include <string>
#include <stdlib.h>
#include <limits>
#include <algorithm>
using namespace std;

class InputValidation {
public:
	InputValidation() {};
	virtual ~InputValidation() {};

	int IntInputCheck(const string xMENU_FORMAT, // IN & OUT - Prompt for User
			 	 	  const int    xIN_MIN,	     // IN & OUT - minimum option
			 	 	  const int    xIN_MAX);	 // IN & OUT - maximum option

	float FloatInputCheck(const string xMENU_FORMAT, // IN & OUT - Prompt for User
	 	 	  	  	  	  const float  xIN_MIN,	     // IN & OUT - minimum option
						  const float  xIN_MAX);	 // IN & OUT - maximum option

	char CharInputCheck (const string xPROMPT); // IN & OUT - Prompt for User

	string StringInputCheck(const string xPROMPT); // IN & OUT - Prompt for User
};

#endif /* INPUTVALIDATION_H_ */
