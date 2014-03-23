/*******************************************************************
*   File: GraphNode.cpp											   * 
*   Name: James Walker (Ethan)									   *
*   Project: Programming Assignment 3: Graph Depth First Traversal *
*   Creation Date: 11/20/2013									   *
*   Purpose: CPP file for a node class 							   *
*   															   *
*******************************************************************/
#include <iostream>
#include "GraphNode.h"
using namespace std;


//--------------------------------------------
// Function: GraphNode()					 *
// Purpose: Class Constructor				 *
// Returns: void							 *
//--------------------------------------------
	GraphNode::GraphNode()
	{
		char m_sNodeData[25] = {0};
		m_bVisited = false;
		numberOfEdges = 0;
	}

//--------------------------------------------
// Function: ~GraphNode()					 *
// Purpose: Class Deconstructor				 *
// Returns: void							 *
//--------------------------------------------
	GraphNode::~GraphNode()
	{
	
	}                    

//--------------------------------------------
// Function: setNodeID()					 *
// Purpose: NodeID Setter					 *
// Returns: void							 *
//--------------------------------------------
	void GraphNode::setNodeID(int ID)
	{
		m_iNodeID = ID;
		return;
	}

//--------------------------------------------
// Function: setNodeData()					 *
// Purpose: NodeData Setter					 *
// Returns: void							 *
//--------------------------------------------
	void GraphNode::setNodeData(char *data)
	{
		strcpy(m_sNodeData, data);
		return;
	}

//--------------------------------------------
// Function: setVisited()					 *
// Purpose: Set private visited variable	 *
// Returns: void							 *
//--------------------------------------------
	void GraphNode::setVisited(bool visited)
	{
		m_bVisited = visited;
		return;
	}
//--------------------------------------------
// Function: getNodeID()					 *
// Purpose: NodeID Getter Function			 *
// Returns: int								 *
//--------------------------------------------
	int GraphNode::getNodeID()
	{
		return m_iNodeID;
	}

//--------------------------------------------
// Function: *getNodeData()					 *
// Purpose: NodeData Getter Function		 *
// Returns: char *							 *
//--------------------------------------------
	char* GraphNode::getNodeData()
	{
		return m_sNodeData;
	}

//--------------------------------------------
// Function: hasBeenVisited()				 *
// Purpose: Get private visited variable	 *
// Returns: bool							 *
//--------------------------------------------
	bool GraphNode::hasBeenVisited()
	{
		return m_bVisited;
	}
	void GraphNode::setNumberOfEdges(int edges)
	{
		numberOfEdges = edges;
	}
	
	int GraphNode::getNumberOfEdges()
	{
		return numberOfEdges;
	}

	