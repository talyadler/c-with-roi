#pragma once
#include "linkedlist.h"
// #include "arraylist.h"

// FIFO = first in first out
class Queue {
public:
	Queue();
	~Queue();

	// adds new element `e` to the queue
	void enqueue(int e);

	// removes and returns the first element in the queue
	int dequeue();

	// returns the first element in the queue without removing it
	int peek();

private:
	LinkedList ll;
	// ArrayList al;
};

