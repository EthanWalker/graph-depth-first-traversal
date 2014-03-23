/*******************************************************************
*   File: Stack.cpp												   * 
*   Name: James Walker (Ethan)									   *
*   Project: Programming Assignment 3: Graph Depth First Traversal *
*   Creation Date: 11/20/2013									   *
*   Purpose: CPP file for a stack class 						   *
*   															   *
*******************************************************************/

#include <iostream>
#include "Stack.h"

//--------------------------------------------
// Function: Stack()						 *
// Purpose: Class Constructor				 *
// Returns: void							 *
//--------------------------------------------
	Stack::Stack()
	{
		size = 0;
	}

//--------------------------------------------
// Function: ~Stack()						 *
// Purpose: Class Deonstructor				 *
// Returns: void							 *
//--------------------------------------------
	Stack::~Stack()
	{
	
	}
//--------------------------------------------
// Function: Push()							 *
// Purpose: Lets us push onto the stack		 *
// Returns: void							 *
//--------------------------------------------
	void Stack::Push(int ID)
	{
		nodeIDs[size] = ID;
		size++;
	}

//--------------------------------------------
// Function: Pop()							 *
// Purpose: Lets us pop off of the stack	 *
// Returns: int								 *
//--------------------------------------------
	int Stack::Pop()
	{
		size--;
		return nodeIDs[size];
	}

//--------------------------------------------
// Function: Peek()							 *
// Purpose: Shows top stack item			 *
// Returns: int								 *
//--------------------------------------------
	int Stack::Peek()
	{
		if(size > 0)
			return nodeIDs[size-1];
		else
			return NULL;
	}
//--------------------------------------------
// Function: isEmpty()						 *
// Purpose: Returns TRUE if stack is empty	 *
// Returns: bool							 *
//--------------------------------------------	
	bool Stack::isEmpty()
	{
		return !(bool)size;
	}
	
	void Stack::print() 
	{
		for(int i = (size - 1); i >= 0 ; i --)
		{
        std::cout << nodeIDs[i] << " ";    
		}
	}