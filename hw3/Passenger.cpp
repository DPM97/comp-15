/*
 *
 */

#include <iostream>
#include <string>
#include "Passenger.h"

using namespace std;

/*
 * Remember to write a complete function contract here!
 */

void Passenger::print()
{
        cout << "[";
        cout << id;
        cout << ", ";
        cout << from;
        cout << "->";
        cout << to;
        cout << "]";
}

