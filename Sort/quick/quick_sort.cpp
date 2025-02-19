#include <iostream>

void quicksort(int a[], int length);

void quicksort_recursion(int a[], int low_index, int high_index);

int partition_index(int a[], int low_index, int high_index);

void swap(int& x, int& y);

void print(int a[], int length);

int main(){
    int a[] = {-5,-8,5,9,88,71,3,100,3};
    int length = 9;
    
    std::cout << "original array\n";
    print(a,length);

    quicksort(a,length);
    std::cout << "quick sorted array\n";
    print(a,length);
    
    return 0;
}

void quicksort(int a[], int length){
    quicksort_recursion(a, 0, length - 1);
}

void quicksort_recursion(int a[], int low_index, int high_index){
    if (low_index<high_index){
        int pivot_index = partition_index(a,low_index,high_index);
        quicksort_recursion(a, low_index, pivot_index - 1);
        quicksort_recursion(a, pivot_index + 1, high_index);
    }
}

int partition_index(int a[], int low_index, int high_index){
    int pivot_value = a[high_index];
    int i = low_index;
    for (int j = low_index; j < high_index; j++){
        if (a[j] <= pivot_value){
            std::swap(a[i], a[j]);
            i++;
        }
    }
    std::swap(a[i], a[high_index]);
    return i;
}

void swap(int& x, int& y){
    int temp = x;
    x = y;
    y = temp;
}

void print(int a[], int length){
    for (int i = 0; i < length; i++){
        std::cout << "a[" << i << "]=\t" << a[i] << "\n";
    }
    std::cout << "\n";
}