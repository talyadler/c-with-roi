#include "arraylist.h"
#include "queue_array.h"
#include "stack_array.h"
#include <iostream>

int main (){
    ArrayQueue qal;
    ArrayStack sal;
    int alscope = 5;
    
    std::cout << "Adding " << alscope << " Items to QueueArray List" <<std::endl;
    for(int i = 1; i <= alscope; i++){
        qal.enqueue(i);
    }

    std::cout << "Peeking = " << qal.peek() << "\n" ;

    std::cout << "Dequeueing " << qal.dequeue() << "\n" ;

    std::cout << "Peeking = " << qal.peek() << "\n" ;

    std::cout << "Adding " << alscope << " Items to StackArray List" <<std::endl;
    for(int i = 1; i <= alscope; i++){
        sal.push(i);
        std::cout << sal.peek() << "\n";
    }

    std::cout << "Peeking = " << sal.peek() << "\n" ;

    std::cout << "Poping " << sal.pop() << "\n" ;

    std::cout << "Peeking = " << qal.peek() << "\n" ;
/*
    ArrayList al;
    std::cout << "Adding " << alscope << " Items to Array List" <<std::endl;
    for(int i = 1; i <= alscope; i++){
        al.addLast(i);
    }

    for (int i=1; i <= 3; i++){
        try{
            al.addLast(i*100);
            al.addAt(i*100, 3);
        }
        catch(...){
            std::cout << "exception in removefirst()\n";
        }
    }

    for(int i = -1; i <= al.length(); i++){
        try{
            std::cout << al.numAt(i) << std::endl;
        }
        catch(...){
            std::cout << "exception in index: " << i << "\n";
        }
    }

    try{
        std::cout << "First item on the array value " << al.numFirst() << std::endl;
        std::cout << "Last item on the array value " << al.numLast() << std::endl;
    }
    catch(...){
        std::cout << "exception in index: " << "\n";
    }

*/
    return 0;
}
