#include "stack_linked.h"
#include <iostream>

/*
* CONSTRUCTORS
*/

Stack::Stack() {}

/*
* DESTRUTORS
*/

Stack::~Stack() {}

/*
* USER METHODS
*/

// adds the element `e` to the stack
void Stack::push(int e){
    ll.addFirst(e);
}

// removes and returns the top element in the stack
int Stack::pop(){
    int pop = ll.numFirst();
    ll.removeFirst();
    return pop;
}

// returns the top element in the stack without removing it
int Stack::peek(){
    return ll.numFirst();
}
