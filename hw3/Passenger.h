/*
 *
 */


#ifndef __PASSENGER_H__
#define __PASSENGER_H__

struct Passenger
{

        int id, from, to;
        
        Passenger()
        {
                id   = -1;
                from = -1;
                to   = -1;
        }

        Passenger(int newId, int arrivalStation, int departureStation)
        {
                id   = newId;
                to = arrivalStation;
                from   = departureStation;
        }

        // TODO: implement the print function in Passenger.cpp
        void print();

};

#endif
