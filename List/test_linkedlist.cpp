#include "linkedlist.h"
#include "stack_linked.h"
#include "queue_linked.h"
#include "queue_with_stack.hpp"
#include <iostream>

int main (){
    QueueWithStack qws(new LinkedStack());

    qws.enqueue(1);
    std::cout << "peeking at first " << qws.peek() << "\n" ;
    qws.enqueue(2);
    std::cout << "peeking at second " << qws.peek() << "\n" ;

    /*
    LinkedQueue qll;
    LinkedStack sll;
    int llscope = 5;
    
    std::cout << "\nThis is the LinkedList tests\n";
    std::cout << "Adding " << llscope << " Items to QueueLinked List" <<std::endl;
    try{
        for(int i = 1; i <= llscope; i++){
            std::cout << "Enqueueing " << i << " and is at the end if the QueueLinkedList\n";
            qll.enqueue(i);
        }
        std::cout << "Peeking = " << qll.peek() << "\n" ;
        for(int i = 1; i <= llscope; i++){
            std::cout << "Dequeueing " << qll.dequeue() << "\n" ;
        }
        std::cout << "Peeking = " << qll.peek() << "\n" ;
        std::cout << "Dequeueing " << qll.dequeue() << "\n" ;
        std::cout << "Peeking = " << qll.peek() << "\n" ;
    }
    catch(...){
        std::cout << "Failed";
    }
    
    std::cout << "\n\nAdding " << llscope << " Items to StackLinked List" <<std::endl;
    try{
        for(int i = 1; i <= llscope; i++){
            std::cout << "pushing " << i << " and is at the start if the StackLinkedlist\n";
            sll.push(i);
        }
        std::cout << "Peeking = " << sll.peek() << "\n" ;
        for(int i = 1; i <= llscope; i++){
            std::cout << "Poping " << sll.pop() << "\n" ;
        }
        std::cout << "Poping " << sll.pop() << "\n" ;
        std::cout << "Peeking = " << sll.peek() << "\n" ;
    }
    catch(...){
            std::cout << "Failed \n";
    }

/*
    int llqscope = 5;
    std::cout << "Adding " << llqscope << " Items to Queued List" <<std::endl;
    for (int i = 1; i <= llqscope; i++){
        q.push(i);
    }

    std::cout << "Front: " << q.peek() << std::endl;
    q.pop();
    std::cout << "Front: " << q.peek() << std::endl;

    int llscope = 4;
    std::cout << "Adding " << llscope << " Items to Linked List\n" <<std::endl;
    for (int i = 1; i <= llscope; i++){
        try{
                ll.addLast(i);
                // std::cout << i << "\n";
                // std::cout << "length is: " << ll.length() << "\n";
            }
        catch(...){
            std::cout << "yo" << i << "\n";
        }
    }

    for (int i = 0; i <= llscope; i++){
        try{
            ll.addAt(i*100, i+1);
        }
        catch(...){
            std::cout << "bad input\n";
        }
    }


    std::cout << "~~~~~Testing numAt(index)~~~~~\n";
    for (int i = -1; i <=ll.length(); i++){
        try{
            std::cout << "numAt(" << i << ") is: " << ll.numAt(i) << "\n\n";
            // ll.numLast();
        }
        catch(...){
            std::cout << "\tFound exception in numAt(" << i << ")\n"; 
        }
    }
    
    std::cout << "\nTesting length()" <<std::endl;
    std::cout << ll.length() << std::endl;

    std::cout << "\nTesting removeLast()" <<std::endl;
    try {
        ll.removeAt(ll.length()-1);
    }
    catch(...){
        std::cout << "error\n";
    }

    for (int i = -1; i <= llscope; i++){
        try{
            std::cout << "numAt(" << i << ") is: " << ll.numAt(i) << "\n\n";
        }
        catch(...){
            std::cout << "\tFound exception\n"; 
        }
    }

    std::cout << "\nTesting length()" <<std::endl;
    std::cout << ll.length() << std::endl;
    
/*
    std::cout << "Is ll empty? " << ll.isEmpty() << std::endl;

    std::cout << "Testing addAt(2)\n";
    int counter = llscope;
    try{
        ll.addAt(100, 2);
    }
    catch(...){
        std::cout << "\tFound addAt() exception\n"; 
    }
    while(counter >= 0){
        try{
            try{
                std::cout << ll.numAt(counter) << std::endl;
            }
            catch(...){
                std::cout << "\tFound exception\n"; 
            }
            counter --;
        }
        catch(...){
            std::cout << "\tFound exception\n"; 
        }
    }

    int testtt = 5;
    try{
        std::cout << "Testin addAt(" << testtt<<")\n";
        ll.addAt((testtt+1)*100,testtt);
    }
    catch(...){
        std::cout << "\tFound removeAt(" << testtt<<") exception\n"; 
    }
    for (int i = 0; i < ll.length(); i++){
    try{
            std::cout << "Testing numAt(index) " << i << "= " << ll.numAt(i)<<std::endl;
            
        }
    catch(...){
            std::cout << "Found numAt(" << i <<") exception\n"; 
        }
    }

    try{
        std::cout << "Testin removeAt(1)\n";
        ll.removeAt(1);
    }
    catch(...){
        std::cout << "\tFound removeAt(0) exception\n"; 
    }
    for (int i = -1; i <= llscope; i++){
    try{
            std::cout << "Testing numAt(index) " << i << "= " << ll.numAt(i)<<std::endl;
            
        }
    catch(...){
            std::cout << "Found numAt(" << i <<") exception\n"; 
        }
    }
    std::cout << std::endl << std::endl;
*/
    return 0;
}
