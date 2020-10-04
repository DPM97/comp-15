/*
 *
 */

#include "MetroSim.h"
#include <string>
#include <vector>
#include "Passenger.h"
#include "PassengerQueue.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <bits/stdc++.h>

using namespace std;

MetroSim::MetroSim() {}

MetroSim::MetroSim(const string &station_input, const string &output_input)
{
  simSize = 0;
  curStation = 0;
  passengers = 0;
  outfile = output_input;
  popSetup(station_input);
  takeInput();
}

MetroSim::MetroSim(const std::string &station_input,
                   const std::string &output_input, 
                   const std::string &commands_input)
{
  simSize = 0;
  curStation = 0;
  passengers = 0;
  outfile = output_input;
  popSetup(station_input);
  parseCommands(commands_input);
}

void MetroSim::popSetup(string station_input)
{
  populateStations(station_input);

  for (int i = 0; i < simSize; i++)
  {
    stationLines.push_back(PassengerQueue()); // populate stations
    train.push_back(PassengerQueue());        // populate train "cars"
  }
}

void MetroSim::populateStations(string station_input)
{
  ifstream station_data;
  string station;

  station_data.open(station_input);
  if (!station_data.is_open())
  {
    cerr << "Invalid stations.txt file..." << endl;
    exit(1);
  }
  else
  {
    getline(station_data, station);
    while (!station_data.eof())
    {
      stations.push_back(station);
      simSize++;
      getline(station_data, station);
    }
    station_data.close();
  }
}

void MetroSim::parseCommands(string commands_input)
{
  ifstream commands_data;
  string command;

  commands_data.open(commands_input);
  if (!commands_data.is_open())
  {
    cerr << "Invalid commands.txt file..." << endl;
    exit(1);
  }
  else
  {
    printState();
    getline(commands_data, command);
    while (!commands_data.eof())
    {
      if (command == "m m")
      {
        move();
      }
      else if (command == "m f")
      {
        cout << "Thanks for playing MetroSim. Have a nice day!" << endl;
        exit(0);
      }
      else
      { // add passenger
        newPassenger(command);
      }
      getline(commands_data, command);
      printState();
    }
    commands_data.close();
  }
}

void MetroSim::takeInput()
{
  printState();

  string command;
  cout << "Command? ";
  getline(cin, command);
  if (command == "m m")
  {
    move();
    takeInput();
  }
  else if (command == "m f")
  {
    cout << "Thanks for playing MetroSim. Have a nice day!" << endl;
    exit(0);
  }
  else
  { // add passenger
    newPassenger(command);
    takeInput();
  }
}

void MetroSim::printState()
{
  cout << "Passengers on the train: {";
  for (int i = 0; i < simSize; i++)
  {
    train.at(i).print();
  }
  cout << "}" << endl;
  for (int i = 0; i < simSize; i++)
  {
    if (curStation == i)
    cout << "TRAIN: ";
    cout << "[" << i + 1 << "] " << stations.at(i) << " ";
    cout << "{";
    stationLines.at(i).print();
    cout << "}" << endl;
  }
}

void MetroSim::move()
{
  loadPassengers();

  curStation++;
  if (curStation == simSize)
    curStation = 0;

  unloadPassengers();
}

void MetroSim::newPassenger(string passData)
{
  string p;
  string start;
  string end;

  stringstream iss(passData);
  getline(iss, p, ' ');
  getline(iss, start, ' ');
  getline(iss, end, ' ');

  passengers++; // this will be considered the passenger id
  stationLines.at(stoi(start) - 1).enqueue(
    Passenger(passengers, stoi(end), stoi(start))
  );
}

void MetroSim::unloadPassengers()
{
  // remove all passengers that are supposed to get off at this station
  
  PassengerQueue *t = &train.at(curStation);

  while (t->size() > 0 && t->front().to == curStation)
  {
    printPassenger(t->front().id);
    t->dequeue();
  }
}

void MetroSim::printPassenger(int id) {
    ofstream out;
    out.open(outfile, ios::app);

    int offStation = curStation - 1;
    if (curStation == -1) offStation = simSize;

    out << "Passenger " 
    << id
    << " left train at station "
    << stations.at(offStation)
    << endl;

    out.close();
}

void MetroSim::loadPassengers()
{
  // loads all passengers in queue at station
  while ((int)stationLines.at(curStation).size() > 0)
  {
    Passenger pass = stationLines.at(curStation).front();
    train.at(pass.to).enqueue(pass);
    stationLines.at(curStation).dequeue();
  }
}

MetroSim::~MetroSim()
{
  stationLines.clear();
  stations.clear();
  train.clear();

  curStation = 0;
  passengers = 0;
}
