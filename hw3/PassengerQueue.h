/*
 *
 */

#ifndef __PASSENGER_QUEUE_H__
#define __PASSENGER_QUEUE_H__

#include "Passenger.h"
#include <vector>

class PassengerQueue
{
public:

  PassengerQueue();
  ~PassengerQueue();

  Passenger front();
  void dequeue();
  void enqueue(const Passenger &passenger);

  int size();
  void print();

private:
  std::vector<Passenger> list;
};

#endif
