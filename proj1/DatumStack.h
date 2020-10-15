/*
 *  COMP 15 Project 1
 *
 *  DatumStack.h
 * 
 *  PURPOSE: Header file for the DatumStack class
 *
 *  Modified By: Dylan Maloy
 *           On: Oct 11 2020
 */


#ifndef DATUMSTACK_H
#define DATUMSTACK_H

#include "Datum.h"
#include <vector>

class DatumStack {
  public:
    DatumStack();
    DatumStack(Datum arr[], int size);
    ~DatumStack();

    bool isEmpty();
    void clear();
    int size();
    Datum top();
    void pop();
    void push(Datum element);
  private:
    int length;
    std::vector<Datum> stack;
};

#endif
