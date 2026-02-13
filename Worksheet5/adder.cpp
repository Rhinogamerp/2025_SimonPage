/** @file
* this is the cpp source file that contains the basic addition function.
*/


/**
* defines mathsEXPORTS and includes the header file in the source file
*/

//begin - adder.cpp============
#define mathsEXPORTS
#include "adder.h"

/**
* takes in the two integers a and b as parameters
* @param a = first integer passed in
* @param b = 2nd integer passed in
* returns the two integers added together
*/

MATHSLIBAPI int add(int a, int b) 
{
    return a + b;
}

//end - adder.cpp============
