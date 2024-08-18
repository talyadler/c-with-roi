#include <iostream>

// forward declaration
int add6(int);
//int add7(int);
//int add7(int, int);

int main() {
  std::cout << "hello world" << std::endl;
  int y=1;
  int z = add6(y);
  std::cout<<z<<std::endl;
  return 0;
}

int add6(int x){
  return x+6;
}
