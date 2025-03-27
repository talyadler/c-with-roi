#include "al.h"

int main() {
    AL<int> al;
    
    int c = 5;
    int p = c-c;

    printf("adding %d items to array\n", c);

    for (int i = 0; i < c; i++){
        al.addLast(i);
    }

    printf("\ntesting operator []\n", c);
    try{
        for (int i = 0; i <= c; i++){
            printf("\ttesting index %d: ",i);
            std::cout << al[i] << "\n";
        }
    } catch (std::out_of_range e) {
        std::cout << e.what() << "\n";
    }
    
    printf("\ntesting operator <<\n", c);
    std::cout << "\t" << al << "\n";
    return 0;
}