#include "binarytree.h"

int main(){
    binarytree BT;
    // int tv[] = {10,5,11,90,3,8,7,2,6,-8,33,44};
    // int length = 12;
    
    // int tv[] = {2,1,3};
    // int length = 3;

    int tv[] = {0, 1};
    int length = 2;
    // int scope = 4;
    for (int i = 0; i < length; i++){
        BT.insert(tv[i]);
        // printf("inserted %d\n",tv[i]);
    }
    // BT.showinfoo();
    printf("items in tree %d\n",BT.length());
    BT.showinfoo();
    
    // if (BT.contains(6)){
    //     printf("contains\n");
    // }
    // else {
    //     printf("dose not contain");
    // }
    return 0;

}
