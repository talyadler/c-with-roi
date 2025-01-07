#include "queue_linked.h"
#include <iostream>

/*
* CONSTRUCTORS
*/

LinkedQueue::LinkedQueue() : Queue() {}

/*
* DESTRUTORS
*/

LinkedQueue::~LinkedQueue() {
    while (!ll.isEmpty()) dequeue(); // O(1)
}

/*
* USER METHODS
*/

// adds new element `e` to the queue
void LinkedQueue::enqueue(int e){
    ll.addLast(e); // O(1)
} // O(1)

// removes and returns the first element in the queue
int LinkedQueue::dequeue(){
    int deq = ll.numFirst(); // O(1)
    ll.removeFirst(); // O(1)
    return deq;
} // O(1)

// returns the first element in the queue without removing it
int LinkedQueue::peek(){
    return ll.numFirst(); // O(1)
} // O(1)

// return bool on empty list
bool LinkedQueue::isEmpty(){
    return ll.isEmpty(); // O(1)
}