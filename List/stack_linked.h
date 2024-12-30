#pragma once
#include "linkedlist.h"

// LIFO = last in first out
class Stack {
public:
	Stack();
	virtual ~Stack();

	// adds the element `e` to the stack
	virtual void push(int e);

	// removes and returns the top element in the stack
	virtual int pop();

	// returns the top element in the stack without removing it
	virtual int peek();

private:
	LinkedList ll;
};
