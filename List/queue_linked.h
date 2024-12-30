#pragma once
#include "linkedlist.h"
#include "arraylist.h"

// FIFO = first in first out
class Queue {
public:
	Queue();
	virtual ~Queue();

	// adds new element `e` to the queue
	virtual void enqueue(int e) =0;

	// removes and returns the first element in the queue
	virtual int dequeue() =0;

	// returns the first element in the queue without removing it
	virtual int peek() =0;

private:
	LinkedList ll;
	ArrayList al;
};

