/*
 *  COMP 15 Project 1
 *
 *  testDatumStack.cpp
 * 
 *  PURPOSE: Tests the DatumStack class & the parseRString method
 *
 *  Modified By: Dylan Maloy
 *           On: Oct 11 2020
 */


#include <string>
#include <iostream>
#include "DatumStack.h"
#include "Datum.h"
#include "parser.h"
#include <sstream>

using namespace std;

void push();
void pop();
void top();
void size();
void clear();
void testParser();
void print(DatumStack s);


/**
 * FUNCTION: main
 * PURPOSE: calls all test methods
 * PARAMETERS: N/A
 * RETURN: N/A
 * MISC: N/A
 **/

int main()
{
  push();
  pop();
  top();
  size();
  clear();
  testParser();
  return 0;
}

/**
 * FUNCTION: push
 * PURPOSE: tests the stack's "push" method
 * PARAMETERS: N/A
 * RETURN: N/A
 * MISC: N/A
 **/

void push()
{
  DatumStack stack;
  print(stack);
  cout << "Pushing true to stack..." << endl;
  stack.push(Datum(true));
  print(stack);
  cout << endl;
}

/**
 * FUNCTION: pop
 * PURPOSE: tests the stack's "pop" method
 * PARAMETERS: N/A
 * RETURN: N/A
 * MISC: N/A
 **/

void pop()
{
  DatumStack stack;
  stack.push(Datum(true));
  print(stack);
  cout << "Popping true from stack..." << endl;
  stack.pop();
  print(stack);
  cout << endl;
}

/**
 * FUNCTION: top
 * PURPOSE: tests the stack's "top" method
 * PARAMETERS: N/A
 * RETURN: N/A
 * MISC: N/A
 **/

void top()
{
  DatumStack stack;
  stack.push(Datum(true));
  print(stack);
  cout << "Getting top element on stack..." << endl;
  cout << stack.top().toString() << endl;
  cout << endl;
}

/**
 * FUNCTION: size
 * PURPOSE: tests the stack's "size" method
 * PARAMETERS: N/A
 * RETURN: N/A
 * MISC: N/A
 **/

void size()
{
  DatumStack stack;
  stack.push(Datum(true));
  print(stack);
  cout << "Getting size of stack..." << endl;
  cout << stack.size() << endl;
  cout << endl;
}

/**
 * FUNCTION: clear
 * PURPOSE: tests the stack's "clear" method
 * PARAMETERS: N/A
 * RETURN: N/A
 * MISC: N/A
 **/

void clear()
{
  DatumStack stack;
  stack.push(Datum(true));
  print(stack);
  cout << "Clearing stack..." << endl;
  stack.clear();
  print(stack);
  cout << endl;
}

/**
 * FUNCTION: testParser
 * PURPOSE: tests the parseRString method
 * PARAMETERS: N/A
 * RETURN: N/A
 * MISC: N/A
 **/

void testParser()
{
  string i;
  string str = " 1 { 4 2 / } / } swap #f";
  istringstream test(str);
  cout << "Testing parseRString on  1 { 4 2 / } / } swap #f..." << endl;
  cout << parseRString(test) << endl;
  cout << endl;
}

/**
 * FUNCTION: print
 * PURPOSE: prints the stack
 * PARAMETERS: DatumStack s - stack to be printed
 * RETURN: N/A
 * MISC: N/A
 **/

void print(DatumStack s)
{
  cout << "Stack: ";
  while (s.isEmpty() == false)
  {
    cout << s.top().toString() << " ";
    s.pop();
  }
  cout << endl;
}