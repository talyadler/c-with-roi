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

    try{
        std::cout << "numat 5 is " << rll.numAt(7) << std::endl;
    }
    catch(...){std::cout << "index out of bounds\n"; }
}