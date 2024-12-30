#include "queue_array.h"
#include <iostream>

/*
* CONSTRUCTORS
*/

ArrayQueue::ArrayQueue() : Queue() {}

/*
* DESTRUTORS
*/

ArrayQueue::~ArrayQueue() {}

/*
* USER METHODS
*/

// adds new element `e` to the queue
void ArrayQueue::enqueue(int e){
    al.addLast(e);
}

// removes and returns the first element in the queue
int ArrayQueue::dequeue(){
    int deq = al.numFirst();
    al.removeFirst();
    return deq;
}

// returns the first element in the queue without removing it
int ArrayQueue::peek(){
    return al.numFirst();
}