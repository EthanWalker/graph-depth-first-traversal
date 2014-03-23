/*******************************************************************
*   File: Prog3Graph.h											   * 
*   Name: James Walker (Ethan)									   *
*   Project: Programming Assignment 3: Graph Depth First Traversal *
*   Creation Date: 11/20/2013									   *
*   Purpose: Header file for a graph class 						   *
*   															   *
*******************************************************************/


#ifndef PROG3GRAPH_H
#define PROG3GRAPH_H
#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <stdlib.h>
#include "GraphNode.h"

using namespace std;

#define NUMNODES 10

class Prog3Graph
{
     private:
		  
          ifstream  inFile;         // File stream to read from
          int       AdjMatrix[NUMNODES][NUMNODES];
          GraphNode Nodes[NUMNODES];
		  int nodesInserted;
		  int neighbors[9];

     public:

          ///////////////////////// Functions I added /////////////////////////////
          void populateNodes(char *filename);
          void populateEdges(char *filename);
          void insertEdge(int nodeA_ID, int nodeB_ID);
          void insertNode(int ID, char *data, int edges);
          int getNode(int ID);	
          bool hasEdge(int nodeA_ID, int nodeB_ID);
          void getNeighbors(int nodeA_ID, int *neighbors); // can modify to take in an array ptr
          ////////////////////////////////////////////////////////////////////////				
		  
          Prog3Graph();                     // Class constructor
          ~Prog3Graph();                    // Class destructor
          bool buildGraph(char *filename);  // Read graph file, build graph
          void printGraph();                // Print all data in graph
          void depthFirstTraversal();       // Perform a depth first traversal
     private:
          bool getNextLine(char *line, int lineLen); // Read next line from graph file
};

#endif





