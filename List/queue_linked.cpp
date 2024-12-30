#include "queue_linked.h"
#include <iostream>

/*
* CONSTRUCTORS
*/

LinkedQueue::LinkedQueue() : Queue() {}

/*
* DESTRUTORS
*/

LinkedQueue::~LinkedQueue() {}

/*
* USER METHODS
*/

// adds new element `e` to the queue
void LinkedQueue::enqueue(int e){
    ll.addLast(e);
}

// removes and returns the first element in the queue
int LinkedQueue::dequeue(){
    int deq = ll.numFirst();
    ll.removeFirst();
    return deq;
}

// returns the first element in the queue without removing it
int LinkedQueue::peek(){
    return ll.numFirst();
}