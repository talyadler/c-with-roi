#pragma once
#include "stack.h"
#include "queue.h"

class StackWithQueue : public Stack {
public:
	StackWithQueue(Queue* pQueue) : pQueue(pQueue) {}
	virtual ~StackWithQueue() { delete pQueue; }

	virtual void push(int e);
	virtual int pop();
	virtual int peek();
	virtual bool isEmpty();

private:
	Queue* pQueue;
};
