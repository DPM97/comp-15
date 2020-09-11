#include <iostream>
#include "Square.h"
#include <fstream>

using namespace std;

void changeByValue(int val);
void changeByPtr(int* valPtr);
void changeByRef(int& val);
void upSizeArray(int*& array);
void readFromFile();

int main() {
  cout << "How many participants are there?: ";
  int numParticipants = 0;
  cin >> numParticipants;

  int* numParticipantsPtr = &numParticipants;

  changeByValue(numParticipants);
  cout << numParticipants << endl;
  changeByPtr(numParticipantsPtr); // can be this or &numParticipants
  cout << numParticipants << endl;
  changeByRef(numParticipants); 
  cout << numParticipants << endl;


  /* dynamic memory allocation */

  int* dynamicArray = new int[5]; // pointer to dynamically allocated memory;

  for (int i = 0; i < 5; i++) {
    dynamicArray[i] = 3;
  }

  upSizeArray(dynamicArray);

  dynamicArray[5] = 5;

  cout << dynamicArray[5] << endl;

  delete [] dynamicArray;


  // Classes

  Square square(4);

  cout << square.area() << endl;

}
 
void changeByValue(int val) { // value does not change globally... only locally
  val = 0;
}

void changeByPtr(int* valPtr) { // value changes globally
  *valPtr = 0;
}

void changeByRef(int& val) {  // value changes globally
  val = 0;
}

void upSizeArray(int*& array) {
    int i = 0;
    while (array[i]) {
      i++;
    } // i = size of array;
    
    int* newArray = new int[i*2];

    for (int j = 0; j < i; j++) {
      newArray[j] = array[j];
    }

    array = newArray;
}

void readFromFile() {

  ifstream infile("square.cpp");

  if (!infile.is_open()) {
    cerr << "Error file not open!" << endl;
  }

  string s;

  infile >> s;

  cout << s << endl;
}