/*
 *  COMP 15 Project 2
 *
 *  SixDegrees.h
 * 
 *  PURPOSE: Header file for SixDegrees.cpp
 *
 *  Modified By: Dylan Maloy
 *           On: NOV 18 2020
 */

#ifndef __SIX_DEGREES__
#define __SIX_DEGREES__

#include "CollabGraph.h"
#include "Artist.h"
#include <string>
#include <unordered_map>
#include <fstream>

using namespace std;

class SixDegrees
{
        friend class Testing;

public:
        SixDegrees();
        ~SixDegrees();

        void run(string inputfile, string cmdfile, string outputfile);

private:
        void populateGraph(string filename);
        void connectGraph(unordered_map<string, vector<string>> map);
        void createConnection(string v1, string v2, string song);

        void parseCommand(istream &in);
        void openFileAndRead(string cmdf);
        void readFromFile(ifstream &cmdf);
        void chooseCmd(string cmd, string a1, string a2, vector<string> excl);

        void bfs(string a1, string a2);
        void dfs(string a1, string a2);
        void excl(string a1, string a2, vector<string> excl);

        void printPath(string v1, string v2);

        Artist fetchArtist(string artist);
        CollabGraph graph;
        unordered_map<string, Artist> artistMap;
};

#endif