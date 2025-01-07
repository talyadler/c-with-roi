#include <iostream>

class A {
public:
	virtual void foo() {
		printf("A::foo\n");
	}
};

class B : public A {
public:

	virtual void goo() {
		printf("B::goo\n");
	}
};

class C : public B {
public:
	void hoo() {
		printf("C::hoo\n");
	}
};

class D {
public:
	void foo() {
		printf("D::foo\n");
	}
};


void callFooC(C c) {
	c.foo();
	c.goo();
	c.hoo();
}

// slicing
void callFooB(B b) {
	b.foo();
}

// slicing
void callFooA(A a) {
	a.foo();
}

int main(){
	C* c1 = new C();
	A* a1 = c1; // a1's static class is A*, dynamic class is C*;
	callFooC(*c1);
	callFooB(*c1);
	callFooA(*c1);
}

