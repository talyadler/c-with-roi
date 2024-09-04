#include <iostream>
void hanoi(int n, int from, int to){
	std::cout << n << "\n";
	if (n==1){
		printf("move ring %d from column %d to column %d --- this is the return print --- \n",n,from,to);
		return;
	}
	std::cout << n << "\n";
	hanoi(n-1,from,to);
	printf("move ring %d from column %d to column %d --- this is second hanoi --- \n",n,from,to);
	std::cout << n << "\n";
}
int main(){
	int n=3;
	int from=1;
	int to=3;
	hanoi(n,from,to);
	return 0;
}
