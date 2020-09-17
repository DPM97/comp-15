/*
 *
 *  COMP 15 HW 1 Cheshire ConCATenation - no strings attached
 *
 *  CharArrayList.h
 *
 *  PURPOSE
 *
 *  Modified by: Dylan Maloy
 *           On: Sep 16 2020
 *
 */

#ifndef CHARARRAYLIST_H
#define CHARARRAYLIST_H

class CharArrayList
{
public:
  /**
     * CONSTRUCTORS, DESTRUCTORS, OPERATORS
     **/

  CharArrayList();                       // initializes empty arraylist (capacity of 0)
  CharArrayList(char c);                 // initializes arraylist with this single element (capacity 1)
  CharArrayList(char *cArr, int length); // create list of size length with items cArr
  CharArrayList(CharArrayList *list)
  { // copy constructor
    numItems = list->numItems;
    capacity = list->capacity;
    arr = new char[capacity];
    for (int i = 0; i < numItems; i++)
    {
      arr[i] = list->arr[i];
    }
  }
  CharArrayList &operator=(CharArrayList &assign)
  { // assignment operator
    if (this != &assign)
    {
      delete[] arr;

      capacity = assign.capacity;
      numItems = assign.numItems;

      for (int i = 0; i < numItems; i++)
      {
        arr[i] = assign.arr[i];
      }
    }
    return *this;
  }
  ~CharArrayList();

  /**
     * METHODS
     **/

  bool isEmpty();
  void clear();
  int size();
  char first();
  char last();
  char elementAt(int index); // should throw error if index is out of range
  void print();              // [CharArrayList of size 5 <<insert chars here>>]
  void pushAtBack(char c);
  void pushAtFront(char c);
  void insertAt(char c, int index); // should throw error if index is out of range
  void insertInOrder(char c);       // insert where element fits (alphabetical order)
  void popFromFront();
  void popFromBack();
  void removeAt(int index);          // should throw error if index is out of range
  void replaceAt(char c, int index); // should throw error if index is out of range
  void concatenate(CharArrayList *newArr);
  void shrink(); // reduces to bare minimum memory

private:
  char *arr;
  int capacity;
  int numItems;
  void reduce();
  void expand();
  void resize();
};

#endif
