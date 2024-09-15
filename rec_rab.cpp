#include <iostream>

int bunnyEars(int bunnies) {
	printf("this is round %d\n", bunnies);
	if (bunnies == 1) {
		return 1;
	}
	int x =  bunnyEars(bunnies-1);
	return x * 2;
}

int main (){
	printf("there are %d ears\n", bunnyEars(4));
}
