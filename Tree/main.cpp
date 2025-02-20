#include "binarytree.h"

int main(){
    binarytree BT;
    int scope = 9;
    for (int i = 1; i <= scope; i++)BT.insert(i);
    printf("items in tree %d\n",BT.length());
    // BT.showinfoo();
    
    if (BT.contains(6)){
        printf("contains\n");
    }
    else {
        printf("dose not contain");
    }
    return 0;

}