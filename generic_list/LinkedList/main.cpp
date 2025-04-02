#include "ll.h"


void ll_addAt_test1(){
    std::cout << "ll_addAt_test1 start" << std::endl;
    LinkedList<int> ll;
    ll.addLast(5);
    ll.addLast(6);
    std::cout << ll << std::endl;
    ll.addAt(9,1);
    std::cout << ll << std::endl;
    std::cout << "ll_addAt_test1 end" << std::endl;
}


int main(){
    ll_addAt_test1();
}
    /*
    std::cout << ll << "\n";

    int c = 5;
    int p = c-c;
    for (int i = 0; i < c; i++){
        ll.addLast(i);
        printf("%d ", i);
    }

    std::cout << "\n" << ll << "\nlength: " << ll.length() << "\n";

    std::cout << "is there 1 value in linkedlist? " << ((ll.getByValue(1)) ? "true": "false") << "\n";

    try {
        ll[p]=100;
        std::cout << "value at index " << p << ": " << ll[p] <<"\n";
        
    } catch(std::out_of_range e){
        std::cout << e.what() << "\n";
    }

    try {
        std::cout << "max value :" << ll.max() <<"\n";
    } catch(...){
        printf("failed\n");
    }

    try {
        std::cout << "min value :" << ll.min() <<"\n";
    } catch(...){
        printf("failed\n");
    }

    try {
        std::cout << "sum value :" << ll.sum() <<"\n";
    } catch(...){
        printf("failed\n");
    }

    try {
        std::cout << "replace first value: " << ll.valueFirst() << " with 100" << "\n";
        ll.replaceFirst(100);
        std::cout << "first value: " << ll.valueFirst() << "\n";
    } catch(...){
        printf("failed\n");
    }

    try {
        std::cout << "replace last value: " << ll.valueLast() << " with 200" << "\n";
        ll.replaceLast(200);
        std::cout << "last value: " << ll.valueLast() << "\n";
    } catch(...){
        printf("failed\n");
    }

    try {
        std::cout << "replace value at index 2: " << ll.valueAt(2) << " with 300" << "\n";
        ll.replaceAt(300, 2);
        std::cout << "value at index 2: " << ll.valueAt(2) << "\n";
    } catch(...){
        printf("failed\n");
    }

    std::cout << "is there 2 value in linkedlist? " << ((ll.getByValue(2)) ? "true": "false") << "\n";
    std::cout << ll << "\nlength: " << ll.length() << "\n";

    return 0;
}
*/
