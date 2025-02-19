#include <iostream>
// #include <ctime>

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

    return 0;
}

void quicksort(int a[], int length){
    //seed rand in recursion
    // std::srand(std::time(NULL));
    // initialize with start of array and end of array
    quicksort_recursion(a, 0, length - 1);
}

void quicksort_recursion(int a[], int low_index, int high_index){
    if (low_index<high_index){
        int pivot_index = partition_index(a,low_index,high_index);
        //sort left partition
        quicksort_recursion(a, low_index, pivot_index - 1);
        // sort right partition
        quicksort_recursion(a, pivot_index + 1, high_index);
    }
}

int partition_index(int a[], int low_index, int high_index){
    // //use rand for better efficiancy to start the partitioning in random index in case the array is sorted.
    // int pivot_index = low_index +(std::rand() % (high_index - low_index + 1)); // using % willl result in a remaider that will be in the correct range
    // // swap the values of high_index with rand_index to lower run time.
    // if (pivot_index != high_index) std::swap(a[pivot_index], a[high_index]);

    int pivot_value = a[high_index]; // store the value in the pivot index for later use
    int i = low_index; // i is the index for the left most part of the partition
    std::cout << "\npartitioning...\nfound low index at, " <<low_index<<"\tfound high index at, "<< high_index<</*"\t pivot index selected randomly is," << pivot_index <<*/" \tkey value is,"  <<pivot_value<<  "\n"; 
    for (int j = low_index; j < high_index; j++){ // j is the index containg a value that will be swaped with the value in index i if the value in j index is lower than the key value (pivot)
        std::cout << "j=" <<j<<"\ti="<< i << "\t a[j]=" << a[j] << "\t a[i]=" << a[i] << "\t\tkey value=" << pivot_value <<"\n";
        if (a[j] <= pivot_value){
            std::cout << "a[j]," <<a[j]<<" is lower than key, "<< pivot_value<<".\t swapping...\n"; 
            std::swap(a[i], a[j]);
            std::cout << "incrementing i by 1\n";
            i++;
            
        }
        else{
            std::cout << "a[j]," <<a[j]<<" is NOT lower than key, "<< pivot_value<<"\n"; 
        }
        std::cout << "incrementing j by 1" << "\n";
    }
    std::cout << "loop done... swapping a["<<i<<"]" << a[i] << " with a["<<high_index<<"]" <<a[high_index]<<"\n"; 
    std::swap(a[i], a[high_index]);
    print(a, high_index+1);
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