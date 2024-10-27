#include <iostream>
/*
 * We have a number of bunnies and each bunny has two big floppy ears. 
 * We want to compute the total number of ears across all the bunnies recursively (without loops or multiplication).
 */
int bunnyEars(int bunnies) {
	printf("this is round %d\n", bunnies);
	if (bunnies == 0){ 
		return 0;
	}
	return 2 + bunnyEars(bunnies-1);
}
/*
 * We have bunnies standing in a line, numbered 1, 2, ... 
 * The odd bunnies (1, 3, ..) have the normal 2 ears. 
 * The even bunnies (2, 4, ..) we'll say have 3 ears, because they each have a raised foot. 
 * Recursively return the number of "ears" in the bunny line 1, 2, ... n (without loops or multiplication).
 */
int oddEars(int e) {
	if (e == 0){
		return 0;
	}
	if (e == 1) 
		return 2;
	return 5 + oddEars(e-2);
}

/*
 * Given a non-negative int n, return the sum of its digits recursively (no loops). 
 * Note that mod (%) by 10 yields the rightmost digit (126 % 10 is 6), 
 * while divide (/) by 10 removes the rightmost digit (126 / 10 is 12).
 */
int sumDigits(int n) {
	return 0;
}

/*
 * Given a non-negative int n, 
 * compute recursively (no loops) the count of the occurrences of 8 as a digit, 
 * except that an 8 with another 8 immediately to its left counts double, so 8818 yields 4. 
 * Note that mod (%) by 10 yields the rightmost digit (126 % 10 is 6), 
 * while divide (/) by 10 removes the rightmost digit (126 / 10 is 12).
 *
 * count8(81) == 1
 * count8(818) == 2
 * count8(8818) == 4
 */
int count8(int n) {
	return 0;
}

/*
 * Given a string (array of chars), a starting index and an ending index,
 * compute recursively if the sub-string starting at a[from] and ending at a[to] 
 * is a palindrome (is the same read backwards).
 *
 * isPalindrome("palindrome", 0, 9) == false
 * isPalindrome("atoyota", 0, 6) == true
 */
bool isPalindrome(char* a, int from, int to) {
	return 0;
}

int main (){
	printf("there are %d ears\n", oddEars(4));
}
