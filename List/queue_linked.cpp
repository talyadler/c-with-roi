#include "queue_linked.h"
#include <iostream>

/*
* CONSTRUCTORS
*/

Queue::Queue() {}

/*
* DESTRUTORS
*/

Queue::~Queue() {}

/*
* USER METHODS
*/

// adds new element `e` to the queue
void Queue::enqueue(int e){
    ll.addLast(e);
}

// removes and returns the first element in the queue
int Queue::dequeue(){
    int deq = ll.numFirst();
    ll.removeFirst();
    return deq;
}

// returns the first element in the queue without removing it
int Queue::peek(){
    return ll.numFirst();
}