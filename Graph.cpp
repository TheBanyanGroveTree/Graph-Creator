#include <iostream>
#include <string>
#include "Graph.h"


// Constructor that initializes empty graph
Graph::Graph() {
  numVertices = 0;
  for (int i = 0; i < MAX_VERTICES, i++) {
    for (int j = 0; j < MAX_VERTICES, j++) {
      adjTable[i][j] = NO_EDGE;
    }
  }
}


// Add new vertex with given label
void Graph::addVertex(string& label) {
  // Graph is full
  if (numVertices >= MAX_VERTICES) {
    cout << "Graph is full. Try again next time." << endl;
  }
  // Label already exists
  else if (getIndex(label) != -1) {
    cout << "Vertex already exists." << endl;
  }

  labels[numVertices] = label; // Add to label array
  
  // Initialize in adjacency table
  for (int i = 0; i < MAX_VERTICES; i++) {
    adjTable[numVertices][i] = NO_EDGE;
    adjTable[i][numVertices] = NO_EDGE;
  }
  
  numVertices++; // Update number of vertices 
}


// Add directed edge with given weight
void Graph::addEdge(string& start, string& end, int weight) {
  // Get vertex indices
  int startIndex = getIndex(start);
  int endIndex = getIndex(end);

  // Validate input
  if ((startIndex == -1) || (endIndex == -1)) {
    cout << "One or both vertices were NOT found." << endl;
  }
  if (weight <= 0) {
    cout << "Weight must be positive integer" << endl;
  }

  adjTable[startIndex][endIndex] = weight; // Add edge weight
}


// Remove vertex with given lable and all connected edges
void Graph::removeVertex(string& label) {
  // Validate input
  int index = getIndex(label);
  if (index == -1) {
    coutn << "Vertex NOT found." << endl;
  }

  // Fill gap
  for (int i = index; (i < numVertices - 1); i++) {
    labels[i] = labels[i + 1];
    // Shift adjacency rows up
    for (int j = 0; j < MAX_VERTICES; j++) {
      adjTable[i][j] = adjMatrix[i + 1][j];
    }
  }
  // Shift adjacency columns left
  for (int j = index; (j < numVertices - 1); j++) {
    for (int i = 0; i < MAX_VERTICES; i++) {
      adjTable[i][j] = adjMatrix[i][j + 1];
    }
  }

  // Clear unused row and column
  numVertices--;
  for (int i = 0; i < MAX_VERTICES; i++) {
    adjTable[numVertices][i] = NO_EDGE;
    adjTable[i][numVertices] = NO_EDGE;
  }
}


// Remove directed edge
void Graph::removeEdge(string& start, string& end) {
  // Get vertex indices
  int startIndex = getIndex(start);
  int endIndex = getIndex(end);

  // Validate input
  if ((startIndex == -1) || (endIndex == -1)) {
    cout << "One or both vertices were NOT found." << endl;
  }
  if (adjTable[startIndex][endIndex] == NO_EDGE) {
    cout << "Edge does NOT exist." << endl;
  }

  adjTable[startIndex][endIndex] = NO_EDGE; // Update table 
}


// Use Dijkstra's Algorithm to find shortest path between vertices
void Graph::findShortestPath(string& start, string& end) {

}


// Print adjacency table
void Graph::printAdjacencyTable() {

}


// Get number of vertices
int Graph::getNumVertices() {
  return numVertices;
}


// Get index of vertex by label
int Graph::getIndex(string& label) {
  for (int i = 0; i < numVertices; i++) {
    if (labels[i] == label) {
      return i;
    }
  }
  return -1; // NOT found
}
