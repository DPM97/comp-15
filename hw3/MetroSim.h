/*
 *
 */

#ifndef _METROSIM_H_
#define _METROSIM_H_

#include "Passenger.h"
#include "PassengerQueue.h"
#include <vector>
#include <string>
#include <fstream>


// Put any other structs you need here

class MetroSim
{
public:
  MetroSim();
  MetroSim(const std::string &station_input, const std::string &output_input);
  MetroSim(const std::string &station_input, const std::string &output_input, 
  const std::string &commands_input);
  ~MetroSim();

private:

  void move();
  void newPassenger(std::string passData);
  void loadPassengers();
  void unloadPassengers();
  void populateStations(std::string station_input);
  void parseCommands(std::string commands_input);
  void printState();
  void popSetup(std::string station_input);
  void takeInput();
  void printPassenger(int id);

  std::vector<PassengerQueue> train;
  std::vector<PassengerQueue> stationLines;
  std::vector<std::string> stations;
  int curStation;
  int passengers;
  int simSize;
  std::string outfile;
};

#endif
