#include <iostream>

int bunnyEars(int bunnies) {
	printf("this is round %d\n", bunnies);
	if (bunnies == 0){ 
		return 0;
	}
	return 2 + bunnyEars(bunnies-1);
}

int oddEars(int e) {
	if (e == 1){
		printf("adding %d ears\n", e*3);
		return 1;
	}
	else if (e % 2 == 0){
		printf("adding %d ears\n", (e/e)+1);
		return oddEars(e-1)*2;
	}
	printf("adding %d ears\n", (e/e)+2);
	return  oddEars(e-1)*3;
}

int main (){
	printf("there are %d ears\n", bunnyEars(5));
}
