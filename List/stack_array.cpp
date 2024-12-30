#include "stack_array.h"
#include <iostream>

/*
* CONSTRUCTORS
*/

ArrayStack::ArrayStack() :Stack() {}

/*
* DESTRUTORS
*/

ArrayStack::~ArrayStack() {}

/*
* USER METHODS
*/

// adds the element `e` to the stack
void ArrayStack::push(int e){
    al.addFirst(e);
}

// removes and returns the top element in the stack
int ArrayStack::pop(){
    int pop = al.numFirst();
    al.removeFirst();
    return pop;
}

// returns the top element in the stack without removing it
int ArrayStack::peek(){
    return al.numFirst();
}
