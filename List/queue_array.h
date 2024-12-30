#pragma once
#include "queue.h"
#include "arraylist.h"

// FIFO = first in first out
class Queue {
public:
	Queue();
	virtual ~Queue();

	// adds new element `e` to the queue
	virtual void enqueue(int e);

	// removes and returns the first element in the queue
	virtual int dequeue();

	// returns the first element in the queue without removing it
	virtual int peek();

private:
	ArrayList al;
};

