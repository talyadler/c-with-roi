#include <iostream>
#include <string>

// Given a m x n matrix, you can start at the top-left corner (0, 0) and can move either right or down at any step. Write a recursive function to count all possible paths to reach the bottom-right corner (m-1, n-1).
//Example:
//	• countPaths(2, 2) should return 2 (Paths: right->down, down->right)
//	• countPaths(3, 3) should return 6
//	we know
//	n = 0 end of recurse
//	m = 0 end
//	count each combination as 1
//	base case = only one sulution ie 1x1 = 1

int matrix(int x, int y){
	if (x&&y!=1){
		printf("path %d,%d\n",x,y);
	}
	if (x == 1 && y == 1){
		return 1;
	}
	if (x>1&&y==1){
		return  matrix (x-1,y);
	}
	if (y>1&&x==1){
		return matrix(x,y-1);
	}
	return matrix(x-1,y) +  matrix(x,y-1);
}
/*
String Permutations

Function Signature:

void permute(std::string s, int l, int r);
Description:
Write a recursive function to generate all permutations of a given string. The function should take a string s and print all its possible permutations.
Example:
• Input: "ABC"
• Output:
ABC
ACB
BAC
BCA
CAB
CBA
*/
void permute(std::string s, int l, int r){	
	printf("(r = %d)\n",r);
	if (r == 1){
		std::cout<<"end"<<std::endl;
		return;
	}
	if (s[l] == '\0'){
		return permute(s,l-1,r-1);
	}
	return permute(s,l-1,r-1);
}

unsigned int factorial(int n) {
    if (n <= 1) return 1;
    else return n * factorial(n - 1);
}

int main (){
// start of matrix
	printf("matrix result: %d\n", matrix(2,3));
// start of permute
	std::string t = "ABC";
	permute(t,t.length(),factorial(t.length()));
// start of 
}
