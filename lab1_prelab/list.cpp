#include <iostream>
#include <fstream>

using namespace std;

void addElement(int*& arr, int e);
void removeElement(int*& arr, int e);

int main() {
  int* arr;
  arr = new int[4];

  for (int i = 0; i < 4; i++) {
    arr[i] = i+1;
  }
  addElement(arr, 8);
  removeElement(arr, 2);
  delete [] arr;
}


void addElement(int*& arr, int e) { // in the case of the lab this will be replaced with an item
  
    cout << "before" << endl;


  int size = 0;
  while (arr[size] != 0) {
    size++;
  }
  
  int* tempArr = new int[size];
  
  cout << sizeof(*tempArr) << endl;

  for (int i = 0; i < size; i++) {
    tempArr[i] = arr[i];
  } 
  tempArr[size] = e;
  delete [] arr;
  arr = tempArr;
}

void removeElement(int*& arr, int e) {
  int size = 0;
  while (arr[size] != 0) {
    size++;
  }

  cout << size << endl;
  int* tempArr = new int[size-2];

  int j = 0;
  int i = 0;

  while(i < size) {
    if (arr[i] == e) {
      i++;
      tempArr[j] = arr[i];
    } else {
      tempArr[j] = arr[i];
    }
    i++;
    j++;
  } 
  delete [] arr;
  arr = tempArr;
}