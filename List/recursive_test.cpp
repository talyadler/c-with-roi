#include "recursive_linkedlist.h"
#include <iostream>

int main (){
    RecursiveLinkedList rll;
    int scope = 8;
    for (int i = 1; i <= scope; i++){
        try{
            rll.add(i);
        }
        catch(...){std::cout << "cought error in add()";}
    }

    try{
    std::cout << "length is " << rll.length() << std::endl;
    }
    catch(...){std::cout << "error\n"; }

    for (int i = -1; i <= rll.length(); i++){
        try{
            std::cout << "numat " << i << " is " << rll.numAt(i) << std::endl;
        }
        catch(...){std::cout << "index out of bounds\n"; }
    }

    int test_addAt_index = 1;
    try{
        rll.addAt(test_addAt_index*10, test_addAt_index-1);
    }
    catch(...){std::cout << "index out of bounds\n";}
    for (int i = -1; i <= rll.length(); i++){
        try{
            std::cout << "numat " << i << " is " << rll.numAt(i) << std::endl;
        }
        catch(...){std::cout << "index out of bounds\n"; }
    }

}