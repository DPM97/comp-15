/*
 *  COMP 15 Project 1
 *
 *  RPNCalc.h
 * 
 *  PURPOSE: Header file for the RPNCalc class
 *
 *  Modified By: Dylan Maloy
 *           On: Oct 14 2020
 */


#ifndef RPNCALC_H
#define RPNCALC_H

#include "Datum.h"
#include "DatumStack.h"
#include <string>
#include <iostream>

class RPNCalc{

  friend class testing;
  
  public:
    RPNCalc(); // default constructor
    ~RPNCalc(); // default destructor

    void run(); // will call the parseInput() method

  private:
    void pushBool(std::string s); // #t #f
    void invertBool(); // not (invers the boolean on the top of the stack)
    void printTop(); // print (without pop) (newline)
    void clearStack(); // clear (empty stack)
    void drop(); // drop (remove the top element of stack)
    void duplicate(); // dup (duplicates the top element on the stack)
    void swap(); // swap (swaps the top two elements on the stack)
    void quit(); // quit (quits the calculator completely)

    void operateOn(std::string s); // pop top 2 elems, operate, push back result
    void compareTo(std::string s); // pop top 2 elems, compare, push bool back

    std::string parseRString(std::istream &input); // parses rstring input
    void exec(); // takes top elem (rstring) and process's its contents
                 // handle cerr "Error: cannot execute non rstring"
    void file(); // see spec for details
    void execIf(); // see spec

    void parseInput(std::istream &in); // takes command from string
    void chooseCommand(std::string command); // takes a simple command and 
                                             // figures out what it is
    void chooseComplexCmd(std::string command); // chooses func from complex 
                                                // cmd's                            
    bool isInt(std::string s); // checks if string is int
    DatumStack *stack;
};

#endif
