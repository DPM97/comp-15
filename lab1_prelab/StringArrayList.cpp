#include <iostream>
#include "StringArrayList.h"

using namespace std;

StringArrayList::StringArrayList() {
  currSize = 0;
  capacity = 0;
  data = nullptr;
}

StringArrayList::~StringArrayList() {
  delete [] data;
}

int StringArrayList::size() {
  return this->currSize;
}

void StringArrayList::addAtBack(ElemType e) {
  if (currSize == capacity) {
    doubleCapacity();
  }
  data[currSize] = e;
  currSize++;
}

void StringArrayList::addAtFront(ElemType e) {
  if (currSize == capacity) {
    doubleCapacity();
  }

  ElemType *tempArr = new ElemType[capacity];

  tempArr[0] = e; //set first value

  for (int i = 1; i < size() + 1; i++) {
    tempArr[i] = data[i];
  }

  delete [] data;
  data = tempArr;
  currSize++;
}

void StringArrayList::addAt(ElemType e, int index) {
  if (currSize == capacity) {
    doubleCapacity();
  }

  ElemType *tempArr = new ElemType[capacity];


  for (int i = 0; i < index; i++) {
    tempArr[i] = data[i];
  }

  tempArr[index] = e;

  for (int i = index + 1; i < size(); i++) {
    tempArr[i] = data[i];
  }

  delete [] data;
  data = tempArr;
  currSize++;
}

void StringArrayList::removeAt(int index) {
  if (currSize == capacity / 2) {
    halveCapacity();
  }

  ElemType *tempArr = new ElemType[capacity];

  for (int i = 0; i < index; i++) {
    tempArr[i] = data[i];
  }

  for (int i = index + 1; i < size(); i++) {
    tempArr[i - 1] = data[i];
  }

  delete [] data;
  data = tempArr;
  currSize--;
}

void StringArrayList::removeFirstOccurance(ElemType e) {
  int index = 0;
  while (data[index] != e) {
    index++;
  }

  ElemType *tempArr = new ElemType[capacity];

  for (int i = 0; i < index; i++) {
    tempArr[i] = data[i];
  }

  for (int i = index + 1; i < size(); i++) {
    tempArr[i - 1] = data[i];
  }

  delete [] data;
  data = tempArr;
  currSize--;
}

int StringArrayList::indexOf(ElemType e) {
  int index = 0;
  while (data[index] != e) {
    index++;
  }

  if (index == size() + 1) {
    return -1;
  }

  return index;
}

ElemType StringArrayList::elementAt(int index) {
  return data[index];
}

void StringArrayList::doubleCapacity() {
  int newCapacity = (capacity * 2) + 2;
  ElemType *tempArr = new ElemType[newCapacity];

  for (int i = 0; i < size(); i++) {
    tempArr[i] = data[i];
  }

  capacity = newCapacity;

  delete [] data;
  data = tempArr;
}

void StringArrayList::halveCapacity() {
  int newCapacity = capacity / 2;
  ElemType *tempArr = new ElemType[newCapacity];

  for (int i = 0; i < size(); i++) {
    tempArr[i] = data[i];
  }

  capacity = newCapacity;

  delete [] data;
  data = tempArr;
}
