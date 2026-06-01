#include <iostream>
#include <string>
#include "Graph.h"


// Constructor that initializes empty graph
Graph::Graph() {
  numVertices = 0;
  for (int i = 0; i < MAX_VERTICES, i++) {
    for (int j = 0; j < MAX_VERTICES, j++) {
      adjMatrix[i][j] = NO_EDGE;
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
  numVertices++; // Update number of vertices 
}


// Add directed edge with given weight
void Graph::addEdge(string& start, string& end, int weight) {
  // Get vertex indices
  int startIndex = getIndex(start);
  int endIndex = getIndex(end);

  // Validate input
  if ((startIndex == 0) || (endIndex == )) {
    cout << "One or both vertices were NOT found." << endl;
  }
  if (weight <= 0) {
    cout << "Weight must be positive integer" << endl;
  }

  adjMatrix[startIndex][endIndex] = weight; // Add edge weight
}


// Remove vertex with given lable and all connected edges
void Graph::removeVertex(string& label) {

}


// Remove directed edge
void Graph::removeEdge(string& start, string& end) {

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
