#include <iostream>

int max (int a[]){
    int max = a[0];
    for(int i = 1; i < 8;i++){
        if (a[i] > max){
            max = a[i];
        }
    }
    return max;
}

int search(int a, int v){
    for (int i = 0; i < 8; i++){
        if (a[i] == v){
            return i;
        }
    }
    return -1;
}

int main()
{
    int a[] = {7,2,10,15,9,3,7,8};
    std::cout << max(a) << "\n";
    return 0;
}
