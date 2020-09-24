/*
 * planet-driver.cpp
 * 
 * Comp 15 Lab 2
 * Edited by Elizabeth Hom, Sept 2020
 *
 * Driver for a planetary system program, details a linked list of planets.
 *
 * TODO: In part 1, the driver currently prints in default order (backwards).
 *       However, it must also be able to print the planets in reverse order.
 *
 */

#include <iostream>
#include "LinkedList.h"
#include "Planet.h"

using namespace std;

void reverse_list(LinkedList &lst1, LinkedList &lst2);

// User string to stop entering planets
const string STOP   = "done";
const string PROMPT = "Enter a planet (or \""
                      + STOP
                      + "\" to stop)\n";
/* get_string
 *    Purpose: Reads a string from cin following a prompt printed to cout
 * Parameters: string - prompt
 *    Returns: string - input read from cin
 */
string get_string(string prompt)
{
        string result;
        
        cout << prompt;
        cin  >> result;

        return result;
}
        
int main()
{
        // Make a list of planets and prompt user for names
        LinkedList planets, planets_inverse;
        string     name;

        cout << "PART 1: Inserting at the front of the list\n";

        name = get_string(PROMPT);
        while (name != STOP) {
                cout << endl;
                Planet p(name);
                planets.insert_planet(p);
                name = get_string(PROMPT);
        }

        // Print in default order (backwards)
        cout << "List of planets, default:\n";
        planets.print(cout);    
        cout << endl;

        LinkedList planetsReversed;
        cout << "List of planets, correct order:\n";
        reverse_list(planets, planetsReversed);
        planetsReversed.print(cout);    


        cout << "PART 2: Inserting at the back of the queue\n";
        cout << "This time with insert_planet_at_back\n";
        name = get_string(PROMPT);
        while (name != STOP) {
                cout << endl;
                Planet p(name);
                planets_inverse.insert_planet_at_back(p);
                name = get_string(PROMPT);
        }

        // Print in order of arrival
        cout << "List of planets."
             << "  We inserted at the back, so should be"
             << " in correct order already\n";
        planets_inverse.print(cout);    

        return 0;       
}

/* reverse_list
 *    Purpose: Reverses a linked list by storing the elements of lst1 into
 *             lst2 in reverse order
 * Parameters: The linked list (lst1) to be reversed, the reversed linked list
 *             (lst2)
 *    Returns: none
 *
 *       Note: There is no need to return anything, because both lists are
 *             passed by refernce.
 */
void reverse_list(LinkedList &lst1, LinkedList &lst2)
{
    Planet p = lst1.get_next_planet();
    for (int i = 0; i < lst1.get_length() - 1; i++) {
        lst2.insert_planet(p);
        p = lst1.get_next_planet();
    }
    lst2.insert_planet(p);
}
