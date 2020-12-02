/*
 *  COMP 15 Project 2
 *
 *  Testing.h
 * 
 *  PURPOSE: Header file for the testing class
 * 
 *  Modified By: Dylan Maloy
 *           On: NOV 27 2020
 */

#ifndef __TESTING__
#define __TESTING__

#include "SixDegrees.h"

class Testing
{
        friend class SixDegrees;

public:
        Testing();
        void run();

private:
        void bfs();
        void dfs();
        void excl();
        void notInGraph();
        void notPossible();
        void duplicateArtist();
        SixDegrees sd;
};

#endif