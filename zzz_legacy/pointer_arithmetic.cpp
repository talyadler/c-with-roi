#include <iostream>

void changeToSix(int *p) {
	*p = 6;
}


int main() {
	int a = 5;
	int b = a;
	printf("a: %d, b: %d, &a: %lu, &b: %lu \n", a, b, (unsigned long)&a, (unsigned long)&b);

	int *p = &a;
	printf("p: %lu, *p: %d \n", (unsigned long)p, *p);

	printf("\n");

	a = 80;
	printf("a: %d, b: %d, &a: %lu, &b: %lu \n", a, b, (unsigned long)&a, (unsigned long)&b);
	printf("p: %lu, *p: %d \n", (unsigned long)p, *p);

	printf("\n");

	*p = 666;
	printf("a: %d, b: %d, &a: %lu, &b: %lu \n", a, b, (unsigned long)&a, (unsigned long)&b);
	printf("p: %lu, *p: %d \n", (unsigned long)p, *p);

	printf("\n");

	changeToSix(&b);
	printf("a: %d, b: %d, &a: %lu, &b: %lu \n", a, b, (unsigned long)&a, (unsigned long)&b);
	printf("p: %lu, *p: %d \n", (unsigned long)p, *p);

	printf("\n");

	*p = 700;
	int **pp = &p;
	p = (int *) ((char *)p + sizeof(int));
	**pp = 900;

	printf("a: %d, b: %d, &a: %lu, &b: %lu \n", a, b, (unsigned long)&a, (unsigned long)&b);
	printf("p: %lu, *p: %d \n", (unsigned long)p, *p);

}

