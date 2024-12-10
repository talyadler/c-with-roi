#include <iostream>

class A {
public:
	A() {}
	A(int) : x(10), y(20), z(30) {
	}
	A(char) : x(31), y(41), z(51) {
	}

	void print() {
		std::cout << "Class A: x = " << x << ", y = " << y << ", z = " << z << std::endl;
	}

private:
	int x = 1;
	int y = 2;
	int z = 3;
};

class B : public A {
public:
	B() { print(); }
	B(int) : a(4), b(5) {}
	B(char) : A(1), a(61), b(71) {}

	void print() {
		std::cout << "Class B: a = " << a << ", b = " << b << std::endl;
		A::print();
	}
private:
	int a = 0;
	int b = 0;
};


int main() {
	B b1;
	B b2(1);
	B b3('a');

	std::cout << std::endl;
	b2.print();
	std::cout << std::endl;
	b3.print();
	std::cout << std::endl;
}

