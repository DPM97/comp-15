/*
 *      CircularBuffer.cpp 
 *      PartyPlaylist 
 *      Comp 15 Lab 3
 *
 *      2016-09-16 Created by Yennie Jun
 *      2016-09-20 Documentation added by Mark A. Sheldon, Tufts University
 *      2019-08-01 Modified by Alice Dempsey
 *      2020-01-31 Modified by Juliana Vega
 *                 Removed "sequence" wording
 *      2020-09-21 Modified by Matt Champlin
 *                 Added prevIndex function that wraps around.
 *                 Note: "front" always points to first element. "back" always
 *                       points to the next available empty slot. 
 */

#include <iostream>
#include <stdexcept>

#include "CircularBuffer.h"

using namespace std;

/*  Purpose:    Gets the next index in the buffer
 *  Parameters: index - the index to increment
 *  Returns:    The index of the next element in the buffer.
 *  Notes:      Wraps around!
 */
int CircularBuffer::nextIndex(int index)
{
        index++;
        return index % capacity;
        // for instance if x = capacity + 1 it will just return 1;
        // else if under the capacity it will return the usual index;
}

/*  Purpose: Default constructor
 *  Notes:   INIT_CAPACITY is set to 5 in .h file
 */
CircularBuffer::CircularBuffer()
{
        init(INIT_CAPACITY);
}

/*  Purpose:    Overloaded Constructor for a buffer with a hint for an initial
 *              capacity.
 *  Parameters: initialCapacity - Capacity user wants buffer to be
 */
CircularBuffer::CircularBuffer(int initialCapacity)
{
        init(initialCapacity);
}

/*  Purpose:    Initialize a new, empty CircularBuffer with an initial capacity
 *  Parameters: initialCapacity - Capacity user wants buffer to be 
 */
void CircularBuffer::init(int initialCapacity)
{
        capacity = initialCapacity;
        bufferArray = new ElementType[capacity];
        currentSize = 0;
        front = 0;
        back = 0;
}

/*  Purpose: Destructor. Recycles the dynamically allocated array containing
 *           the data.
 */
CircularBuffer::~CircularBuffer()
{
        delete[] bufferArray;
}

/*  Purpose:    Add given element to the back of the buffer
 *  Parameters: elem - object to add to the buffer
 *  Notes:      ElementType is defined in ElementType.h
 */
void CircularBuffer::addAtBack(ElementType elem)
{
        if (currentSize == capacity) expand();
        currentSize++;
        back = nextIndex(back);
        bufferArray[back] = elem;
}

/*  Purpose:    Add given element to the front of the list
 *  Parameters: elem - object to add to the buffer
 *  Notes:      ElementType is defined in ElementType.h
 */
void CircularBuffer::addAtFront(ElementType elem) // STUDENT TODO:
{
        if (currentSize == capacity)
                expand();

        if (front == 0)
        {
                front = capacity - 1;
        }
        else
        {
                front--;
        }

        currentSize++;
        bufferArray[front] = elem;

        (void)elem;
}

/*  Purpose:    Remove the element at the back of the list and return it.
 *  Returns:    The ElementType at the back of the list.    
 */
ElementType CircularBuffer::removeFromBack()
{
        ElementType tempEl = bufferArray[back];

        bufferArray[back] = "";
        if (back == 0)
        {
                back = capacity - 1;
        }
        else
        {
                back--;
        }
        currentSize--;
        return tempEl;
}

/*  Purpose:    Remove the element at the front of the list and return it.
 *  Returns:    The ElementType at the front of the list. 
 */
ElementType CircularBuffer::removeFromFront()
{
        ElementType tempEl = bufferArray[front];
        bufferArray[front] = "";
        front = nextIndex(front);
        currentSize--;
        return tempEl;
        
}

/*  Purpose:    Expand the capacity of the array by a factor of 2 + 2.
 *  Parameters: None
 *  Notes:      This one is tricky! It will be different than the expand you
 *              are used to writing. Think about how to handle wrapping. Also
 *              think about how you are going to ensure that "front" and "back"
 *              maintain their meaning once you've copied the items over.
 */
void CircularBuffer::expand()
{

        ElementType *newArr = new ElementType[(capacity * 2) + 2];

        int currIndex = front;
        for (int i = 0; i < currentSize; i++)
        {
                newArr[i] = bufferArray[currIndex];
                currIndex = nextIndex(currIndex);
        }

        front = 0;
        back = currentSize - 1;
        capacity = (capacity * 2) + 2;

        delete[] bufferArray;
        bufferArray = newArr;
}

/*  Purpose: Print the contents of the CircularBuffer, one element per line.
 *  Notes:   Prints the elements place in the lists, starting at 1
 */
void CircularBuffer::printBuffer()
{
        int currIndex = front;
        for (int i = 0; i < currentSize; i++)
        {
                cout << i + 1 << ": " << bufferArray[currIndex] << endl;
                currIndex = nextIndex(currIndex);
        }
}