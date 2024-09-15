#include <iostream>

// Given a m x n matrix, you can start at the top-left corner (0, 0) and can move either right or down at any step. Write a recursive function to count all possible paths to reach the bottom-right corner (m-1, n-1).
//Example:
//	• countPaths(2, 2) should return 2 (Paths: right->down, down->right)
//	• countPaths(3, 3) should return 6
//	we know
//	n = 0 end of recurse
//	m = 0 end
//	count each combination as 1
//

int matrix(int m, int n){
	if (n == 0 && m == 0){
		return 1;
	}
	return matrix(m-1,n-1);
}

int main (){
	printf("hi %d\n", matrix(2,2));
}
