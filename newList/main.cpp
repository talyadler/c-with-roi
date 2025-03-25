#include "ll.h"

int main(){
    LinkedList<int> ll;

    std::cout << ll << "\n";

    int c = 3;
    for (int i = 0; i < c; i++){
        ll.addLast(i);
    }

    std::cout << ll << "\n";
}
