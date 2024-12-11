#include "recursive_linkedlist.h"
#include <iostream>

int main (){
    RecursiveLinkedList rll;
    int scope = 8;
    for (int i = 1; i <= scope; i++){
        // std:: cout << "creating link " << i << std::endl;
        rll.add(i);
    }

    try{
    std::cout << "length is " << rll.length() << std::endl;
    }
    catch(...){std::cout << "error\n"; }

    for (int i = -1; i <= rll.length(); i++){
        try{
            // int test = 4;
            std::cout << "numat " << i << " is " << rll.numAt(i) << std::endl;
        }
        catch(...){std::cout << "index out of bounds\n"; }
    }
}