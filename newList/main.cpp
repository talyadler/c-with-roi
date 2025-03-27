#include "ll.h"

int main(){
    LinkedList<int> ll;

    std::cout << ll << "\n";

    int c = 5;
    int p = c-2;
    for (int i = 0; i < c; i++){
        ll.addLast(i);
        printf("%d ", i);
    }

    std::cout << "\n" << ll << "\nlength: " << ll.length() << "\n";

    // std::cout << ((ll.getByValue(1)) ? "true": "false") << "\n";

    try {
        std::cout << "value at index " << p << ": " << ll.valueAt(p) <<"\n";
    } catch(...){
        printf("failed\n");
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

    return 0;
}
