#include "binarytree.h"

int main(){
    binarytree BT;

    // int tv[] = {10,5,11,90,3,8,7,2,6,-8,33,44};
    // int length = 12;

    // int tv[] = {1,-10,2,-20,-5,3,-17};
    // int length = 7;
    
    // int tv[] = {2,1,3};
    // int length = 3;

    // int tv[] = {10, 15, -8, 6, 11, 88, -4};
    // int length = 7;

    // int tv[] = {10, 9, 11, 8, 12};
    // int length = 5;

    // int tv[] = {1, 1, 2, 2, 2, 2, 2, 2};
    // int length = 8;

    int tv[] = {1, 2, 3, 4, 5, 6, 7, 8};
    int length = 8;
    
    // index in array for later use in other functions
    int c = 2;
    int a = 1;
    
    // insert
    for (int i = 0; i < length; i++){
        BT.insert(tv[i]);
    }
    
    /*
        START
    */
    // printf("%d items in tree\n",BT.length());
    // for (int i = 0; i < BT.length(); i++){
    //     BT.showinfo(tv[i]);
    // }
    // printf("-----------------------------------------------------\n");
    
    // // remove function
    // BT.remove(tv[c]);
    // printf("hi\n");
    // BT.search(tv[c],a);
    // BT.search(1000,2);
    // std::cout << BT.depth() << "\n";
    // //

    printf("%d items in tree\n",BT.length());
    for (int i = 0; i < BT.length(); i++){
        BT.showinfo(tv[i]);
    }
    // printf("-----------------------------------------------------\n");
    // BT.OrderShowInfo(1);
    // std::cout << "MAIN: min:" << BT.min() << "; max:" << BT.max() << "\n";
    // END
    return 0;
}
