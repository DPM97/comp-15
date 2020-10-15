/*
 *  COMP 15 Project 1
 *
 *  parser.cpp
 * 
 *  PURPOSE: Parses rStrings from an input stream
 *
 *  Modified By: Dylan Maloy
 *           On: Oct 11 2020
 */


#include <iostream>
#include <string>

using namespace std;

/**
 * FUNCTION: parseRString
 * PURPOSE: parses the rString from an input stream and returns the rString
 * PARAMETERS: istream &in - input stream
 * RETURN: string - final rString
 * MISC: N/A
 **/

string parseRString(istream &in) {
  string rstring = "{";
  int bracketDiff = 1; // { count - } count

  string object = ""; 

  while (bracketDiff > 0) {
    in >> object;

    if (object == "{") {
      bracketDiff++;
    } else if (object == "}") {
      bracketDiff--;
    } 

    rstring = rstring + " " + object;
    object = "";
  }

  return rstring;
}