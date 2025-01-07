#include <iostream>
#include "queue_with_stack.hpp"

// FIFO using FILO

void QueueWithStack::enqueue(int e){
    // we need to somehow insert new item at the LAST position
    if (pStack->isEmpty()) {
        pStack->push(e); // put e at first position and is at last position
        return;
    }
}

int QueueWithStack::dequeue(){
    return 0;
}

int QueueWithStack::peek(){
    return pStack->peek();
}

bool QueueWithStack::isEmpty(){
    return pStack->isEmpty();
}