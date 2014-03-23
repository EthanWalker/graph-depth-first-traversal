#include <iostream>
#include "Prog3Graph.h"


using namespace std;

int main()
{
	 // build graph  from input file
	 // print graph contents
	 // print matrix
	 // print step by step DFT
	Prog3Graph *graph = new  Prog3Graph();
	graph->buildGraph("graph.txt");
	graph->printGraph();
	graph->depthFirstTraversal();

	cin.get();
	return 0;
}