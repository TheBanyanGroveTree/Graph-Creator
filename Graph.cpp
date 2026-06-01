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

}


// Add directed edge with given weight
void Graph::addEdge(string& start, string& end, int weight) {

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
