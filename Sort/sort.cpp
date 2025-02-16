#include <iostream>

int max (int const a[], int const l);

int search(int const a[], int const v, int const l);

int maxLimited(int a[], int l);

int sortedMax(int a[], int l);

int sort(int& a, int l);

int main()
{
    int a[] = {7,2,10,15,9,3,7,8};
    int size = sizeof(a)/sizeof(a[0]);
    std::cout << "size of array is \t" << size << "\n";
    std::cout << "max of array is \t" << max(a,size) << "\n";
    std::cout << "position of max  is \t" << search(a,max(a,size),size) << "\n";
    return 0;
}

int sortedMax(int a[], int l){
    return a[l-1];
}

int maxLimited(int a[], int l){
    if (l <= 0) return -1;
    int max = -2147483648;
    for (int i = 0; i < l; i++){
        if (max <= a[i]) max = a[i];
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

int max (int const a[], int const l) {
    if (l <= 0) return -1;
    int max = a[0];
    for(int i = 1; i < l;i++){
        if (a[i] > max){
            max = a[i];
        }
    }
    return max;
}

int sort(int a[], int l){
    int temp[l] = a;
    temp[l-1] = max(a,l);
    for (int i = l -2; i>0 ;i--){
        temp[i] = maxLimited(a,temp[i+1]);
    }
    return 0;
}
