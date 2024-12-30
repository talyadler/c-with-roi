#include "stack_linked.h"
#include <iostream>

/*
* CONSTRUCTORS
*/

LinkedStack::LinkedStack() : Stack() {
    ll;
}

/*
* DESTRUTORS
*/

LinkedStack::~LinkedStack() {
    while (!ll.isEmpty()) pop();
}

/*
* USER METHODS
*/

// adds the element `e` to the stack
void LinkedStack::push(int e){
    ll.addFirst(e);
}

// removes and returns the top element in the stack
int LinkedStack::pop(){
    int pop = ll.numFirst();
    ll.removeFirst();
    return pop;
}

// returns the top element in the stack without removing it
int LinkedStack::peek(){
    return ll.numFirst();
}
