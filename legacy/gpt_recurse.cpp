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
	if (x == 1 && y == 1){
		return 1;
	}
	if (x > 1 && y == 1){
		return  matrix (x-1,y);
	}
	if (y > 1 && x == 1){
		return matrix(x,y-1);
	}
	return matrix(x-1,y) + matrix(x,y-1);
}
/*
-----------------------------------------------------------------
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


unsigned int factorial(int n) {
    if (n <= 1) return 1;
    else return n * factorial(n - 1);
}
------------------------------------------------------------------------------------------
*/

//void permute(std::string s, int l, int r){	
//	if (s.empty()){
//		return;
//	}
//	printf("left index = %d | right index = %d \n",l,r);
//}
//
//----------------------------------------------------------------------------------------

/*
---------------------------------------------------------------------
 Generate All Balanced Parentheses
Function Signature:

cpp
Copy code
void generateParentheses(int n);
Description:
Write a recursive function to generate all combinations of n pairs of balanced parentheses.
Example:
	• generateParentheses(3) should return:

scss
Copy code
((()))
(()())
(())()
()(())
()()()
-------------------------------------------------------------------
*/

/*
-------------------------------------------------------------------
 *Solve N-Queens Problem
Function Signature:

cpp
Copy code
bool solveNQueens(int n);
Description:
The N-Queens problem is to place n queens on an n x n chessboard such that no two queens attack each other. Write a recursive function to find one valid solution.
Example:
	• solveNQueens(4) should return a valid configuration like:

css
Copy code
.Q..
...Q
Q...
..Q.
---------------------------------------------------------------------
 */


/*
---------------------------------------------------------------------
Subset Sum Problem
Function Signature:

cpp
Copy code
bool subsetSum(std::vector<int>& nums, int target);
Description:
Given an array of integers nums and an integer target, write a recursive function to determine if there is a subset of the array that sums up to the target.
Example:
	• subsetSum({3, 34, 4, 12, 5, 2}, 9) should return true (because 4 + 5 = 9)
	• subsetSum({1, 2, 3}, 7) should return false
----------------------------------------------------------------------
 */

/*
---------------------------------------------------------------------
Word Break Problem
Function Signature:

cpp
Copy code
bool wordBreak(std::string s, std::vector<std::string>& wordDict);
Description:
Given a string s and a dictionary wordDict containing a list of words, determine if s can be segmented into a space-separated sequence of dictionary words using recursion.
Example:
	• wordBreak("leetcode", {"leet", "code"}) should return true
	• wordBreak("applepenapple", {"apple", "pen"}) should return true
wordBreak("catsandog", {"cats", "dog", "sand", "and", "cat"}) should return false
---------------------------------------------------------------------
 */

/*
-----------------------------------------------------------------------
Count Number of Islands
Function Signature:

cpp
Copy code
int countIslands(std::vector<std::vector<int>>& grid);
Description:
Given a 2D grid of 0's (water) and 1's (land), write a recursive function to count the number of islands. An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You can assume all four edges of the grid are surrounded by water.
Example:
	• Input:

css
Copy code
grid = [  [1,1,0,0,0],
  [1,1,0,0,0],
  [0,0,1,0,0],
  [0,0,0,1,1]
]
	• Output: 3

-----------------------------------------------------------------------
 */


int main (){
// start of matrix
	if (matrix(2,2)==2){
		printf("true\n");
	}
	if (matrix(3,3)==6){
		printf("true\n");
	}
	if (matrix(2,3)==3){
		printf("true\n");
	}
	if (matrix(3,4)!=9){
		printf("false\n");
	}
	int x, y;
	scanf("%d %d", &x, &y);
	printf("%d\n",matrix(x,y));
// start of permute
//	std::string t = "ABC";
//	permute(t,0,t.length()-1);
// start of 
}
