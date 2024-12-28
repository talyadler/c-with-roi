#include "linkedlist.h"
#include "stack.h"
#include "queue.h"
#include <iostream>

int main (){
    Stack q;

    int llqscope = 5;
    std::cout << "Adding " << llqscope << " Items to Queued List" <<std::endl;
    for (int i = 1; i <= llqscope; i++){
        q.push(i);
    }

    std::cout << "Front: " << q.peek() << std::endl;
    q.pop();
    std::cout << "Front: " << q.peek() << std::endl;

/*
    std::cout << "Testing numAt(index)\n";
    for (int i = -1; i <=llscope; i++){
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
}
