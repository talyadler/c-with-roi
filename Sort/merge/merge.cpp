#include <iostream>

void merge_sort(int a[],int length);
void merge_sort_recursion(int a[], int low, int high);
void merge_sorted(int a[], int low, int mid, int high);
void print(int a[], int length);

int main(){
    int a[] = {-8,10,-55,9,5,3,95,1};
    int length = 8;

    print(a,length);
    merge_sort(a,length);

    print(a,length);
    
    return 0;
}

void merge_sort(int a[],int length){
    merge_sort_recursion(a,0,length-1);
}

void merge_sort_recursion(int a[], int low, int high){
    if (low < high){
        int mid = (low + (high -1)) / 2;
        merge_sort_recursion(a, low, mid);
        merge_sort_recursion(a, mid + 1, high);
        merge_sorted(a, low, mid, high);
    }
}

void merge_sorted(int a[], int low, int mid, int high){
    int left_length = mid - low + 1;
    int right_length = high - mid;

    int temp_left[left_length];
    int temp_right[right_length];

    int i, j, k;
    for (int i = 0; i < left_length; i++) temp_left[i] = a[low + i];
    for (int i = 0; i < left_length; i++) temp_right[i] = a[mid + 1 +i];

    for (i = 0, j = 0, k = low; k <= high; k++){
        if ((i < left_length) &&
            (j >= right_length || temp_left[i] <= temp_right[j])){
                a[k] = temp_left[i];
                i++;
        }
        else{
            a[k] = temp_right[j];
            j++;
        }
    }
}

void print(int a[], int length){
    for (int i = 0; i < length; i++)std::cout << a[i] << " ";
    std::cout << "\n";
}