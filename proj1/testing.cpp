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
  clearStack();
  drop();
  duplicate();
  swap();
  operateOn();
  compareTo();
  exec();
  execIf();
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
 * FUNCTION: clearStack
 * PURPOSE: tests clearStack method
 * PARAMETERS: N/A
 * RETURN: N/A
 * MISC: N/A
 **/

void testing::clearStack() {
  RPNCalc calc;
  calc.pushBool("#f");
  calc.pushBool("#t");
  cout << "Clearing stack of size " << calc.stack->size() << endl;
  calc.clearStack();
  cout << "Stack size: " << calc.stack->size() << endl;
  cout << endl;
}

/**
 * FUNCTION: drop
 * PURPOSE: tests drop method
 * PARAMETERS: N/A
 * RETURN: N/A
 * MISC: N/A
 **/

void testing::drop() {
  RPNCalc calc;
  calc.pushBool("#f");
  calc.pushBool("#t");
  print(*calc.stack);
  cout << "Dropping top element" << endl;
  calc.drop();
  print(*calc.stack);
  cout << endl;
}

/**
 * FUNCTION: duplicate
 * PURPOSE: tests duplicate method
 * PARAMETERS: N/A
 * RETURN: N/A
 * MISC: N/A
 **/

void testing::duplicate() {
  RPNCalc calc;
  calc.pushBool("#f");
  print(*calc.stack);
  cout << "Duplicating top element" << endl;
  calc.duplicate();
  print(*calc.stack);
  calc.clearStack();
  cout << "Testing on empty stack" << endl;
  calc.duplicate();
  cout << endl;
}

/**
 * FUNCTION: swap
 * PURPOSE: tests swap method
 * PARAMETERS: N/A
 * RETURN: N/A
 * MISC: N/A
 **/

void testing::swap() {
  RPNCalc calc;
  calc.pushBool("#f");
  calc.pushBool("#t");
  print(*calc.stack);
  cout << "Swapping top element" << endl;
  calc.swap();
  print(*calc.stack);
  calc.clearStack();
  cout << "Testing on empty stack" << endl;
  calc.swap();
  cout << endl;
}

/**
 * FUNCTION: operateOn
 * PURPOSE: tests operateOn method
 * PARAMETERS: N/A
 * RETURN: N/A
 * MISC: N/A
 **/

void testing::operateOn() {
  RPNCalc calc;
  cout << "Testing 4+2, 4-2, 4*2, 4/2, 4mod2" << endl;
  string str = "{ testOperate.cylc } file";
  istringstream test(str);
  calc.parseInput(test);
  cout << endl;
}

/**
 * FUNCTION: compareTo
 * PURPOSE: tests compareTo method
 * PARAMETERS: N/A
 * RETURN: N/A
 * MISC: N/A
 **/

void testing::compareTo() {
  RPNCalc calc;
  cout << "Testing 4<2, 4>2, 4<=3, 4>=3, 3==3, 4==3" << endl;
  string str = "{ testCompare.cylc } file";
  istringstream test(str);
  calc.parseInput(test);
  cout << endl;
}

/**
 * FUNCTION: exec
 * PURPOSE: tests exec method
 * PARAMETERS: N/A
 * RETURN: N/A
 * MISC: N/A
 **/

void testing::exec() {
  RPNCalc calc;
  cout << "Testing exec: { 4 2 + } exec quit" << endl;
  string str = "{ 4 2 + } exec print quit";
  istringstream test(str);
  calc.parseInput(test);
  cout << endl;
}

/**
 * FUNCTION: execIf
 * PURPOSE: tests execIf method
 * PARAMETERS: N/A
 * RETURN: N/A
 * MISC: N/A
 **/

void testing::execIf() {
  RPNCalc calc;
  cout << "Testing execIf: #f { 4 2 + } { 4 2 - } if print quit" << endl;
  string str = "#f { 4 2 + } { 4 2 - } if print quit";
  istringstream test(str);
  calc.parseInput(test);
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
  string str = " 1 { 4 2 / } / } swap #f";
  istringstream test(str);
  cout << "Testing parseRString on  1 { 4 2 / } / } swap #f..." << endl;
  cout << calc.parseRString(test) << endl;
  cout << endl;
}