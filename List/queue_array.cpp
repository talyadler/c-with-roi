#include "queue_array.h"
#include <iostream>

/*
* CONSTRUCTORS
*/

ArrayQueue::ArrayQueue() : Queue() {
    al;
}

/*
* DESTRUTORS
*/

ArrayQueue::~ArrayQueue() {
    while (!al.isEmpty()) al.removeLast();
}

/*
* USER METHODS
*/

// adds new element `e` to the queue
void ArrayQueue::enqueue(int e){
    al.addLast(e); // O(n)
} // O(n)

// removes and returns the first element in the queue
int ArrayQueue::dequeue(){
    int deq = al.numFirst(); // O(1)
    al.removeFirst(); // O(n)
    return deq;
} // O(n)

// returns the first element in the queue without removing it
int ArrayQueue::peek(){
    return al.numFirst();
} // O(1)

// return bool on empty list
bool ArrayQueue::isEmpty(){
    return al.isEmpty(); // O(1)
}