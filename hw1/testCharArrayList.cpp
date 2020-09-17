/*
 *
 *  COMP 15 HW 1 Cheshire ConCATenation - no strings attached
 *
 *  testCharArrayList.cpp
 *
 *  PURPOSE: Test the funcitonality of the CharArrayList class
 *
 *  Written by: Dylan Maloy
 *          On: Sep 16 2020
 */

#include <iostream>
#include "CharArrayList.h"

using namespace std;

int main()
{
    /* testing default constructor */
    cout << "creating new empty list" << endl;
    cout << endl;
    CharArrayList *list = new CharArrayList();

    /* testing isEmpty on empty list */
    cout << "isEmpty: " << boolalpha << list->isEmpty() << endl;
    cout << endl;

    /* testing pushAtBack */
    list->pushAtBack('a');
    cout << "pushing a to back: " << endl;
    list->print();

    /* testing isEmpty on non-empty list */
    cout << endl;
    cout << "isEmpty: " << boolalpha << list->isEmpty() << endl;
    cout << endl;

    /* testing pushAtBack */
    list->pushAtBack('b');
    cout << "pushing b to back: " << endl;
    list->print();

    cout << endl;

    /* testing pushAtBack */
    list->pushAtFront('c');
    cout << "pushing c to front: " << endl;
    list->print();
    cout << endl;

    /* test fetching last val, first val, value at index, and size of list */
    cout << "fetching last value: " << list->last() << endl;
    cout << "fetching first value: " << list->first() << endl;
    cout << "fetching element at index 1: " << list->elementAt(1) << endl;
    cout << "size of list: " << list->size() << endl;

    cout << endl;

    /* testing insertAt index */
    list->insertAt('d', 1);
    cout << "inserted d at index 1: " << endl;
    list->print();

    cout << endl;

    /* testing removeAt index */
    list->removeAt(2);
    cout << "removing char at index 2" << endl;
    list->print();

    cout << endl;

    /* testing constructor from array of existing elements */
    CharArrayList *list2 = new CharArrayList(new char[3]{'e', 'f', 'g'}, 3);
    cout << "creating new list from array {'e', 'f', 'g'}..." << endl;
    list2->print();
    cout << endl;

    /* testing concatenation of two arraylists */
    cout << "concatenating array 1 {'c', 'd', 'b'} and 2 {'e', 'f', 'g'}" << endl;
    list->concatenate(list2);
    list->print();

    cout << endl;

    /* testing constructor from array of existing elements (ordred) */
    CharArrayList *list3 = new CharArrayList(new char[5]{'a', 'a', 'b', 'c', 'g'}, 5);

    /* testing insertInOrder */
    list3->insertInOrder('b');
    cout << "Inserting b into {'a', 'a', 'b', 'c', 'g'} in order" << endl;
    list3->print();
    cout << endl;

    /* testing removal of last element */
    cout << "popping element from back: " << endl;
    list3->popFromBack();
    list3->print();
    cout << endl;

    /* testing removal of first element */
    cout << "popping element from front: " << endl;
    list3->popFromFront();
    list3->print();
    cout << endl;

    /* testing shrink function */
    list3->shrink();

    cout << endl;

    /* testing constructor from single char */
    cout << "creating new list from char" << endl;
    CharArrayList *list4 = new CharArrayList('a');
    list4->print();
}
