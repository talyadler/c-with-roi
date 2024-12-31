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
    al.addFirst(e); // O(n)
} // O(n)

// removes and returns the top element in the stack
int ArrayStack::pop(){
    int pop = al.numFirst(); // O(1)
    al.removeFirst(); // O(n)
    return pop;
} // O(n)

// returns the top element in the stack without removing it
int ArrayStack::peek(){
    return al.numFirst();
} // O(1)
