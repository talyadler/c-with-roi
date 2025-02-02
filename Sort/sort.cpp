#include <iostream>
#include <array>

int max (int const a[], int const l) {
    int max = a[0];
    for(int i = 1; i < l;i++){
        if (a[i] > max){
            max = a[i];
        }
    }
    return max;
}

int search(int const a[], int const v, int const l){
    for (int i = 0; i < l; i++){
        if (a[i] == v){
            return i;
        }
    }
    return -1;
}

int maxLimited(int a[], int l){
    int max = -2147483648;
    for (int i = 0; i < l; i++){
        if (max <= a[i]) max = a[i];
    }
    return max;
}

int sortedMax(int a[], int l){
    return a[l-1];
}

int sort(int& a, int l){
    int temp[l] = a[];
    return 0;
}

int main()
{
    int a[] = {7,2,10,15,9,3,7,8};
    int l = std::end(a) - std::begin(a);
    std::cout << "max value in arry is: " << max(a,l) << "\n";
    std::cout << "max value in index arry is: " << search(a, max(a,l), l) << "\n";

    return 0;
}
