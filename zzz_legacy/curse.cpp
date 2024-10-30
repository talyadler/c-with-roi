#include <iostream>

// return a^b
int pow(unsigned int a, unsigned int b){
	printf("this is round %u\n", b);
	if (b == 0) {
		return 1;
	}
	int x = pow(a, b - 1);
	printf("were at sum %d\n", x);
	return x * a;
}

/*
 * 		n,	n < 2
 * fib(n) =   {
 * 		fib(n-1)+fib(n-2),	else
 */
unsigned int fibonacci(unsigned int n) {
	if (n<2){
		return n;
	}
	return fibonacci(n-1)+fibonacci(n-2);
	}

unsigned int ac(unsigned int m,unsigned int n){
	if (m==0){
		return n+1;
	}
	if (n==0){
		return ac(m-1,1);
	}
	return ac(m-1,ac(m,n-1));
}

int main (){
	printf("%u\n", ac(5, 1));
}
