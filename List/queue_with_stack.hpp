#pragma once
#include "queue.h"
#include "stack.h"

class QueueWithStack : public Queue {
public:
	QueueWithStack(Stack* pStack) : pStack(pStack) {}
	virtual ~QueueWithStack() { delete pStack; }

	virtual void enqueue(int e);
	virtual int dequeue();
	virtual int peek();
	virtual bool isEmpty();

private:
	Stack* pStack;
};

