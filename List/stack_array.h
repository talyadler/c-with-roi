#pragma once
#include "stack.h"
#include "arraylist.h"

// LIFO = last in first out
class ArrayStack : public Stack {
public:
	ArrayStack();
	virtual ~ArrayStack();

	// adds the element `e` to the stack
	virtual void push(int e);

	// removes and returns the top element in the stack
	virtual int pop();

	// returns the top element in the stack without removing it
	virtual int peek();

private:
	ArrayList al;
};
