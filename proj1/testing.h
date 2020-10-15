/*
 *  COMP 15 Project 1
 *
 *  testing.h
 * 
 *  PURPOSE: Header file for the testing class
 *
 *  Modified By: Dylan Maloy
 *           On: Oct 14 2020
 */


#ifndef TESTING_H
#define TESTING_H

#include "Datum.h"
#include "DatumStack.h"
#include "RPNCalc.h"
#include <string>
#include <iostream>

class testing {
  
  friend class RPNCalc;

  public:
    testing(); // default constructor
    ~testing(); // default destructor

    void main(); // starts tests

  private:
    void print(DatumStack s);
    void push();
    void pop();
    void top();
    void size();
    void clear();

    void isInt();
    void pushBool();
    void invertBool();
    void parseRString();
};

#endif
