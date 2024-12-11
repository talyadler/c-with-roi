#include "recursive_linkedlist.h"
#include <iostream>

int main (){
    RecursiveLinkedList rll;
    int scope = 8;
    for (int i = 1; i <= scope; i++){
        // std:: cout << "creating link " << i << std::endl;
        rll.add(i);
    }

    std::cout << rll.length() << std::endl;
}