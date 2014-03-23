/*******************************************************************
*   File: Stack.h												   * 
*   Name: James Walker (Ethan)									   *
*   Project: Programming Assignment 3: Graph Depth First Traversal *
*   Creation Date: 11/20/2013									   *
*   Purpose: Header file for a stack class 						   *
*   															   *
*******************************************************************/
#ifndef STACK_H
#define STACK_H

class Stack
{
private:
	int nodeIDs[10];	// Array to old ID #s of our nodes
	int size;			// Size of array to be used as index for where to push/pop IDs 
public:
	Stack();			
	~Stack();

	void Push(int ID);
	int Pop();
	int Peek();
	bool isEmpty();
	void print();
};
#endif