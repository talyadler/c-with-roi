#include <iostream>
void hanoi(int n, int from, int to){
	// base case, n = 1
	if (n==1){
		printf("move ring %d from column %d to column %d --- this is the return print --- \n",n,from,to);
		return;
	}
	// assume for n-1, prove for n
	hanoi(n-1,from,3-(from + to)); // call to 'black box', using induction assumption
	printf("move ring %d from column %d to column %d --- this is second hanoi --- \n",n,from,to);
	hanoi(n-1,3-(from+to),to); // call to 'black box', using induction assumption
}
int main(){
	int n=5;
	int from=0;
	int to=2;
	hanoi(n,from,to);
	return 0;
}

//--------------------------------------------------------------------------------
//
//n = 1;
//
//assume we have a solution to move a tower of n discs
//prove for n+1
//
//1. move first n discs from 'from' to '(3-(from+to))'  (using induction assumption)
//2. move disc n+1 from 'from' to 'to'
//3. move n discs from '(3-(...))' to 'to
//
//	we have n+1 transformend to n (-1)
//	we have n transformed to n-1 (-1)
//	towers are cohsen by reson. we know startin tower (from) and destination (to) with this knowlage we can find the reaming tower 3-(from+to)
//
//	1. base case is proven explicitely by us  (line 4+5)
//	2. we assum recursive function is a solution for n-1 (n) (line 9+11)
//	3. we need to prove for n (n+1), use recursive call where needed, and complete with explicit code (line 10)
//				
