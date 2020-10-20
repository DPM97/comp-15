/*
 *  COMP 15 Project 1
 *
 *  RPNCalc.cpp
 * 
 *  PURPOSE: The main implementation of the RPNCalc class
 *
 *  Modified By: Dylan Maloy
 *           On: Oct 14 2020
 */

#include "Datum.h"
#include "DatumStack.h"
#include "RPNCalc.h"
#include <string>
#include <sstream>
#include <iostream>
#include <fstream>

using namespace std;

// default constructor
RPNCalc::RPNCalc()
{
  stack = new DatumStack();
}

// default destructor
RPNCalc::~RPNCalc()
{
  delete stack;
}

/**
 * FUNCTION: run
 * PURPOSE: starts the parsing operations & quits after done
 * PARAMETERS: N/A
 * RETURN: void
 * MISC: N/A
 **/

void RPNCalc::run()
{
  parseInput(cin);
}

/**
 * FUNCTION: parseInput
 * PURPOSE: parses input from input stream
 * PARAMETERS: istrema &in - input stream
 * RETURN: void
 * MISC: N/A
 **/

void RPNCalc::parseInput(istream &in)
{
  string i;

  while (in >> i)
  {
    if (i == "{")
    {
      string rs = parseRString(in);
      stack->push(Datum(rs));
    }
    else if (i == "quit")
    {
      cerr << "Thank you for using CalcYouLater." << endl;
      return;
    }
    else
    {
      chooseCommand(i);
    }
  }
}

/**
 * FUNCTION: chooseCommand
 * PURPOSE: chooses which function to excecute given the input string
 * PARAMETERS: string command - command which is being executed
 * RETURN: void
 * MISC: N/A
 **/

void RPNCalc::chooseCommand(string command)
{
  if (isInt(command) == true)
  {
    stack->push(Datum(stoi(command)));
  }
  else if (command == "#t" or command == "#f")
  {
    pushBool(command);
  }
  else if (command == "not")
  {
    invertBool();
  }
  else if (command == "print")
  {
    printTop();
  }
  else if (command == "clear")
  {
    clearStack();
  }
  else if (command == "drop")
  {
    drop();
  }
  else if (command == "dup")
  {
    duplicate();
  }
  else if (command == "swap")
  {
    swap();
  }
  else if (command == "+" or command == "-" or command == "*" or
           command == "/" or command == "mod")
  {
    operateOn(command);
  }
  else if (command == "<" or command == ">" or command == "<=" or
           command == ">=" or command == "==")
  {
    compareTo(command);
  }
  else
  {
    chooseComplexCmd(command);
  }
}

/**
 * FUNCTION: isInt
 * PURPOSE: checks if string is an integer
 * PARAMETERS: string integer - string that might be an integer
 * RETURN: bool - true if is int
 * MISC: N/A
 **/

bool RPNCalc::isInt(string integer)
{
  if (integer[0] == '0')
    return true;
  return (atoi(integer.c_str()));
}

/**
 * FUNCTION: chooseComplexCmd
 * PURPOSE: chooses correct function for the input
 * PARAMETERS: string command - command which is being executed
 * RETURN: void
 * MISC: N/A
 **/

void RPNCalc::chooseComplexCmd(string command)
{
  if (command == "exec")
  {
    exec();
  }
  else if (command == "file")
  {
    file();
  }
  else
  {
    execIf();
  }
}

/**
 * FUNCTION: pushBool
 * PURPOSE: given the command, it will push the correct boolean to the stack
 * PARAMETERS: string command - will be #f or #t
 * RETURN: void
 * MISC: N/A
 **/

void RPNCalc::pushBool(string command)
{
  if (command == "#f")
  {
    stack->push(Datum(false));
  }
  else
  {
    stack->push(Datum(true));
  }
}

/**
 * FUNCTION: invertBool
 * PURPOSE: inverts the bool on the top of the stack
 * PARAMETERS: N/A
 * RETURN: void
 * MISC: N/A
 **/

void RPNCalc::invertBool()
{
  try
  {
    if (stack->top().getBool() == false)
    {
      stack->pop();
      stack->push(Datum(true));
    }
    else
    {
      stack->pop();
      stack->push(Datum(false));
    }
  }
  catch (exception &e)
  {
    cerr << "Error: " << e.what() << endl;
  }
}

/**
 * FUNCTION: printTop
 * PURPOSE: prints the top element on the stack
 * PARAMETERS: N/A
 * RETURN: void
 * MISC: N/A
 **/

void RPNCalc::printTop()
{
  try
  {
    cout << stack->top().toString() << endl;
  }
  catch (exception &e)
  {
    cerr << "Error: " << e.what() << endl;
  }
}

/**
 * FUNCTION: clearStack
 * PURPOSE: clears the stack of all elements
 * PARAMETERS: N/A
 * RETURN: void
 * MISC: N/A
 **/

void RPNCalc::clearStack()
{
  stack->clear();
}

/**
 * FUNCTION: drop
 * PURPOSE: drops the top element from the stack
 * PARAMETERS: N/A
 * RETURN: void
 * MISC: N/A
 **/

void RPNCalc::drop()
{
  try
  {
    stack->pop();
  }
  catch (exception &e)
  {
    cerr << "Error: " << e.what() << endl;
  }
}

void RPNCalc::duplicate()
{
  try
  {
    stack->push(stack->top());
  }
  catch (exception &e)
  {
    cerr << "Error: " << e.what() << endl;
  }
}

/**
 * FUNCTION: swap
 * PURPOSE: swaps the top two elements on the stack
 * PARAMETERS: N/A
 * RETURN: void
 * MISC: N/A
 **/

void RPNCalc::swap()
{
  try
  {
    Datum first = stack->top();
    stack->pop();
    Datum second = stack->top();
    stack->pop();

    stack->push(first);
    stack->push(second);
  }
  catch (exception &e)
  {
    cerr << "Error: " << e.what() << endl;
  }
}

/**
 * FUNCTION: operateOn
 * PURPOSE: fetches the first two elements on the stack and operates on them
 *          given the operation in the command, and pushes the result
 * PARAMETERS: string command - operation
 * RETURN: void
 * MISC: N/A
 **/

void RPNCalc::operateOn(string command)
{
  try
  {
    Datum first = stack->top();
    stack->pop();
    Datum second = stack->top();
    stack->pop();

    if (command == "+")
    {
      stack->push(Datum(first.getInt() + second.getInt()));
    }
    else if (command == "-")
    {
      stack->push(Datum(second.getInt() - first.getInt()));
    }
    else if (command == "*")
    {
      stack->push(Datum(first.getInt() * second.getInt()));
    }
    else if (command == "/")
    {
      stack->push(Datum(second.getInt() / first.getInt()));
    }
    else
    {
      stack->push(Datum(second.getInt() % first.getInt()));
    }
  }
  catch (exception &e)
  {
    cerr << "Error: " << e.what() << endl;
  }
}

/**
 * FUNCTION: compareTo
 * PURPOSE: fetches the top two elements on the stack, compares them, then
 *          pushes the final result
 * PARAMETERS: string command - comparison operator
 * RETURN: void
 * MISC: N/A
 **/

void RPNCalc::compareTo(string command)
{
  try
  {
    Datum first = stack->top();
    stack->pop();
    Datum second = stack->top();
    stack->pop();

    if (command == "<")
    {
      stack->push(Datum(second.getInt() < first.getInt()));
    }
    else if (command == ">")
    {
      stack->push(Datum(second.getInt() > first.getInt()));
    }
    else if (command == "<=")
    {
      stack->push(Datum(second.getInt() <= first.getInt()));
    }
    else if (command == ">=")
    {
      stack->push(Datum(second.getInt() >= first.getInt()));
    }
    else
    {
      stack->push(Datum(second.getInt() == first.getInt()));
    }
  }
  catch (exception &e)
  {
    cerr << "Error: " << e.what() << endl;
  }
}

/**
 * FUNCTION: parseRString
 * PURPOSE: fetches the rstring from the cin stream & returns it
 * PARAMETERS: istream &in - input stream
 * RETURN: string - final rString
 * MISC: N/A
 **/

string RPNCalc::parseRString(istream &in)
{
  string rstring = "{";
  int bracketDiff = 1; // { count - } count

  string object = "";

  while (bracketDiff > 0)
  {
    in >> object;

    if (object == "{")
    {
      bracketDiff++;
    }
    else if (object == "}")
    {
      bracketDiff--;
    }

    rstring = rstring + " " + object;
    object = "";
  }

  return rstring;
}

/**
 * FUNCTION: parseRString
 * PURPOSE: executes the top element (rstring) on the stack
 * PARAMETERS: N/A
 * RETURN: N/A
 * MISC: N/A
 **/

void RPNCalc::exec()
{
  try
  {
    Datum topElem = stack->top();
    if (topElem.isRString() == false)
    {
      cerr << "Error: cannot execute non rstring" << endl;
    }
    else
    {
      stack->pop();

      string topElemStr = topElem.toString();

      /* remove curley braces and spaces from rString */
      if (topElemStr.size() <= 3) return; // empty rString

        topElemStr.erase(0, 2);
        topElemStr.pop_back();
        topElemStr.pop_back();
        istringstream rString(topElemStr);
        parseInput(rString);
      
    }
  }
  catch (exception &e)
  {
    cerr << "Error: " << e.what() << endl;
  }
}

/**
 * FUNCTION: file
 * PURPOSE: reads file in rString on top of the stack & processesthe contents
 * PARAMETERS: N/A
 * RETURN: N/A
 * MISC: N/A
 **/

void RPNCalc::file()
{
  try
  {
    Datum topElem = stack->top();
    if (topElem.isRString() == false)
    {
      cerr << "Error: cannot execute non rstring" << endl;
      return;
    }
    else
    {
      stack->pop();
      string topElemStr = topElem.toString();

      /* remove curley braces and spaces from rString */
      if (topElemStr.size() <= 3) return; // empty rString

      topElemStr.erase(0, 2);
      topElemStr.pop_back();
      topElemStr.pop_back();

      ifstream data(topElemStr);
      if (!data.is_open())
      {
        cerr << "Unable to read " << topElemStr << endl;
        return;
      }
      else
      {
        parseInput(data);
        data.close();
      }
    }
  }
  catch (exception &e)
  {
    cerr << "Error: " << e.what() << endl;
  }
}

/**
 * FUNCTION: execIf
 * PURPOSE: reads file in rString on top of the stack & processesthe contents
 * PARAMETERS: N/A
 * RETURN: N/A
 * MISC: N/A
 **/

void RPNCalc::execIf()
{
  try
  {
    Datum falseCase = stack->top();
    if (!falseCase.isRString())
    {
      cerr << "Error: expected rstring in if branch" << endl;
      return;
    }
    stack->pop();

    Datum trueCase = stack->top();
    if (!trueCase.isRString())
    {
      cerr << "Error: expected rstring in if branch" << endl;
      return;
    }
    stack->pop();

    Datum condition = stack->top();
    if (!condition.isBool())
    {
      cerr << "Error: expected boolean in if test" << endl;
      return;
    }
    stack->pop();

    if (condition.getBool() == false)
    {
      stack->push(falseCase);
    }
    else
    {
      stack->push(trueCase);
    }
    exec();
  }
  catch (exception &e)
  {
    cerr << "Error: " << e.what() << endl;
  }
}