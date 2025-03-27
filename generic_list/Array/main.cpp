#include "al.h"

int main() {
    AL<int> al;
    
    int c = 5;
    int p = c-c;

    for (int i = 0; i < c; i++){
        al.addLast(i);
    }

    try{
        for (int i = 0; i <= c; i++){
            printf("testing index %d: ",i);
            std::cout << al[i] << "\n";
        }
    } catch (std::out_of_range e) {
        std::cout << e.what() << "\n";
    }
    
    std::cout << al << "\n";
    return 0;
}