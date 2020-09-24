/*
 * LinkedList.cpp
 * 
 * Comp 15 Lab 2
 * Edited by Elizabeth Hom, Sept 2020
 * 
 * The LinkedList class is a linked list of planet nodes.
 *
 * TODO: The LinkedList class is designed to be able to add nodes at the front
 *   and back of the list, but it currently cannot add to the back.
 *
 */

#include <ostream>
#include "LinkedList.h"

using namespace std;

// Default constructor -- initializes an empty LinkedList
LinkedList::LinkedList()
{
    length   = 0;
    front    = nullptr;
    curr_pos = nullptr;
}

// Assignment operator
LinkedList &LinkedList::operator= (const LinkedList &rhs)
{
    length   = rhs.length;
    curr_pos = nullptr;

    if (this == &rhs)                   // leave on self-assignment
            return *this;
    
    if (rhs.front == nullptr) {         // Empty lists are copied easily
        front = nullptr;
    } else {                            // Non-empty lists:  copy first node
        front = new Node;
        front->info = rhs.front->info;
        Node *curr = front;
        Node *orig = rhs.front;

        while (orig->next != nullptr) { // then copy any/all subsequent nodes 
            curr->next = new Node;
            curr->next->info = orig->next->info;
            orig = orig->next;
            curr = curr->next;
        }
    }

    return *this;
}

/* insert_planet
 *    Purpose: Inserts a planet at the front of the list and increments length
 * Parameters: a Planet object
 *    Returns: none
 */
void LinkedList::insert_planet(Planet p)
{
    Node *node = new Node;

    node->info = p;
    node->next = front;

    front = node;
    length++;
}

/* insert_planet_at_back
 *    Purpose: Inserts a planet at the back of the list and increments length.
 * Parameters: a Planet object
 *    Returns: none
 *
 */

void LinkedList::insert_planet_at_back(Planet p)
{
    Node *node;

    if (length == 0) {
        node = new Node;
        node->info = p;
        node->next = nullptr;
        front = node;
        length++;
        return;
    }

    node = front;

    while(node->next != nullptr) {
        node = node->next;
    }

    Node *newNode = new Node;
    newNode->info = p;
    newNode->next = nullptr;

    node->next = newNode;
    length++;
}

/* get_next_planet
 *    Purpose: Returns the Planet object at the current position. If at the end,
 *             wraps around to front of list. If empty, returns default planet.
 * Parameters: a Planet object
 *    Returns: none
 *
 */
Planet LinkedList::get_next_planet()
{
    if (length == 0) {
        Planet p;
        return p;
    }

    if (curr_pos == nullptr) {
        curr_pos = front;
    } else {
        curr_pos = curr_pos->next;
    }

    return curr_pos->info;
}

/* get_length
 *    Purpose: Returns the current length of the list
 * Parameters: none
 *    Returns: int - length of list
 */
int LinkedList::get_length() const
{
    return length;
}

/* print
 *    Purpose: Prints out each element in the list
 * Parameters: ostream & - where to print
 *    Returns: none
 */
void LinkedList::print(ostream &out) const
{
    Node *node = front;

    while (node != nullptr) {
        (node->info).print(out);
        out << endl;
        node = node->next;
    }
}
