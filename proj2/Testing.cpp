/*
 *  COMP 15 Project 2
 *
 *  Testing.cpp
 * 
 *  PURPOSE: The main testing class. This will include all methods to test
 *           different input scenerios and edge cases on the graph.
 * 
 *  Modified By: Dylan Maloy
 *           On: NOV 27 2020
 */


#include "Testing.h"
#include "SixDegrees.h"
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

// default constructor
Testing::Testing() {
  // create a graph from artists.txt
  sd.run("artists.txt", "testing", "");
}

/**
FUNCTION: run
PURPOSE: runs all of the functions in the Testing class
PARAMETERS: N/A
RETURN: void
MISC: N/A
**/
void Testing::run() {
        cout << endl;
        dfs();
        bfs();
        excl();
        notInGraph();
        notPossible();
        duplicateArtist();
        cout << "**Testing Protocol Completed**" << endl;
}

/**
FUNCTION: dfs
PURPOSE: tests the dfs functionality on an input file
PARAMETERS: N/A
RETURN: void
MISC: N/A
**/
void Testing::dfs() {
  cout << "Testing normal dfs implementation (Jay-Z -> Post Malone)" << endl;
  string input{"dfs\nJay-Z\nPost Malone\nquit"};
  istringstream instream(input);
  sd.parseCommand(instream);
  cout << endl;
}

/**
FUNCTION: bfs
PURPOSE: tests the bfs functionality on an input file
PARAMETERS: N/A
RETURN: void
MISC: N/A
**/
void Testing::bfs() {
  cout << "Testing normal bfs implementation (Jay-Z -> Post Malone)" << endl;
  string input{"bfs\nJay-Z\nPost Malone\nquit"};
  istringstream instream(input);
  sd.parseCommand(instream);
  cout << endl;
}

/**
FUNCTION: excl
PURPOSE: tests the excl functionality on an input file
PARAMETERS: N/A
RETURN: void
MISC: N/A
**/
void Testing::excl() {
  cout << "Testing normal not implementation (Jay-Z -> Post Malone)" << endl;
  cout << "Excluding artists: Nicki Minaj, Beyonce" << endl;
  string input{"not\nJay-Z\nPost Malone\nNicki Minaj\nBeyonce\n*\nquit"};
  istringstream instream(input);
  sd.parseCommand(instream);
  cout << endl;
}

/**
FUNCTION: notInGraph
PURPOSE: tests the edge case where one artist is not in the graph
PARAMETERS: N/A
RETURN: void
MISC: N/A
**/
void Testing::notInGraph() {
  cout << "Testing all methods with artist not in dataset." << endl;
  cout << "BFS: " << endl;
  string input{"bfs\njustin bieber\nJustin Bieber\nquit"};
  istringstream instream(input);
  sd.parseCommand(instream);
  cout << "DFS: " << endl;
  input = "dfs\nnotingraph\nJustin Bieber\nquit";
  instream = istringstream(input);
  sd.parseCommand(instream);
  cout << "NOT: " << endl;
  input = "not\njay z\nJustin Bieber\nJay-Z\n*\nquit";
  instream = istringstream(input);
  sd.parseCommand(instream);
  cout << endl;
}

/**
FUNCTION: notPossible
PURPOSE: tests the edge case where the path bwtween artists is not possible
PARAMETERS: N/A
RETURN: void
MISC: N/A
**/
void Testing::notPossible() {
  cout << "Testing case where there is no possible path" << endl;
  string input{"bfs\nJustin Bieber\nUnconnected Artist\nquit"};
  istringstream instream(input);
  sd.parseCommand(instream);
  cout << "DFS: " << endl;
  input = "dfs\nJustin Bieber\nUnconnected Artist\nquit";
  instream = istringstream(input);
  sd.parseCommand(instream);
  cout << "NOT: " << endl;
  input = "not\nJustin Bieber\nUnconnected Artist\nJay-Z\n*\nquit";
  instream = istringstream(input);
  sd.parseCommand(instream);
  cout << endl;
}
 
/**
FUNCTION: duplicateArtist
PURPOSE: tests the edge case where there are duplicate artists in the input
PARAMETERS: N/A
RETURN: void
MISC: N/A
**/
void Testing::duplicateArtist() {
  cout << "Testing duplicate artist in input." << endl;
  cout << "BFS: " << endl;
  string input{"bfs\nJustin Bieber\nJustin Bieber\nquit"};
  istringstream instream(input);
  sd.parseCommand(instream);
  cout << "DFS: " << endl;
  input = "dfs\nJustin Bieber\nJustin Bieber\nquit";
  instream = istringstream(input);
  sd.parseCommand(instream);
  cout << "NOT: " << endl;
  input = "not\nJustin Bieber\nJustin Bieber\nJay-Z\n*\nquit";
  instream = istringstream(input);
  sd.parseCommand(instream);
  cout << endl;
}






