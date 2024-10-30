#include <iostream>

// return 'true' iff we can reach 'targetSum' by summing any subset of elements from 'arr'
// for arr = {1,1,2,4, -1}, targetSum = 7, should return true (1+2+4 = 7)
// for arr = {2,2,4,5, -1}, targetSum = 3, should return false
// for arr = {5,2,1,7, -1}, targetSum = 3, should return true (2+1 = 3)
// for arr = { -1}, targetSum = 3, should return false
//
// assume arr contains only positive numbers, -1 means end of arr
bool subsetSum(int *arr, int targetSum) {
	if (targetSum == 0) return true;
	if (*arr == -1) return false;
	return targetSum > 0 && (subsetSum(arr + 1, targetSum - *arr) || subsetSum(arr + 1, targetSum));
}


int main() {
	int arr1[] = {1, 1, 2, 4, -1};
	int arr2[] = {2, 2, 4, 5, -1};
	int arr3[] = {5,2,1,7, -1}; 
	int arr4[] = { -1}; 
	if (!subsetSum(arr1, 7))
		printf("failed on case 1\n");
	else if (subsetSum(arr2, 3))
		printf("failed on case 2\n");
	else if (!subsetSum(arr3, 3))
		printf("failed on case 3\n");
	else if (subsetSum(arr4, 3))
		printf("failed on case 4\n");
	else 
		printf("SUCCESS!!!\n");
}
