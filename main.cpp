/**
   Description: Graph Creator
   Author: Aahana Sapra
   Date: 05/29/2026
*/


#include <iostream>
#include <string>
#include "Graph.h"


using namespace std;


// Define function prototypes
void stringUpper(string& input);


int main() {
  Graph g; // Create graph object

  // Continue prompting user for input until QUIT command
  bool newInput = true;
  while (newInput) {
    // Read in user input
    cout << "Enter a command (ADD, REMOVE, PATH, PRINT, or QUIT): ";
    getline(cin, userCommand);

    stringUpper(userCommand); // Convert input to uppercase for comparison

    // Validate input and call appropriate method or exit program
    if (userCommand == "ADD") {
      // Vertex

      // Edge
      
    } else if (userCommand == "REMOVE") {
      // Vertex

      // Edge
      
    } else if (userCommand == "PATH") {

      
    } else if (userCommand == "PRINT") {


    } else if (userCommand == "QUIT") {
      newInput = false; // Change input status
      
    } else { // Invalid input
      cout << "Please input ADD, READ, SEARCH, DELETE, PRINT, or QUIT."
	   << endl;
    }
  }

  return 0;
}


// Convert string to uppercase
void stringUpper(string& input) {
  for (int i = 0; i < input.size(); i++) {
      input[i] = toupper(input[i]);
    }
}
