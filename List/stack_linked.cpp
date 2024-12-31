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
    while (!ll.isEmpty()) pop(); // O(1)
} // O()

/*
* USER METHODS
*/

// adds the element `e` to the stack
void LinkedStack::push(int e){
    ll.addFirst(e); // O(1)
} // O(1)

// removes and returns the top element in the stack
int LinkedStack::pop(){
    int pop = ll.numFirst(); // O(1)
    ll.removeFirst(); // O(1)
    return pop;
} // O(1)

// returns the top element in the stack without removing it
int LinkedStack::peek(){
    return ll.numFirst(); // O(1)
} // O(1)
