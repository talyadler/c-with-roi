#pragma once
#include "stack.h"
#include "linkedlist.h"

// LIFO = last in first out
class LinkedStack : public Stack {
public:
	LinkedStack();
	virtual ~LinkedStack();

	// adds the element `e` to the stack
	virtual void push(int e);

	// removes and returns the top element in the stack
	virtual int pop();

	// returns the top element in the stack without removing it
	virtual int peek();

	// return bool on empty list
	virtual bool isEmpty();

private:
	LinkedList ll;
};
