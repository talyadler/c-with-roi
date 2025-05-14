#include "al.h"

template <typename T> void fillList(AL<T> &al, unsigned int c) {
  printf("adding %d items to array\n", c);
  for (int i = 0; i < c; i++) {
    al.addLast(i);
    showList(al);
  }
  std::cout << "length: " << al.length() << "\n";
}

template <typename T> void showList(AL<T> &al) {
  try {
    std::cout << al << "\n";
  } catch (std::out_of_range e) {
    std::cout << e.what() << "\n";
  }
}

template <typename T> void main_removeFirst(AL<T> &al) {
  try {
    al.removeFirst();
  } catch (std::out_of_range e) {
    std::cout << e.what() << "\n";
  }
}

template <typename T> void main_removeLast(AL<T> &al) {
  try {
    al.removeLast();
  } catch (std::out_of_range e) {
    std::cout << e.what() << "\n";
  }
}

template <typename T> void main_removeAt(AL<T> &al, int index) {
  try {
    al.removeAt(index);
  } catch (std::out_of_range e) {
    std::cout << e.what() << "\n";
  }
}

void remove_test(int c) {
  printf("testing remove start\n");
  AL<int> al;
  fillList(al, c);
  showList(al);
  printf("\ntesting remove first\n");
  main_removeFirst(al);
  showList(al);
  printf("\ntesting remove last\n");
  main_removeLast(al);
  showList(al);
  printf("\ntesting remove at(1)\n");
  main_removeAt(al, 1);
  showList(al);
  printf("testing remove end\n");
  std::cout << "--------------------------------------\n" << std::endl;
}

void complex_test(int c) {
  printf("testing complex start\n");
  AL<int> al;
  fillList(al, c);
  printf("remove first\n");
  main_removeFirst(al);
  showList(al);
  printf("remove last\n");
  main_removeLast(al);
  showList(al);
  int add = 3;
  fillList(al, add);
  showList(al);

  printf("testing remove end\n");
  std::cout << "--------------------------------------\n" << std::endl;
}

int main() {
  int c = 5;
  remove_test(c);
  // complex_test(c);
  return 0;
}