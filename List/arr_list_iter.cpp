#include <iostream>
#include "arraylist.h"

int main() {
	ArrayList al;
	al.addLast(1);
	al.addLast(2);
	al.addLast(3);
	al.addLast(4);
	al.addLast(5);
	al.addLast(6);
	std::cout << "al[3] = " << al[3] << std::endl;
	al[3] = 7;

	for (int element : al) {
		std::cout << element << ", " ;
	}

	std::cout << std::endl;
}

