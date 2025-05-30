#include <iostream>

void bubble_sort(int array[], int size);

int main() {
    int array[] = {10, -1008, 9, 2, 2, 3, -7, 4, 6, 5};
    int size = 10;
    bubble_sort(array, size);
    for(int i=0; i < size; i++){
        std::cout << array[i] << " ";
    }
    std::cout << "\n";
    return 0;
}

void bubble_sort(int array[], int size){
    int temp;
    for(int i = 0; i < size - 1; i++){
        for(int j = 0; j < size - i - 1; j++){
            if(array[j] > array[j + 1]){ // sort array from low value to high value for other way change from < to >
                temp = array[j]; //save value in temp for swap
                array[j] = array[j + 1]; // swap places for bigger value
                array[j + 1] = temp; // place the higher value in next index
            }
        }
    }
} 