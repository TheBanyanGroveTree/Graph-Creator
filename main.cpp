/**
   Description: Graph Creator
   Author: Aahana Sapra
   Date: 05/29/2026
*/


#include <iostream>
#include <string>
#include <limits>
#include "Graph.h"


using namespace std;


// Define function prototypes
void stringUpper(string& input);


int main() {
  Graph* g = new Graph(); // Create graph object

  // Declare vars for user input
  string userCommand = "";
  string label = "";
  string start = "";
  string end = "";
  int weight = 0;

  // Continue prompting user for input until QUIT command
  bool newInput = true;
  while (newInput) {
    // Read in user input
    cout << "Enter a command (ADD, REMOVE, PATH, PRINT, or QUIT): ";
    getline(cin, userCommand);
    stringUpper(userCommand); // Convert input to uppercase for comparison

    // Validate input and call appropriate method or exit program
    if (userCommand == "ADD") {
      // Prompt user for what to add
      cout << "What would you like to add? (v/e) ";
      getline(cin, userCommand);
      stringUpper(userCommand);
      
      // Vertex
      if (userCommand == "V") {
	// Prompt user for label
	cout << "Enter vertex label: ";
	getline(cin, label);
	
	g->addVertex(label);
      }

      // Edge
      if (userCommand == "E") {
	// Prompt user
	cout << "Enter start vertex label: ";
	getline(cin, start);
	cout << "Enter end vertex label: ";
	getline(cin, end);
	cout << "Enter edge weight (positive integer): ";
	cin >> weight;
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	g->addEdge(start, end, weight);
      }
      
    } else if (userCommand == "REMOVE") {
      // Prompt user for what to remove
      cout << "What would you like to remove? (v/e) ";
      getline(cin, userCommand);
      stringUpper(userCommand);
      
      // Vertex
      if (userCommand == "V") {
	// Prompt user for label
	cout << "Enter vertex label: ";
	getline(cin, label);
	
	g->removeVertex(label);
      }

      // Edge
      if (userCommand == "E") {
	// Prompt user
	cout << "Enter start vertex label: ";
	getline(cin, start);
	cout << "Enter end vertex label: ";
	getline(cin, end);
	
	g->removeEdge(start, end);
      }

      
    } else if (userCommand == "PATH") {
      // Prompt user for endpoints
      cout << "Enter start vertex label: ";
      getline(cin, start);
      cout << "Enter end vertex label: ";
      getline(cin, end);

      g->findShortestPath(start, end);
      
    } else if (userCommand == "PRINT") {
      g->printAdjacencyTable();

    } else if (userCommand == "QUIT") {
      newInput = false; // Change input status
      
    } else { // Invalid input
      cout << "Please input ADD, REMOVE, PATH, PRINT, or QUIT."
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
