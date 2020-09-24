/*
 *  COMP 15 HW 2 Cheshire ConCATenation - Time to linked up in Fur
 *
 *  LinkedList.cpp
 *
 *  PURPOSE: Implement a doubly linked-list and supporting methods
 *
 *  Modified By: Dylan Maloy
 *           On: Sep 23 2020
 */

//
// NOTE:  Do a "monomorphic" implementation for char LinkedLists
// first, then turn all the functions into template functions.
//
// DO NOT FORGET TO UNCOMMENT THE LAST TWO LINES IN THIS FILE WHEN YOU
// MAKE YOUR TEMPLATES!
//

#include "LinkedList.h"
#include "sstream"
#include <iostream>

using namespace std;

// Default constructor
template <typename E>
LinkedList<E>::LinkedList()
{
    length = 0;
    front = nullptr;
    back = nullptr;
    curr_pos = nullptr;
}

// Constructor taking a single element
template <typename E>
LinkedList<E>::LinkedList(E element)
{
    Node *node = new Node;
    node->val = element;
    node->next = nullptr;
    front = node;
    back = node;
    curr_pos = front;
    length = 1;
}

// Constructor taking an array of elements and a lenght
template <typename E>
LinkedList<E>::LinkedList(E elements[], int len)
{
    Node *prevNode = new Node;
    prevNode->val = elements[0];
    prevNode->next = nullptr;
    front = prevNode;
    back = prevNode;
    length = 1;
    Node *node;
    for (int i = 1; i < len; i++)
    {
        node = new Node;
        node->val = elements[i];
        node->next = nullptr;

        node->prev = prevNode;
        prevNode->next = node;

        prevNode = node;
        length++;
    }
    curr_pos = front;
    back = node; // set the last node equal to the back
    delete[] elements;
}

// Copy constructor
template <typename E>
LinkedList<E>::LinkedList(const LinkedList<E> &other)
{
    length = other.length;
    curr_pos = nullptr;

    if (other.front == nullptr)
    {
        front = nullptr;
        back = nullptr;
    }
    else
    {
        front = new Node;
        front->val = other.front->val;
        Node *curr = front;
        Node *orig = other.front;

        while (orig->next != nullptr)
        {
            curr->next = new Node;
            curr->next->val = orig->next->val;
            orig = orig->next;
            curr = curr->next;
        }
        back = curr;
    }
}

// Default destructor
template <typename E>
LinkedList<E>::~LinkedList()
{
    clear();
}

/**
     * FUNCTION: isEmpty
     * 
     * PURPOSE: Check if the linked list is empty
     *  
     * PARAMETERS: N/A
     * 
     * RETURN: bool
     * 
     * MISC: N/A
     **/

template <typename E>
bool LinkedList<E>::isEmpty()
{
    if (length == 0)
        return true;
    return false;
}

/**
     * FUNCTION: clear
     * 
     * PURPOSE: Clear the linked list
     *  
     * PARAMETERS: N/A
     * 
     * RETURN: void
     * 
     * MISC: N/A
     **/

template <typename E>
void LinkedList<E>::clear()
{
    if (length == 0)
        return;
    curr_pos = front;
    Node *next;
    while (length > 0)
    {
        next = curr_pos->next;
        delete curr_pos;
        curr_pos = next;
        length--;
    }
    curr_pos = front = back = nullptr;
}

/**
     * FUNCTION: size
     * 
     * PURPOSE: fetches size of linked list
     *  
     * PARAMETERS: N/A
     * 
     * RETURN: integer representing the size
     * 
     * MISC: N/A
     **/

template <typename E>
int LinkedList<E>::size()
{
    return length;
}

/**
     * FUNCTION: first
     * 
     * PURPOSE: returns first element in list
     *  
     * PARAMETERS: N/A
     * 
     * RETURN: element of type E
     * 
     * MISC: N/A
     **/

template <typename E>
E LinkedList<E>::first()
{
    if (length == 0)
        throw runtime_error("cannot get first of empty list");
    return front->val;
}

/**
     * FUNCTION: last
     * 
     * PURPOSE: returns last element in list
     *  
     * PARAMETERS: N/A
     * 
     * RETURN: element of type E
     * 
     * MISC: N/A
     **/

template <typename E>
E LinkedList<E>::last()
{
    if (length == 0)
        throw runtime_error("cannot get last of empty list");
    return back->val;
}

/**
     * FUNCTION: elementAt
     * 
     * PURPOSE: returns element at a given index
     *  
     * PARAMETERS: int index (index being fetched)
     * 
     * RETURN: element of type E
     * 
     * MISC: N/A
     **/

template <typename E>
E LinkedList<E>::elementAt(int index)
{

    if (index < 0 || index >= length)
    {
        ostringstream e;
        e << "index " << index << " not in range [0.." << length << "]";
        throw range_error(e.str());
    }

    curr_pos = front;
    for (int i = 0; i < index; i++)
    {
        curr_pos = curr_pos->next;
    }
    return curr_pos->val;
}

/**
     * FUNCTION: print
     * 
     * PURPOSE: prints the linked list
     *  
     * PARAMETERS: N/A
     * 
     * RETURN: void
     * 
     * MISC: N/A
     **/

template <typename E>
void LinkedList<E>::print()
{
    cout << "[LinkedList of size " << length << "<<";
    curr_pos = front;
    for (int i = 0; i < length; i++)
    {
        cout << curr_pos->val;
        curr_pos = curr_pos->next;
    }
    cout << ">>]" << endl;
}

/**
     * FUNCTION: pushAtBack
     * 
     * PURPOSE: pushes element to back of list
     *  
     * PARAMETERS: E element (element being inserted)
     * 
     * RETURN: void
     * 
     * MISC: N/A
     **/

template <typename E>
void LinkedList<E>::pushAtBack(E element)
{
    insertAt(element, length);
}

/**
     * FUNCTION: pushAtFront
     * 
     * PURPOSE: pushes element to front of list
     *  
     * PARAMETERS: E element (element being inserted)
     * 
     * RETURN: void
     * 
     * MISC: N/A
     **/

template <typename E>
void LinkedList<E>::pushAtFront(E element)
{
    insertAt(element, 0);
}

/**
     * FUNCTION: insertAt
     * 
     * PURPOSE: inserts element at index
     *  
     * PARAMETERS: E element (element being inserted), int index (index of insertion)
     * 
     * RETURN: void
     * 
     * MISC: N/A
     **/

template <typename E>
void LinkedList<E>::insertAt(E element, int index)
{

    if (index < 0 || index > length)
    {
        ostringstream e;
        e << "index " << index << " not in range [0.." << length << "]";
        throw range_error(e.str());
    }

    curr_pos = front;
    for (int i = 0; i < index; i++)
    {
        curr_pos = curr_pos->next;
    }

    Node *newNode = new Node;
    newNode->val = element;

    if (length == 0)
    {
        front = back = newNode;
        length++;
        return;
    }

    if (index == 0)
    {
        front->prev = newNode;
        newNode->next = front;
        front = newNode;
        length++;
        return;
    }
    else if (index == length)
    {
        back->next = newNode;
        newNode->prev = back;
        back = newNode;
        length++;
        return;
    }

    Node *last = curr_pos->prev;

    newNode->prev = last;
    last->next = newNode;
    newNode->next = curr_pos;
    curr_pos->prev = newNode;

    length++;
}

/**
     * FUNCTION: insertInOrder
     * 
     * PURPOSE: inserts element in order (assume alphabetical)
     *  
     * PARAMETERS: E element (element being inserted)
     * 
     * RETURN: void
     * 
     * MISC: N/A
     **/

template <typename E>
void LinkedList<E>::insertInOrder(E element)
{

    int index = 0;
    curr_pos = front;
    while (curr_pos != nullptr && element >= curr_pos->val)
    {
        curr_pos = curr_pos->next;
        index++;
    }

    insertAt(element, index);
}

/**
     * FUNCTION: popFromFront
     * 
     * PURPOSE: removes first element
     *  
     * PARAMETERS: N/A
     * 
     * RETURN: void
     * 
     * MISC: N/A
     **/

template <typename E>
void LinkedList<E>::popFromFront()
{
    if (length == 0)
        throw runtime_error("cannot pop from empty list");
    removeAt(0);
}

/**
     * FUNCTION: popFromBack
     * 
     * PURPOSE: removes last element
     *  
     * PARAMETERS: N/A
     * 
     * RETURN: void
     * 
     * MISC: N/A
     **/

template <typename E>
void LinkedList<E>::popFromBack()
{
    if (length == 0)
        throw runtime_error("cannot pop from empty list");
    removeAt(length - 1);
}

/**
     * FUNCTION: removeAt
     * 
     * PURPOSE: removes element at index
     *  
     * PARAMETERS: int index (index to be removed)
     * 
     * RETURN: void
     * 
     * MISC: N/A
     **/

template <typename E>
void LinkedList<E>::removeAt(int index)
{

    if (index < 0 || index >= length)
    {
        ostringstream e;
        e << "index " << index << " not in range [0.." << length << "]";
        throw range_error(e.str());
    }

    if (length == 1)
        clear();

    if (index == 0)
    {
        Node *temp = front;
        front = temp->next;
        front->prev = nullptr;
        delete temp;
        length--;
        return;
    }
    else if (index == length - 1)
    {
        Node *temp = back;
        back = temp->prev;
        back->next = nullptr;
        delete temp;
        length--;
        return;
    }

    curr_pos = front;
    for (int i = 0; i < index; i++)
    {
        curr_pos = curr_pos->next;
    }

    Node *curPrev = curr_pos->prev;
    curPrev->next = curr_pos->next;

    delete curr_pos;

    length--;
}

/**
     * FUNCTION: replaceAt
     * 
     * PURPOSE: replaces element at index
     *  
     * PARAMETERS: int index (index to be replaced)
     * 
     * RETURN: void
     * 
     * MISC: N/A
     **/

template <typename E>
void LinkedList<E>::replaceAt(E element, int index)
{

    if (index < 0 || index >= length)
    {
        ostringstream e;
        e << "index " << index << " not in range [0.." << length << "]";
        throw range_error(e.str());
    }

    curr_pos = front;
    for (int i = 0; i < index; i++)
    {
        curr_pos = curr_pos->next;
    }
    curr_pos->val = element;
}

/**
     * FUNCTION: concatenate
     * 
     * PURPOSE: adds one linked list onto the end of the other
     *  
     * PARAMETERS: LinkedList *list2 (list to be added onto the end)
     * 
     * RETURN: void
     * 
     * MISC: N/A
     **/

template <typename E>
void LinkedList<E>::concatenate(LinkedList *list2)
{

    for (int i = 0; i < list2->length; i++)
    {
        pushAtBack(list2->elementAt(i));
    }
}

/**
     * FUNCTION: shrink
     * 
     * PURPOSE: reduces memory to bare minimum 
     *  
     * PARAMETERS: N/A
     * 
     * RETURN: void
     * 
     * MISC: N/A
     **/

template <typename E>
void LinkedList<E>::shrink() {}

template <typename E>
bool LinkedList<E>::find(E element)
{
    curr_pos = front;
    if (occurances(element, 0) != 0)
        return true;
    return false;
}

template <typename E>
int LinkedList<E>::occurances(E element, int i)
{
    if (curr_pos->val == element)
        i++;
    if (curr_pos->next != nullptr)
    {
        curr_pos = curr_pos->next;
        return occurances(element, i);
    }
    else
    {
        return i;
    }
}

template class LinkedList<char>;
template class LinkedList<int>;