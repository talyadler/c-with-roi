#include "ll.h"

int main(){
    LinkedList<int> ll;

    std::cout << ll << "\n";

    int c = 100;
    for (int i = 0; i < c; i++){
        ll.addLast(i);
    }

    std::cout << ll << "\n";
}
