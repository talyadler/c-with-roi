#include <iostream>

int max (int const a[], int const l);

int min (int const a[], int const l);

int search(int const a[], int const v, int const l);

void sort(int a[], int l);

void print(int a[], int l);

int main()
{
    int a[] = {300,-7,2,10,15,9,-3,7,8};
    int size = 9;
    std::cout << "print array:\n";
    print(a,size);
    std::cout << "max of array is \t" << max(a,size) << "\n";
    std::cout << "min of array is \t" << min(a,size) << "\n";
    std::cout << "position of max  is \t" << search(a,max(a,size),size) << "\n";
    std::cout << "position of min  is \t" << search(a,min(a,size),size) << "\n";
    std::cout << "start sort\n";
    sort(a,size);
    print(a,size);
    std::cout << "position of max  is \t" << search(a,max(a,size),size) << "\n";
    std::cout << "position of min  is \t" << search(a,min(a,size),size) << "\n";
    return 0;
}

int max (int const a[], int const l) {
    if (l <= 0) return -1;
    int max = a[0];
    for(int i = 1; i < l; i++){
        if (a[i] > max){
            max = a[i];
        }
    }
    return max;
}

int min (int const a[], int const l){
    if (l <= 0) return -1;
    int min = a[0];
    for(int i = 1; i < l; i++){
        if (a[i] < min){
            min = a[i];
        }
    }
    return min;
}

int search(int const a[], int const v, int const l){
    for (int i = 0; i < l; i++){
        if (a[i] == v){
            return i;
        }
    }
    return -1;
}

void sort(int a[], int l){
    int temp[l];
    for (int i = 0; i < l; i++)temp[i] = a[i];
    
    temp[l-1] = max(a,l);
    a[search(a,max(a,l),l)] = min(a,l);
    for (int i = l -2; i >= 0 ; i--){
        temp[i] = max(a,l);
        a[search(a,max(a,l),l)] = min(a,l);
    }
    for (int i = 0; i < l; i++){
        a[i] = temp[i];
    }
}

void print(int a[], int l){
        for (int i = 0; i < l; i++){
            std::cout << a[i]<<" ";
        }
    std::cout << "\n";
}