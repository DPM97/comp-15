/*
 *  COMP 15 Project 1
 *
 *  testing.cpp
 * 
 *  PURPOSE: Test all classes & methods in the project
 *
 *  Modified By: Dylan Maloy
 *           On: Oct 15 2020
 */


#include <string>
#include <iostream>
#include "DatumStack.h"
#include "Datum.h"
#include "RPNCalc.h"
#include "testing.h"
#include <sstream>

using namespace std;


testing::testing() {}
testing::~testing() {}

/**
 * FUNCTION: main
 * PURPOSE: calls all test methods
 * PARAMETERS: N/A
 * RETURN: N/A
 * MISC: N/A
 **/

void testing::main()
{
  /* DatumStack */
  push();
  pop();
  top();
  size();
  clear();

  /* RPNCalc */
  isInt();
  pushBool();
  invertBool();
  parseRString();
}

/**
 * FUNCTION: push
 * PURPOSE: tests the stack's "push" method
 * PARAMETERS: N/A
 * RETURN: N/A
 * MISC: N/A
 **/

void testing::push()
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

void testing::pop()
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

void testing::top()
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

void testing::size()
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

void testing::clear()
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
 * FUNCTION: print
 * PURPOSE: prints the stack
 * PARAMETERS: DatumStack s - stack to be printed
 * RETURN: N/A
 * MISC: N/A
 **/

void testing::print(DatumStack s)
{
  cout << "Stack: ";
  while (s.isEmpty() == false)
  {
    cout << s.top().toString() << " ";
    s.pop();
  }
  cout << endl;
}

/**
 * FUNCTION: isInt
 * PURPOSE: tests isInt method
 * PARAMETERS: N/A
 * RETURN: N/A
 * MISC: N/A
 **/

void testing::isInt() {
  RPNCalc calc;
  cout << "Testing isInt on integer (2313)" << endl;
  cout << boolalpha << calc.isInt("2313") << endl;
  cout << "Testing isInt on non-integer (gfrb)" << endl;
  cout << boolalpha << calc.isInt("gfrb") << endl;
  cout << endl;
}

/**
 * FUNCTION: pushBool
 * PURPOSE: tests pushBool method
 * PARAMETERS: N/A
 * RETURN: N/A
 * MISC: N/A
 **/

void testing::pushBool() {
  RPNCalc calc;
  cout << "Testing pushBool on #f & printing top" << endl;
  calc.pushBool("#f");
  calc.printTop();
  cout << endl;
}

/**
 * FUNCTION: invertBool
 * PURPOSE: tests invertBool method
 * PARAMETERS: N/A
 * RETURN: N/A
 * MISC: N/A
 **/

void testing::invertBool() {
  RPNCalc calc;
  cout << "Testing invertBool on #f & printing top" << endl;
  calc.pushBool("#f");
  calc.invertBool();
  calc.printTop();
  calc.clearStack();
  cout << "Testing on empty stack" << endl;
  calc.invertBool();
  cout << endl;
}



/**
 * FUNCTION: parseRString
 * PURPOSE: tests the parseRString method
 * PARAMETERS: N/A
 * RETURN: N/A
 * MISC: N/A
 **/

void testing::parseRString()
{
  RPNCalc calc;
  string i;
  string str = " 1 { 4 2 / } / } swap #f";
  istringstream test(str);
  cout << "Testing parseRString on  1 { 4 2 / } / } swap #f..." << endl;
  cout << calc.parseRString(test) << endl;
  cout << endl;
}