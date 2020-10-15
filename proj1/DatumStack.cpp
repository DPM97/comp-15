/*
 *  COMP 15 Project 1
 *
 *  DatumStack.cpp
 * 
 *  PURPOSE: Create a class that implements the features of a stack for 
 *           the Datum type
 *
 *  Modified By: Dylan Maloy
 *           On: Oct 10 2020
 */

#include "DatumStack.h"
#include "Datum.h"
#include <vector>
#include <stdexcept>

using namespace std;

// default constructor
DatumStack::DatumStack() {
  length = 0;
}

// constructor taking in an array of datum, and the size of the arrayS
DatumStack::DatumStack(Datum arr[], int size) {
  length = size;
  for (int i = 0; i < size; i++) {
    push(arr[i]);
  }
}

/**
 * FUNCTION: isEmpty
 * PURPOSE: checks if the stack is empty
 * PARAMETERS: N/A
 * RETURN: void
 * MISC: N/A
 **/

bool DatumStack::isEmpty() {
  if (length == 0) return true;
  return false;
}

/**
 * FUNCTION: clear
 * PURPOSE: clears the stack (the vector)
 * PARAMETERS: N/A
 * RETURN: void
 * MISC: N/A
 **/

void DatumStack::clear() {
  stack.clear();
  length = 0;
}

/**
 * FUNCTION: size
 * PURPOSE: gets the size of the stack
 * PARAMETERS: N/A
 * RETURN: int - size of the stack
 * MISC: N/A
 **/

int DatumStack::size() {
  return length;
}

/**
 * FUNCTION: top
 * PURPOSE: fetches the top element on the stack
 * PARAMETERS: N/A
 * RETURN: Datum - top element on the stack
 * MISC: N/A
 **/

Datum DatumStack::top() {
  if (isEmpty()) throw runtime_error("empty_stack");
  return stack.back();
}

/**
 * FUNCTION: pop
 * PURPOSE: pops the top element on the stack
 * PARAMETERS: N/A
 * RETURN: N/A
 * MISC: N/A
 **/

void DatumStack::pop() {
  if (isEmpty()) throw runtime_error("empty_stack");
  stack.pop_back();
  length--;
  return;
}

/**
 * FUNCTION: push
 * PURPOSE: pushes an element onto the stack
 * PARAMETERS: Datum element - element to be pushed
 * RETURN: N/A
 * MISC: N/A
 **/

void DatumStack::push(Datum element) {
  stack.push_back(element);
  length++;
  return;
}

// default destructor
DatumStack::~DatumStack() {
  clear();
}

