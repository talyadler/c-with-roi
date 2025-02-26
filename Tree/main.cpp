#include "binarytree.h"

int main(){
    binarytree BT;

    // int tv[] = {10,5,11,90,3,8,7,2,6,-8,33,44};
    // int length = 12;
    
    // int tv[] = {2,1,3};
    // int length = 3;

    int tv[] = {10, 15, -8, 6, 11, 88, -4};
    int length = 7;

    // int tv[] = {10, 9, 11, 8, 12};
    // int length = 5;

    for (int i = 0; i < length; i++){
        BT.insert(tv[i]);
    }
    printf("-----------------------------------------------------\n");
    
    for (int i = 0; i < BT.length(); i++){
        BT.showinfo(tv[i]);
    }
    printf("-----------------------------------------------------\n");

    printf("items in tree %d\n",BT.length());

    BT.remove(tv[0]);

    // BT.showinfoo();
    printf("items in tree %d\n",BT.length());
    printf("-----------------------------------------------------\n");
    
    for (int i = 0; i < BT.length(); i++){
        BT.showinfo(tv[i+1]);
    }

    // std::cout<< BT.depth()<<"\n";    
    
    // if (BT.contains(1000)){
    //     printf("contains\n");
    // }
    // else {
    //     printf("dose not contain\n");
    // }
    
    return 0;
}
