/*******************************************************************
*   File: Prog3Graph.cpp										   * 
*   Name: James Walker (Ethan)									   *
*   Project: Programming Assignment 3: Graph Depth First Traversal *
*   Creation Date: 11/20/2013									   *
*   Purpose: CPP file for a graph class 						   *
*   															   *
*******************************************************************/

#include <sstream>
#include "Prog3Graph.h"
#include "Stack.h"
/////////////////////////////////////////////////////////////////////////
///////////////////////// Functions I added /////////////////////////////
/////////////////////////////////////////////////////////////////////////

//--------------------------------------------
// Function: populateNodes()				 *
// Purpose: Populate Node array				 *
// Returns: void							 *
//--------------------------------------------
	void Prog3Graph::populateNodes(char *filename)
	{
		
		inFile.open(filename);	
	    char line[80];
		 
		int inputData;
		

	    getNextLine(line, 80);		// priming read
        bool stillNextLine = true;
		
		

        // Continue while there is still data being read
        while(stillNextLine == true)
        { 
			
			int numEdges = 0;
			stringstream streamVar(line);
			streamVar >> inputData;	
		           					
			getNextLine(line, 80);
	
			
			

			getNextLine(line, 80);
			streamVar.str(std::string());
			streamVar.clear();
			streamVar << line;	// convert number of edges to int
			streamVar >> numEdges;

			insertNode(inputData, line, numEdges);

			for(;numEdges > 0; numEdges--)
			{
				getNextLine(line, 80);			
			}

			streamVar.str(std::string());
			streamVar.clear();
            stillNextLine = getNextLine(line, 80);
			
        }
		inFile.close();
            // Repeat while variable = true		    
    		    // Save line to nodeID
    		    // getNextLine
    		    // Save line to nodeData
    		    // getNextLine
    		    // save line to number of edges
    		    // do a for loop to skip that many lines (= edges)
    		    // variable = getNextLine
		     
		             
		//   - adds all nodes in file (calls insertNode(); maybe getNode()
		//     to check if it's already there too)
	}

//--------------------------------------------
// Function: populateEdges()				 *
// Purpose: Populate AdjMatrix				 *
// Returns: void							 *
//--------------------------------------------
	void Prog3Graph::populateEdges(char *filename)
	{
		// - reads through file
		// - adds all edges in file

		inFile.open(filename);	
	    char line[80];
		int inputData;

		getNextLine(line, 80);		// priming read
        bool stillNextLine = true;
		
		
		while(stillNextLine == true)
        { 
			int numEdges = 0;
			
			
			
			stringstream streamVar(line);
			streamVar >> inputData;	
			int aIndex = inputData;
			streamVar.str(std::string());
			streamVar.clear();
       
			getNextLine(line, 80);
			getNextLine(line, 80);
			streamVar << line;
			streamVar >> inputData;
			numEdges = inputData;
			streamVar.str(std::string());
			streamVar.clear();
			


			for(;numEdges > 0; numEdges--)
			{
				getNextLine(line, 80);
				stringstream streamVar(line);
				streamVar >> inputData;
				int bIndex = inputData;
				streamVar.str(std::string());
				streamVar.clear();
				insertEdge(aIndex, bIndex);
			}


            stillNextLine = getNextLine(line, 80);	
        }
		inFile.close();
	}

//--------------------------------------------
// Function: insertEdge()					 *
// Purpose: Insert edge in AdjMatrix		 *
// Returns: void							 *
//--------------------------------------------
	void Prog3Graph::insertEdge(int nodeA_ID, int nodeB_ID)
	{
		
        int aIndex = getNode(nodeA_ID);
		int bIndex = getNode(nodeB_ID);
		
		AdjMatrix[aIndex][bIndex] = 1;
		AdjMatrix[bIndex][aIndex] = 1;	
	}

//--------------------------------------------
// Function: insertNode()					 *
// Purpose: Insert nodes in node array		 *
// Returns: void							 *
//--------------------------------------------
	void Prog3Graph::insertNode(int ID, char *data, int edges)
	{
		
		GraphNode *newNode = new GraphNode();
        newNode->setNodeID(ID);
        newNode->setNodeData(data);
		newNode->setNumberOfEdges(edges);
        Nodes[nodesInserted] = *newNode;
        nodesInserted++;
		
	}

//--------------------------------------------
// Function: getNode()						 *
// Purpose: Get node index based on ID		 *
// Returns: int								 *
//--------------------------------------------
	int Prog3Graph::getNode(int ID)
	{
	    for (int i = 0; i < NUMNODES; i++)
	    {
	        if (Nodes[i].getNodeID() == ID)
	        {
	            return i; 
	        }
	    }
	    return -1; // node not found
	}	   

//--------------------------------------------
// Function: hasEdge()						 *
// Purpose: Returns TRUE if edge exist		 *
// Returns: bool							 *
//--------------------------------------------
	bool Prog3Graph::hasEdge(int nodeA_ID, int nodeB_ID)
	{
       int aIndex = getNode(nodeA_ID);
       int bIndex = getNode(nodeB_ID);
	   return AdjMatrix[aIndex][bIndex];	
	}

//--------------------------------------------
// Function: getNeighbors()					 *
// Purpose: Returns list of neighbors		 *
// Returns: int	array						 *
//--------------------------------------------
	void Prog3Graph::getNeighbors(int nodeA_ID,  int *neighbors)
	{
	  int i = 0; 
      for each (GraphNode node in Nodes)
	  {
		 
		 if(hasEdge(nodeA_ID, node.getNodeID()))
		  {
				  
				  neighbors[i] = node.getNodeID();				  
				  i++;
		  }
		
	  }
	}
/////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////

Prog3Graph::Prog3Graph()
{
	nodesInserted = 0;
	int neighbors[9] = {0};
	 memset(AdjMatrix, 0, sizeof(AdjMatrix[0][0]) * NUMNODES * NUMNODES);
} 

Prog3Graph::~Prog3Graph()
{

}

bool Prog3Graph::buildGraph(char *filename)   // must return a value
{
	//cout << "Calling buildGraph()";
	populateNodes(filename);
	populateEdges(filename);

	//cout << "... done." << endl;
	return true;
}

void Prog3Graph::printGraph()
{
	cout << "Graph Contents: " << endl;
	cout << "Nodes: " << endl;
	

	int numberOfNode = 0;
	for each (GraphNode node in Nodes)
	{
		
		cout << numberOfNode << " " << node.getNodeID() << " " << node.getNodeData() << endl;
		numberOfNode++;
	}

	cout << "\nAdjacency Matrix: " << endl;
	for ( int i = 0; i < NUMNODES; i++ )
	{
		for ( int j = 0; j < NUMNODES; j++ )
		{
			cout << AdjMatrix[i][j] << "  ";
		}
		cout << endl;
	}
	cout << endl;
}

void Prog3Graph::depthFirstTraversal()
{
		cout << "Beginning Depth First Graph Traversal: \n\n";
		Stack *s = new Stack();		
		s->Push(Nodes[0].getNodeID());
		Nodes[0].setVisited(true);
		
		
		
		while (!s->isEmpty())
		{
			cout << "Current node ID = " << s->Peek() << endl;
			int nodeToVisit = s->Pop();
			getNeighbors(nodeToVisit, neighbors);
			cout << "Nodes in list: ";
			for (int i = 0; i < Nodes[getNode(nodeToVisit)].getNumberOfEdges(); i++)
			{
				
				if((!Nodes[getNode(neighbors[i])].hasBeenVisited()))
				{
					
					(Nodes[getNode(neighbors[i])].setVisited(true));
					s->Push(neighbors[i]);		
					
				}
			}
			s->print();
			cout << endl;
		}

		cout << "\nDepth First Traversal Complete\n\n";
}

//-------------------------------------------
// GetNextLine()
// Read the next line from the file.
// It is assumed the ifstream object, inFile,
//  is a private class member and that the
//  file has already been successfully opened.
//-------------------------------------------
bool Prog3Graph::getNextLine(char *line, int lineLen)
{
    int    done = false;

    while(!done)
    {
        inFile.getline(line, lineLen);
        
        if(inFile.good())    // If a line was successfully read
        {
           if(strlen(line) == 0)  // Skip any blank lines
                continue;
            else if(line[0] == '#')  // Skip any comment lines
                continue;
            else done = true;    // Got a valid data line so return with this line
        }
        else
        {
            strcpy(line, "");
            return false;    // Flag end of file with null string and return false
        }
    } // end while
    return true; // Flag successful read
}