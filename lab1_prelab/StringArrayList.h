#ifndef STRINGARRAYLIST_H
#define STRINGARRAYLIST_H

#include <string>

using namespace std;

typedef string ElemType;

class StringArrayList {
  public:
    StringArrayList();
    ~StringArrayList();

    int size();

    void addAtBack(ElemType e);
    void addAtFront(ElemType e);
    void addAt(ElemType e, int index);
    void removeAt(int index);
    void removeFirstOccurance(ElemType e);
    
    int indexOf(ElemType e);
    ElemType elementAt(int index);

  private:
    int currSize, capacity;
    ElemType *data; //pointer to the list on heap
    void doubleCapacity();
    void halveCapacity();
};

#endif