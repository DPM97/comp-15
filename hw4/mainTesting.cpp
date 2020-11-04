/*
 * mainTesting.cpp
 *
 *  Created on: Oct 31, 202
 *      Author: Dylan Maloy
 *    
 * creates a testing class object and runs the tests
 */

#include "testing.h"

/**
FUNCTION: main
PURPOSE: creates a testing instance
PARAMETERS: M/A
RETURN: int (0 if successful)
MISC: N/A
**/
int main()
{
        Testing tests;
        tests.run();
        return 0;
}