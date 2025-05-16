#include "FIRST.h"
#include <iostream>

void func(unsigned counter){
    FIRST<int> one;
    for (int i = 1; i <= counter; i++){
        one.add(i);
    }
    one.show();
}

int main(){
    func(5);
    return 0;
}