/*
 *
 *  COMP 15 HW 1 Cheshire ConCATenation - no strings attached
 *
 *  CharArrayList.cpp
 *
 *  PURPOSE: Create a functional arraylist class which includes all of the required methods to manipulate said list.
 *
 *  Modified by: Dylan Maloy
 *           On: Sep 16 2020
 *
 */

#include "CharArrayList.h"
#include <iostream>
#include <stdexcept>

using namespace std;

/**
 * DEFAULT CONSTRUCTOR
 **/

CharArrayList::CharArrayList()
{
  numItems = 0;
  capacity = 0;
  arr = new char[0];
}

/**
 * CONSTRUCTOR THAT CREATES ARRAYLIST WITH ONE ITEM
 **/

CharArrayList::CharArrayList(char c)
{
  numItems = 1;
  capacity = 1;
  arr = new char[0];
  arr[0] = c;
}

/**
 * CONSTRUCTOR THAT CREATES AN ARRAY LIST FROM AN CHAR ARRAY
 **/

CharArrayList::CharArrayList(char *cArr, int length)
{
  capacity = length;
  numItems = 0;
  arr = new char[length];
  try
  {
    for (int i = 0; i < capacity; i++)
    {
      arr[i] = cArr[i];
      numItems++;
    }
  }
  catch (out_of_range e)
  {
    cerr << "Length must be larger than the amount of items in the array. " << e.what() << endl;
  }
}

/**
 * DEFAULT DESTRUCTOR
 **/

CharArrayList::~CharArrayList()
{
  delete[] arr;
}

/**
 * METHODS
 **/

/**
     * FUNCTION: isEmpty
     * 
     * PURPOSE: Check if the arraylist is empty
     *  
     * PARAMETERS: N/A
     * 
     * RETURN: boolean (true if empty else false)
     * 
     * MISC: N/A
     **/

bool CharArrayList::isEmpty()
{
  if (numItems == 0)
    return true;
  return false;
}

/**
     * FUNCTION: clear
     * 
     * PURPOSE: Clear the arraylist
     *  
     * PARAMETERS: N/A
     * 
     * RETURN: void
     * 
     * MISC: N/A
     **/

void CharArrayList::clear()
{
  delete[] arr;
  arr = new char[0];
  numItems = 0;
  capacity = 0;
}

/**
     * FUNCTION: size
     * 
     * PURPOSE: Fetch the size of the arraylist
     *  
     * PARAMETERS: N/A
     * 
     * RETURN: integer representing the amount of elements in the list
     * 
     * MISC: N/A
     **/

int CharArrayList::size()
{
  return numItems;
}

/**
     * FUNCTION: first
     * 
     * PURPOSE: Fetch the first element in the arraylist
     *  
     * PARAMETERS: N/A
     * 
     * RETURN: char representing first item in the arraylist
     * 
     * MISC: N/A
     **/

char CharArrayList::first()
{
  return arr[0];
}

/**
     * FUNCTION: last
     * 
     * PURPOSE: Fetch the last element in the arraylist
     *  
     * PARAMETERS: N/A
     * 
     * RETURN: char representing last item in the arraylist
     * 
     * MISC: N/A
     **/

char CharArrayList::last()
{
  return arr[numItems - 1];
}

/**
     * FUNCTION: elementAt
     * 
     * PURPOSE: Fetch the n'th element in the list
     *  
     * PARAMETERS: index (location of item requested)
     * 
     * RETURN: char representing n'th item in the arraylist
     * 
     * MISC: N/A
     **/

char CharArrayList::elementAt(int index)
{
  try
  {
    return arr[index];
  }
  catch (out_of_range e)
  {
    cerr << e.what() << endl;
    return '\0'; // return null char if error
  }
}

/**
     * FUNCTION: print
     * 
     * PURPOSE: Print all items in the arraylist
     *  
     * PARAMETERS: N/A
     * 
     * RETURN: void
     * 
     * MISC: N/A
     **/

void CharArrayList::print()
{

  cout << "[CharArrayList of size " << numItems << "<<";

  for (int i = 0; i < numItems; i++)
  {
    cout << arr[i];
  }

  cout << ">>]" << endl;
}

/**
     * FUNCTION: pushAtBack
     * 
     * PURPOSE: add an item to the end of the arraylist
     *  
     * PARAMETERS: char c (item to be added)
     * 
     * RETURN: void
     * 
     * MISC: N/A
     **/

void CharArrayList::pushAtBack(char c)
{
  if (numItems == capacity)
    expand();

  arr[numItems] = c;
  numItems++;
}

/**
     * FUNCTION: pushAtFront
     * 
     * PURPOSE: add an item to the front of the arraylist
     *  
     * PARAMETERS: char c (item to be added)
     * 
     * RETURN: void
     * 
     * MISC: N/A
     **/

void CharArrayList::pushAtFront(char c)
{
  if (numItems == capacity)
    expand();

  numItems++;
  char *tempArr = new char[capacity];
  tempArr[0] = c;
  for (int i = 1; i < numItems; i++)
  {
    tempArr[i] = arr[i - 1];
  }

  delete[] arr;
  arr = tempArr;
}

/**
     * FUNCTION: insertAt
     * 
     * PURPOSE: insert item into a specific position in the arraylist
     *  
     * PARAMETERS: char c (item to be added), int index (location to be added at)
     * 
     * RETURN: void
     * 
     * MISC: N/A
     **/

void CharArrayList::insertAt(char c, int index)
{
  try
  {
    if (numItems == capacity)
      expand();

    numItems++;

    char *tempArr = new char[capacity];
    tempArr[index] = c;

    for (int i = 0; i < index; i++)
    {
      tempArr[i] = arr[i];
    }

    for (int i = index + 1; i < numItems; i++)
    {
      tempArr[i] = arr[i - 1];
    }

    delete[] arr;
    arr = tempArr;
  }
  catch (out_of_range e)
  {
    cerr << e.what() << endl;
  }
}

/**
     * FUNCTION: insertInOrder
     * 
     * PURPOSE: add an item to the list (alphabetically)
     *  
     * PARAMETERS: char c (item to be added)
     * 
     * RETURN: void
     * 
     * MISC: we are assuming the list is already sorted in this instance
     **/

void CharArrayList::insertInOrder(char c)
{

  int index = 0;
  while (index < numItems && c >= arr[index + 1])
  {
    index++;
  }

  insertAt(c, index);
}

/**
     * FUNCTION: popFromFront
     * 
     * PURPOSE: remove an item from the front of the arraylist
     *  
     * PARAMETERS: N/A
     * 
     * RETURN: void
     * 
     * MISC: N/A
     **/

void CharArrayList::popFromFront()
{

  char *tempArr = new char[capacity];

  for (int i = 1; i < numItems; i++)
  {
    tempArr[i - 1] = arr[i];
  }

  numItems--;
  if (numItems < capacity / 2)
    reduce();

  delete[] arr;
  arr = tempArr;
}

/**
     * FUNCTION: popFromBack
     * 
     * PURPOSE: remove an item from the back of the arraylist
     *  
     * PARAMETERS: N/A
     * 
     * RETURN: void
     * 
     * MISC: N/A
     **/

void CharArrayList::popFromBack()
{

  char *tempArr = new char[capacity];

  for (int i = 0; i < numItems - 1; i++)
  {
    tempArr[i] = arr[i];
  }

  numItems--;
  if (numItems < capacity / 2)
    reduce();

  delete[] arr;
  arr = tempArr;
}

/**
     * FUNCTION: removeAt
     * 
     * PURPOSE: remove an item from a specific position in the arraylist
     *  
     * PARAMETERS: int index (index to be removed)
     * 
     * RETURN: void
     * 
     * MISC: N/A
     **/

void CharArrayList::removeAt(int index)
{
  try
  {
    char *tempArr = new char[capacity];

    for (int i = 0; i < index; i++)
    {
      tempArr[i] = arr[i];
    }

    for (int i = index; i < numItems - 1; i++)
    {
      tempArr[i] = arr[i + 1];
    }

    numItems--;
    if (numItems < capacity / 2)
      reduce();

    delete[] arr;
    arr = tempArr;
  }
  catch (out_of_range e)
  {
    cerr << e.what() << endl;
  }
}

/**
     * FUNCTION: replaceAt
     * 
     * PURPOSE: replace an item in the array list at the given index
     *  
     * PARAMETERS: char c (replacement), int index (location the action will occur in the list)
     * 
     * RETURN: void
     * 
     * MISC: N/A
     **/

void CharArrayList::replaceAt(char c, int index)
{
  try
  {
    arr[index] = c;
  }
  catch (out_of_range e)
  {
    cerr << e.what() << endl;
  }
}

/**
     * FUNCTION: concatenate
     * 
     * PURPOSE: add arraylist 2 onto the end of arraylist 1
     *  
     * PARAMETERS: CharArrayList *newArr (arraylist to be added)
     * 
     * RETURN: void
     * 
     * MISC: N/A
     **/

void CharArrayList::concatenate(CharArrayList *newArr)
{
  char *tempArr = new char[newArr->capacity + capacity];

  for (int i = 0; i < numItems; i++)
  {
    tempArr[i] = arr[i];
  }

  for (int i = 0; i < newArr->size(); i++)
  {
    tempArr[i + numItems] = newArr->elementAt(i);
  }

  numItems += newArr->numItems;
  capacity += newArr->capacity;

  if (numItems == capacity)
    expand();

  delete[] arr;
  arr = tempArr;
}

/**
     * FUNCTION: shrink
     * 
     * PURPOSE: remove any excess capacity
     *  
     * PARAMETERS: N/A
     * 
     * RETURN: void
     * 
     * MISC: N/A
     **/

void CharArrayList::shrink()
{
  cout << "shrinking array capacity from " << capacity << " to " << numItems << " to consolodate memory..." << endl;
  capacity = numItems;

  char *tempArr = new char[capacity];

  for (int i = 0; i < numItems; i++)
  {
    tempArr[i] = arr[i];
  }

  delete[] arr;
  arr = tempArr;
}

/**
     * FUNCTION: reduce
     * 
     * PURPOSE: halve the array capcity
     *  
     * PARAMETERS: N/A
     * 
     * RETURN: void
     * 
     * MISC: N/A
     **/

void CharArrayList::reduce()
{
  capacity = (capacity / 2);
  resize();
}

/**
     * FUNCTION: expand
     * 
     * PURPOSE: double the array capcity
     *  
     * PARAMETERS: N/A
     * 
     * RETURN: void
     * 
     * MISC: N/A
     **/

void CharArrayList::expand()
{
  capacity = (capacity * 2) + 2;
  resize();
}

/**
     * FUNCTION: resize
     * 
     * PURPOSE: resize the array with an updated capacity
     *  
     * PARAMETERS: N/A
     * 
     * RETURN: void
     * 
     * MISC: N/A
     **/

void CharArrayList::resize()
{
  char *tempArr = new char[capacity];

  for (int i = 0; i < numItems; i++)
  {
    tempArr[i] = arr[i];
  }

  delete[] arr;
  arr = tempArr;
}
