#include "arraylist.h"
#include "linkedlist.h"
#include <iostream>

int main (){
    LinkedList ll;
	ArrayList al;

// linked list testing
    int __llscope = 2;
    std::cout << "Adding " << __llscope << " Items to Linked List" <<std::endl;
    for (int i = 1; i <= __llscope; i++){
        ll.add(i);
    }
    std::cout << "Testing numAt(index)\n";
    for (int i = -1; i <=__llscope; i++){
        try{
            ll.numAt(i);
        }
        catch(...){
            std::cout << "\tFound exception\n"; 
        }
    }
    
    std::cout << "\nTesting length()" <<std::endl;
    std::cout << ll.length() << std::endl;

    std::cout << "\nTesting remove()" <<std::endl;
    ll.remove();
    
    for (int i = -1; i <= __llscope; i++){
        try{
            std::cout << "Testing numAt(index) " << i <<std::endl;
            ll.numAt(i);
        }
        catch(...){
            std::cout << "\tFound exception\n"; 
        }
    }
    
    std::cout << "Is ll empty? " << ll.isEmpty() << std::endl;

    std::cout << std::endl << std::endl;

// array list testing
    int __alscope = 2;
    std::cout << "Adding " << __alscope << " Items to Array List" <<std::endl;
  
    for(int i = 1; i <= __alscope; i++){
        al.add(i);
    }
    

    for(int i = -1; i <= __alscope; i++){
        try{
            std::cout << al.numAt(i) << std::endl;
        }
        catch(...){
            std::cout << "exception in index: " << i << "\n";
        }
    }

    std::cout << "\nTesting remove()\n";
    al.remove();

    std::cout << "Length is: " << al.length() << std::endl;

    std::cout << "\nTesting isEmpty()\n";
    std::cout << "Is al empty? " << al.isEmpty() << std::endl;

    return 0;
}