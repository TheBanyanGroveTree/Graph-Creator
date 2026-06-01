#ifndef GRAPH_H
#define GRAPH_H


#include <iostream>
#include <string>


using namespace std;


// Define const var
const int MAX_VERTICES = 20;
const int NO_EDGE = 0;
const int INF = 999999;


class Graph {
 public:
  Graph();
  void addVertex(string& label);
  void addEdge(string& start, string& end, int weight);
  void removeVertex(string& label);
  void removeEdge(string& start, string& end);
  void findShortestPath(string& start, string& end);
  void printAdjacencyTable();
  int getNumVertices();

 private:
  string labels[MAX_VERTICES];
  int adjMatrix[MAX_VERTICES][MAX_VERTICES];
  int numVertices;
  int getIndex(string& label);
};

#endif
