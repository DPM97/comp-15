/*
 *
 */

#include "MetroSim.h"

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(int argc, char *argv[])
{
	if (!argv[3]) {
		MetroSim sim(argv[1], argv[2]);
	} else {
		MetroSim sim(argv[1], argv[2], argv[3]);
	}
	return 0;
}
