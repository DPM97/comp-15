#include "PassengerQueue.h"
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

// default constructor
PassengerQueue::PassengerQueue()
{
}

// default destructor
PassengerQueue::~PassengerQueue()
{
  list.clear();
}

/**
     * FUNCTION: front
     * 
     * PURPOSE: returns first element in queue
     *  
     * PARAMETERS: N/A
     * 
     * RETURN: void
     * 
     * MISC: N/A
     **/

Passenger PassengerQueue::front()
{
  return list.at(0);
}

/**
     * FUNCTION: enqueue
     * 
     * PURPOSE: adds an element to the queue
     *  
     * PARAMETERS: Passenger &pass (reference to passenger)
     * 
     * RETURN: void
     * 
     * MISC: N/A
     **/

void PassengerQueue::enqueue(const Passenger &pass)
{
  list.push_back(pass);
}

/**
     * FUNCTION: dequeue
     * 
     * PURPOSE: removes element from queue
     *  
     * PARAMETERS: N/A
     * 
     * RETURN: void
     * 
     * MISC: N/A
     **/

void PassengerQueue::dequeue()
{
  list.erase(list.begin());
}

/**
     * FUNCTION: size
     * 
     * PURPOSE: gets size of queue
     *  
     * PARAMETERS: 
     * 
     * RETURN: void
     * 
     * MISC: N/A
     **/

int PassengerQueue::size()
{
  return (int) list.size();
}

/**
     * FUNCTION: print
     * 
     * PURPOSE: prints all elements in queue
     *  
     * PARAMETERS: N/A
     * 
     * RETURN: void
     * 
     * MISC: N/A
     **/

void PassengerQueue::print()
{
  for (int i = 0; i < (int) list.size(); i++)
  {
    list.at(i).print();
  }
}

