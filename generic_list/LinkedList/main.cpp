#include "ll.h"

template <typename T> void fillList(LinkedList<T>& ll, unsigned int c){
    for (int i = 0; i < c; i++){
        ll.addLast(i);
    }
    std::cout << "length: " << ll.length() << "\n";
}

void ll_addAt_test(unsigned int c){
    std::cout << "ll_addAt_test start" << std::endl;
    LinkedList<int> ll;
    printf("fill ll with %d items\n",c);
    fillList(ll, c);
    std::cout << ll << std::endl;
    ll.addAt(9999,c-1);
    std::cout << ll << std::endl;
    std::cout << "ll_addAt_test end" << std::endl;
    std::cout << "--------------------------------------" << std::endl;
}

void ll_operator_eq_test(unsigned int c){
    LinkedList<int> ll1;
    LinkedList<int> ll2;
    std::cout << "ll_operator_eq_test start" << std::endl;
    try {
        printf("print ll1\n");
        std::cout << ll1 << std::endl;
    }catch(std::out_of_range e){
        std::cout << e.what() << "\n";
    }

    try {
        printf("print ll2\n");
        std::cout << ll2 << std::endl;
    }catch(std::out_of_range e){
        std::cout << e.what() << "\n";
    }
    
    printf("\nfill ll1 with %d items\n",c);
    fillList(ll1,5);

    try {
        printf("print ll1\n");
        std::cout << ll1 << std::endl;
    }catch(std::out_of_range e){
        std::cout << e.what() << "\n";
    }

    try {
        printf("print ll2\n");
        std::cout << ll2 << std::endl;
    }catch(std::out_of_range e){
        std::cout << e.what() << "\n";
    }

    printf("\nusing =\n",c);
    try {
        ll2 = ll1;
    }catch(std::out_of_range e){
        std::cout << e.what() << "\n";
    }

    try {
        printf("print ll1\n");
        std::cout << ll1 << std::endl;
    }catch(std::out_of_range e){
        std::cout << e.what() << "\n";
    }

    try {
        printf("print ll2\n");
        std::cout << ll2 << std::endl;
    }catch(std::out_of_range e){
        std::cout << e.what() << "\n";
    }
    std::cout << "ll_operator_eq_test end" << std::endl;
    std::cout << "--------------------------------------" << std::endl;
}

void ll_operator_bracers_test(unsigned int c){
    LinkedList<int> ll;
    fillList(ll,c);
    int p = c-1;
    ll[p]=999;
    std::cout << "value at index " << p << ": " << ll[p] <<"\n";
}

void ll_operator_eq_eq_test(unsigned int c){
    printf("\ntesting operator ==\n",c);
    LinkedList<int> ll1;
    LinkedList<int> ll2;

    printf("\nll1 5 items\tll2 6 items\n",c);
    fillList(ll1,5);
    fillList(ll2,6);

    if (ll2 == ll1) {
        printf("true\n");
    }else{
        printf("false\n");
    }

    printf("\nremove ll2 last\n",c);
    ll2.removeLast();

    if (ll2 == ll1) {
        printf("true\n");
    }else{
        printf("false\n");
    }

    printf("\nchange value in ll1\n",c);
    ll1[2] = 999;

    if (ll2 == ll1) {
        printf("true\n");
    }else{
        printf("false\n");
    }
}

int main(){
    // for (int i = 0; i < 5; i++){
    //     try {
    //         ll_addAt_test(i);
    //     }catch(std::out_of_range e){
    //         std::cout << e.what() << "\n";
    //     }
    // }
    
    try {
        ll_operator_eq_eq_test(5);
    }catch(std::out_of_range e){
        std::cout << e.what() << "\n";
    }

/*
    // ll_operator_eq_test(5);

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
*/
    return 0;

}

