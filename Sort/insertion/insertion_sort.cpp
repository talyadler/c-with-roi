#include <iostream>

void insertion_sort(int a[], int length);

void print(int a[], int length);

int main() {
    int a[] = {8,2,7,4,5,1,9,3};
    int length = 8;
    print(a,length);
    insertion_sort(a,length);
    print(a,length);
    return 0;
}

void insertion_sort(int a[], int length){
    for (int i = 1; i < length; i++){
    /*
    start at 2nd element of the array because first is "sorted".
    i increment for each loop iteration and keep looking at next element in the right hand unsort portion of the array until we reach the last element of the array.
    */
        int key = a[i]; // store the index value for evaluation and storing of value in correct position.
        int j = i-1; // keep track of the position in the sorted portion of the array.
        // the value one index to the left of the current key value i, is the first value in the sorted portion of the array we are going to compare the key to.
        while (j >= 0 && a[j] > key){ // stop at the start of the array and greater than key to actualy sort.
            /*
            loop to shift key value to the right at index i into its correct possition in the sorted position of the array.
            j keeps track of the element were looking at in the sorted portion of the array.
            */
            a[j+1] = a[j]; // shift one to the right 
            j = j - 1; // keep shifting over the next element in the soreted portion of the array
        }
        a[j + 1] = key;
    }
}

void print(int a[], int length){
    for (int i = 0; i < length; i++) std::cout << a[i]<< " ";
    std::cout << "\n";
}