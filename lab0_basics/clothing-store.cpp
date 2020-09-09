/* COMP15 Fall 2019 Lab 0
 * The COMP15 Clothing Store
 * September 3, 2019
 * Name:
 */

#include <iostream>
#include <fstream>
#include <string.h>
#include <sstream>
#include <vector>

using namespace std;

struct ClothingItem {
	string item_type;
	int num_in_stock;
};

const string FILENAME = "inventory.txt";

int read_inventory(ClothingItem *&inventory, string input_file);
void find_in_array(string input, ClothingItem *inventory, int num_items);

int main() {
	cout << "Welcome to the COMP15 Clothing Store!" << endl;
	
	ClothingItem *inventory = NULL;
	int num_items = read_inventory(inventory, FILENAME);

	string input = "";
	while (input != "quit") {
		cout << "What would you like to buy?" << endl;
		cin >> input;
		find_in_array(input, inventory, num_items);
	}		
    
	delete [] inventory;

	return 0;
}

/* Function: read_inventory
 * Parameters: ClothingItem *inventory (passed by reference), and 
 *      the name of the file from which to read inventory data.
 * Returns: the number of different items currently in stock
 * Does: Allocates an array of ClothingItem objects on the heap
 *      and populates the array with data from the file */
int read_inventory(ClothingItem *&inventory, string input_file) {

	std::ifstream inv;
	inv.open(input_file, std::ios::in);

	if (!inv.is_open()) {
		return 0;
	} else {
		cout << "File is Open!" << endl;

		string line;
		std::getline(inv, line);
		int items = std::stoi(line);

		inventory = new ClothingItem[items];

		for (int i = 0; i < items; i++) {
			std::getline(inv, line);

			std::string word;
			std::string amount;

			std::stringstream iss(line);
			std::getline(iss, word, ' ');
			std::getline(iss, amount, ' ');

			inventory[i].item_type = word;
			inventory[i].num_in_stock = std::stoi(amount);
		}

		return items;
	}
}

/* Function: find_in_array
 * Parameters: string representing the name of the clothing item to find,
 *      pointer to the beginning of the array of ClothingItems, and the
 *      number of items in the array.
 * Returns: void
 * Does: Searches the array for the given clothing item name. If found, 
 *      print the number of that item currently in stock. TODO: If not found, 
 *      tell the user we don't have any in stock. */
void find_in_array(string input, ClothingItem *inventory, int num_items) {
	if (input == "quit")
		return;
	for (int i = 0; i < num_items; i++) {
		if (inventory[i].item_type == input) {
			cout << "We have " << inventory[i].num_in_stock << " " << inventory[i].item_type << endl;
		}
	}
}
