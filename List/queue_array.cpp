#include "queue.h"
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
    al.addLast(e);
}

// removes and returns the first element in the queue
int Queue::dequeue(){
    int deq = al.numFirst();
    al.removeFirst();
    return deq;
}

// returns the first element in the queue without removing it
int Queue::peek(){
    return al.numFirst();
}