#include <iostream>
#include <cstdlib>

bool greaterThan(int r,int b){
	if(r < b) {
		return true;
	}
	exit(1);
}

bool notEqual(int b){
	if (b != 0) {
		return true;
	} 
	exit(2);
}

bool calculation(int a, int b, int q, int r){
	if (a == q*b + r) { 
		return true;
	}
	exit(3);
}

int main(int argc, char** argv){
	if (argc < 5) {
		return 99;
	}
	else if (argc > 5) {
		return 101;
	}
	int a = atoi(argv[1]);
	int b = atoi(argv[2]);
	int r = atoi(argv[3]);
	int q = atoi(argv[4]);
	if(greaterThan(r,b) && notEqual(b) && calculation(a,b,q,r)) {
		return 0;
	}
}
