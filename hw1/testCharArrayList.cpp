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

void tIsEmpty();
void tClear();
void tFirst();
void tLast();
void tElementAt();
void tPrint();
void tPushAtBack();
void tPushAtFront();
void tInsertAt();
void tInsertInOrder();
void tPopFromFront();
void tPopFromBack();
void tRemoveAt();
void tReplaceAt();
void tConcatenate();
void tShrink();
void tCopyConstructor();
void tAssignmentOperator();

using namespace std;

/**
     * FUNCTION: main
     * 
     * PURPOSE: call the testing functions
     *  
     * PARAMETERS: N/A
     * 
     * RETURN: int
     * 
     * MISC: N/A
     **/

int main()
{
    cout << endl; // create a space before tests.
    tIsEmpty();
    tClear();
    tFirst();
    tLast();
    tElementAt();
    tPrint();
    tPushAtBack();
    tPushAtFront();
    tInsertAt();
    tInsertInOrder();
    tPopFromFront();
    tPopFromBack();
    tRemoveAt();
    tReplaceAt();
    tConcatenate();
    tShrink();
    tCopyConstructor();
    tAssignmentOperator();
}

/**
     * FUNCTION: tIsEmpty
     * 
     * PURPOSE: tests the isEmpty method
     *  
     * PARAMETERS: N/A
     * 
     * RETURN: void
     * 
     * MISC: N/A
     **/

void tIsEmpty()
{
    CharArrayList *list = new CharArrayList();
    cout << "Creating empty list" << endl;
    cout << "isEmpty: " << boolalpha << list->isEmpty() << endl;
    ;
    cout << "Pushing element to back" << endl;
    list->pushAtBack('c');
    cout << "isEmpty: " << boolalpha << list->isEmpty() << endl;
    cout << endl;
    delete list;
}

/**
     * FUNCTION: tClear
     * 
     * PURPOSE: tests the clear method
     *  
     * PARAMETERS: N/A
     * 
     * RETURN: void
     * 
     * MISC: N/A
     **/

void tClear()
{
    CharArrayList *list = new CharArrayList(new char[5]{'a', 'a', 'b', 'c', 'g'}, 5);
    list->print();
    cout << "Clearing list.." << endl;
    list->clear();
    list->print();
    cout << endl;
    delete list;
}

/**
     * FUNCTION: tFirst
     * 
     * PURPOSE: tests the first method
     *  
     * PARAMETERS: N/A
     * 
     * RETURN: void
     * 
     * MISC: N/A
     **/

void tFirst()
{
    CharArrayList *list = new CharArrayList(new char[5]{'a', 'a', 'b', 'c', 'g'}, 5);
    list->print();
    cout << "First element: " << list->first() << endl;
    cout << "Clearing list.." << endl;
    list->clear();
    try
    {
        cout << list->first() << endl;
    }
    catch (runtime_error e)
    {
        cout << e.what() << endl;
    }
    cout << endl;
    delete list;
}

/**
     * FUNCTION: tLast
     * 
     * PURPOSE: tests the last method
     *  
     * PARAMETERS: N/A
     * 
     * RETURN: void
     * 
     * MISC: N/A
     **/

void tLast()
{
    CharArrayList *list = new CharArrayList(new char[5]{'a', 'a', 'b', 'c', 'g'}, 5);
    list->print();
    cout << "Last element: " << list->last() << endl;
    cout << "Clearing list.." << endl;
    list->clear();
    try
    {
        cout << list->last() << endl;
    }
    catch (runtime_error e)
    {
        cout << e.what() << endl;
    }
    cout << endl;
    delete list;
}

/**
     * FUNCTION: tElementAt
     * 
     * PURPOSE: tests the elementAt method
     *  
     * PARAMETERS: N/A
     * 
     * RETURN: void
     * 
     * MISC: N/A
     **/

void tElementAt()
{
    CharArrayList *list = new CharArrayList(new char[5]{'a', 'a', 'b', 'c', 'g'}, 5);
    list->print();
    cout << "Element at index 2: " << list->elementAt(2) << endl;
    cout << "Testing out of bounds.." << endl;
    try
    {
        cout << list->elementAt(40) << endl;
    }
    catch (range_error e)
    {
        cout << e.what() << endl;
    }
    cout << endl;
    delete list;
}

/**
     * FUNCTION: tPrint
     * 
     * PURPOSE: tests the print method
     *  
     * PARAMETERS: N/A
     * 
     * RETURN: void
     * 
     * MISC: N/A
     **/

void tPrint()
{
    CharArrayList *list = new CharArrayList(new char[5]{'a', 'a', 'b', 'c', 'g'}, 5);
    cout << "testing print: " << endl;
    list->print();
    cout << endl;
    delete list;
}

/**
     * FUNCTION: tPushAtBack
     * 
     * PURPOSE: tests the pushAtBack method
     *  
     * PARAMETERS: N/A
     * 
     * RETURN: void
     * 
     * MISC: N/A
     **/

void tPushAtBack()
{
    CharArrayList *list = new CharArrayList('a');
    list->print();
    cout << "testing push to back..." << endl;
    list->pushAtBack('v');
    list->print();
    cout << endl;
    delete list;
}

/**
     * FUNCTION: tPushAtFront
     * 
     * PURPOSE: tests the PushAtFront method
     *  
     * PARAMETERS: N/A
     * 
     * RETURN: void
     * 
     * MISC: N/A
     **/

void tPushAtFront()
{
    CharArrayList *list = new CharArrayList('a');
    list->print();
    cout << "testing push to front..." << endl;
    list->pushAtFront('v');
    list->print();
    cout << endl;
    delete list;
}

/**
     * FUNCTION: tInsertAt
     * 
     * PURPOSE: tests the insertAt method
     *  
     * PARAMETERS: N/A
     * 
     * RETURN: void
     * 
     * MISC: N/A
     **/

void tInsertAt()
{
    CharArrayList *list = new CharArrayList(new char[5]{'a', 'a', 'b', 'c', 'g'}, 5);
    list->print();
    cout << "Testing insert r at index 2: " << endl;
    list->insertAt('r', 2);
    list->print();
    cout << "Testing out of bounds.." << endl;
    try
    {
        list->insertAt('r', 40);
    }
    catch (range_error e)
    {
        cout << e.what() << endl;
    }
    cout << endl;
    delete list;
}

/**
     * FUNCTION: tInsertInOrder
     * 
     * PURPOSE: tests the InsertInOrder method
     *  
     * PARAMETERS: N/A
     * 
     * RETURN: void
     * 
     * MISC: N/A
     **/

void tInsertInOrder()
{
    CharArrayList *list = new CharArrayList(new char[5]{'a', 'a', 'b', 'c', 'g'}, 5);
    list->print();
    cout << "Testing insertion of c in order: " << endl;
    list->insertInOrder('c');
    list->print();
    cout << endl;
    delete list;
}

/**
     * FUNCTION: tPopFromFront
     * 
     * PURPOSE: tests the popFromFront method
     *  
     * PARAMETERS: N/A
     * 
     * RETURN: void
     * 
     * MISC: N/A
     **/

void tPopFromFront()
{
    CharArrayList *list = new CharArrayList(new char[5]{'a', 'a', 'b', 'c', 'g'}, 5);
    list->print();
    cout << "Testing pop from front.." << endl;
    list->popFromFront();
    list->print();
    cout << "Clearing list.." << endl;
    list->clear();
    try
    {
        list->popFromFront();
    }
    catch (runtime_error e)
    {
        cout << e.what() << endl;
    }
    cout << endl;
    delete list;
}

/**
     * FUNCTION: tPopFromBack
     * 
     * PURPOSE: tests the popFromBack method
     *  
     * PARAMETERS: N/A
     * 
     * RETURN: void
     * 
     * MISC: N/A
     **/

void tPopFromBack()
{
    CharArrayList *list = new CharArrayList(new char[5]{'a', 'a', 'b', 'c', 'g'}, 5);
    list->print();
    cout << "Testing pop from back.." << endl;
    list->popFromBack();
    list->print();
    cout << "Clearing list.." << endl;
    list->clear();
    try
    {
        list->popFromBack();
    }
    catch (runtime_error e)
    {
        cout << e.what() << endl;
    }
    cout << endl;
    delete list;
}

/**
     * FUNCTION: tRemoveAt
     * 
     * PURPOSE: tests the removeAt method
     *  
     * PARAMETERS: N/A
     * 
     * RETURN: void
     * 
     * MISC: N/A
     **/

void tRemoveAt()
{
    CharArrayList *list = new CharArrayList(new char[5]{'a', 'a', 'b', 'c', 'g'}, 5);
    list->print();
    cout << "Removing index 3.." << endl;
    list->removeAt(3);
    list->print();
    try
    {
        list->removeAt(40);
    }
    catch (range_error e)
    {
        cout << e.what() << endl;
    }
    cout << endl;
    delete list;
}

void tReplaceAt()
{
    CharArrayList *list = new CharArrayList(new char[5]{'a', 'a', 'b', 'c', 'g'}, 5);
    list->print();
    cout << "Replacing index 3 with w.." << endl;
    list->replaceAt('w', 3);
    list->print();
    try
    {
        list->replaceAt('w', 40);
    }
    catch (range_error e)
    {
        cout << e.what() << endl;
    }
    cout << endl;
    delete list;
}

/**
     * FUNCTION: tConcatenate
     * 
     * PURPOSE: tests the concatenate method
     *  
     * PARAMETERS: N/A
     * 
     * RETURN: void
     * 
     * MISC: N/A
     **/

void tConcatenate()
{
    CharArrayList *list = new CharArrayList(new char[5]{'a', 'a', 'b', 'c', 'g'}, 5);
    CharArrayList *list2 = new CharArrayList(new char[5]{'s', 'v'}, 2);
    list->print();
    list2->print();
    cout << "Concatenating these two lists.." << endl;
    list->concatenate(list2);
    list->print();
    cout << endl;
    delete list;
    delete list2;
}

/**
     * FUNCTION: tShrink
     * 
     * PURPOSE: tests the shrink method
     *  
     * PARAMETERS: N/A
     * 
     * RETURN: void
     * 
     * MISC: N/A
     **/

void tShrink()
{
    CharArrayList *list = new CharArrayList('a');
    list->pushAtBack('a');
    list->pushAtBack('a');
    list->pushAtBack('r');
    list->pushAtBack('r');
    list->print();
    list->shrink();
    cout << endl;
    delete list;
}

/**
     * FUNCTION: tCopyConstructor
     * 
     * PURPOSE: tests the class's copy constructor
     *  
     * PARAMETERS: N/A
     * 
     * RETURN: void
     * 
     * MISC: N/A
     **/

void tCopyConstructor()
{
    CharArrayList *list = new CharArrayList(new char[5]{'a', 'a', 'b', 'c', 'g'}, 5);
    CharArrayList *list2 = new CharArrayList(*list);
    cout << "copying from list to list2 - printing list2" << endl;
    list->print();
    cout << list << endl;
    list2->print();
    cout << list2 << endl;
    cout << endl;
    delete list;
    delete list2;
}

/**
     * FUNCTION: tAssignmentOperator
     * 
     * PURPOSE: tests the class's assignment operator
     *  
     * PARAMETERS: N/A
     * 
     * RETURN: void
     * 
     * MISC: N/A
     **/

void tAssignmentOperator()
{
    CharArrayList *list = new CharArrayList(new char[5]{'a', 'a', 'b', 'c', 'g'}, 5);
    CharArrayList *list2;
    list2 = list;
    cout << "assigning list to list2 - printing list2" << endl;
    list->print();
    cout << list << endl;
    list2->print();
    cout << list2 << endl;
    cout << endl;
    delete list;
}