/*
 *  COMP 15 Project 2
 *
 *  main.cpp
 * 
 *  PURPOSE: Take in cmd line arguments and run a SixDegrees implementation
 *
 *  Modified By: Dylan Maloy
 *           On: NOV 18 2020
 */

#include "SixDegrees.h"

#include <iostream>

using namespace std;

/**
FUNCTION: main
PURPOSE: runs a SixDegrees implementation
PARAMETERS: argc: cmd count, argv: cmd's
RETURN: int
MISC: N/A
**/
int main(int argc, char *argv[])
{
        SixDegrees run;

        switch (argc)
        {
        case 2:
                run.run(argv[1], "", "");
                break;
        case 3:
                run.run(argv[1], argv[2], "");
                break;
        case 4:
                run.run(argv[1], argv[2], argv[3]);
                break;
        default:
                cerr 
                << "Usage: ./SixDegrees dataFile [commandFile] [outputFile]" 
                << endl;
        }
        return 0;
}
