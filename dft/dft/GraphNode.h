/*******************************************************************
*   File: GraphNode.h											   * 
*   Name: James Walker (Ethan)									   *
*   Project: Programming Assignment 3: Graph Depth First Traversal *
*   Creation Date: 11/20/2013									   *
*   Purpose: Header file for a node class 						   *
*   															   *
*******************************************************************/

#ifndef GRAPHNODE_H
#define GRAPHNODE_H

class GraphNode
{
private:
	int m_iNodeID;
	int numberOfEdges;
	char m_sNodeData[25];
	bool m_bVisited;

public:
	GraphNode();                     // Class constructor
    ~GraphNode();                    // Class destructor
	void setNodeID(int ID);
	void setNodeData(char *data);
	void setVisited(bool visited);
	int getNodeID();
	char *getNodeData();
	bool hasBeenVisited();
	int getNumberOfEdges();
	void setNumberOfEdges(int edges);

};
#endif