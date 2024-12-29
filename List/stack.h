#pragma once
#include "linkedlist.h"
#include "arraylist.h"

// LIFO = last in first out
class Stack {
public:
	Stack();
	~Stack();

	// adds the element `e` to the stack
	void push(int e);

	// removes and returns the top element in the stack
	virtual int pop();

	// returns the top element in the stack without removing it
	int peek();

private:
	LinkedList ll;
	ArrayList al;
};
