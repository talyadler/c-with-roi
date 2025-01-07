#include "stack_array.h"
#include <iostream>

/*
* CONSTRUCTORS
*/

ArrayStack::ArrayStack() : Stack() {
    al;
}

/*
* DESTRUTORS
*/

ArrayStack::~ArrayStack() {
    while (!al.isEmpty()) al.removeLast();
} // O(1)

/*
* USER METHODS
*/

// adds the element `e` to the stack
void ArrayStack::push(int e){
    al.addLast(e); // O(1) amortized
} // O(1) amortized

// removes and returns the top element in the stack
int ArrayStack::pop(){
    int pop = al.numLast(); // O(1)
    al.removeLast(); // O(1)
    return pop;
} // O(1)

// returns the top element in the stack without removing it
int ArrayStack::peek(){
    return al.numLast(); // O(1)
} // O(1)

// return bool on empty list
bool ArrayStack::isEmpty(){
    return al.isEmpty(); // O(1)
}
