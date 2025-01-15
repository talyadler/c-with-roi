#include <iostream>
#include "linkedlist.h"

int main () {
    LinkedList ll;
    int scope = 6;
    
    for (int i = 1; i <= scope; i++){
        try{
            ll.addLast(i);
        }
        catch(...){
            std::cout << "Error to Add\n";
        }
    }
    for (int element : ll){
        std::cout << element << ", ";
    }
    std::cout << std::endl;
}