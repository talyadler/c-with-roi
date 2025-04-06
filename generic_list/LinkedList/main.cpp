#include "ll.h"

template <typename T> void fillList(LinkedList<T> &ll, unsigned int c) {
  for (int i = 0; i < c; i++) {
    ll.addLast(i);
  }
  std::cout << "length: " << ll.length() << "\n";
}

void ll_addAt_test(unsigned int c) {
  std::cout << "ll_addAt_test start" << std::endl;
  LinkedList<int> ll;
  printf("fill ll with %d items\n", c);
  fillList(ll, c);
  std::cout << ll << std::endl;
  for (int i = c; i >= 0; i--) {
    ll.addAt(i + 1000, i);
    std::cout << ll << std::endl;
  }
  std::cout << "ll_addAt_test end" << std::endl;
  std::cout << "--------------------------------------\n" << std::endl;
}

void ll_operator_eq_test(unsigned int c) {
  std::cout << "ll_operator_eq_test start" << std::endl;
  LinkedList<int> ll1;
  LinkedList<int> ll2;
  try {
    printf("print ll1\n");
    std::cout << ll1 << std::endl;
  } catch (std::out_of_range e) {
    std::cout << e.what() << "\n";
  }

  try {
    printf("print ll2\n");
    std::cout << ll2 << std::endl;
  } catch (std::out_of_range e) {
    std::cout << e.what() << "\n";
  }

  printf("\nfill ll1 with %d items\n", c);
  fillList(ll1, 5);

  try {
    printf("print ll1\n");
    std::cout << ll1 << std::endl;
  } catch (std::out_of_range e) {
    std::cout << e.what() << "\n";
  }

  try {
    printf("print ll2\n");
    std::cout << ll2 << std::endl;
  } catch (std::out_of_range e) {
    std::cout << e.what() << "\n";
  }

  printf("\nusing ll2=ll1\n");
  try {
    ll2 = ll1;
  } catch (std::out_of_range e) {
    std::cout << e.what() << "\n";
  }

  try {
    printf("print ll1\n");
    std::cout << ll1 << std::endl;
  } catch (std::out_of_range e) {
    std::cout << e.what() << "\n";
  }

  try {
    printf("print ll2\n");
    std::cout << ll2 << std::endl;
  } catch (std::out_of_range e) {
    std::cout << e.what() << "\n";
  }
  std::cout << "ll_operator_eq_test end" << std::endl;
  std::cout << "--------------------------------------\n" << std::endl;
}

void ll_operator_bracers_test(unsigned int c) {
  std::cout << "ll_operator_bracers_test start" << std::endl;
  LinkedList<int> ll;
  fillList(ll, c);
  int p = c - 1;
  ll[p] = 999;
  std::cout << "value at index " << p << ": " << ll[p] << "\n";
  std::cout << "ll_operator_bracers_test end" << std::endl;
  std::cout << "--------------------------------------\n" << std::endl;
}

void ll_operator_eq_eq_test(unsigned int c) {
  printf("ll_operator_eq_eq_test start\n");
  LinkedList<int> ll1;
  LinkedList<int> ll2;

  printf("\nll1 5 items\tll2 6 items\n");
  fillList(ll1, 5);
  fillList(ll2, 6);

  if (ll2 == ll1) {
    printf("true\n");
  } else {
    printf("false\n");
  }

  printf("\nremove ll2 last\n");
  ll2.removeLast();

  if (ll2 == ll1) {
    printf("true\n");
  } else {
    printf("false\n");
  }

  printf("\nchange value in ll1\n");
  ll1[2] = 999;

  if (ll2 == ll1) {
    printf("true\n");
  } else {
    printf("false\n");
  }
  printf("ll_operator_eq_eq_test end\n");
  std::cout << "--------------------------------------\n" << std::endl;
}

void ll_operator_plus_test(unsigned int c) {
  printf("ll_operator_plus_test start\n");
  LinkedList<int> ll1;
  LinkedList<int> ll2;
  LinkedList<int> ll3;
  fillList(ll1, c);
  fillList(ll2, c);
  ll3 = ll1 + ll2;
  try {
    printf("print ll3\n");
    std::cout << ll3 << std::endl;
  } catch (std::out_of_range e) {
    std::cout << e.what() << "\n";
  }
  printf("ll_operator_plus_test end\n");
  std::cout << "--------------------------------------\n" << std::endl;
}

void ll_operator_plus_link_test(unsigned int c) {
  printf("ll_operator_plus_link_test start\n");
  LinkedList<int> ll1;
  LinkedList<int> ll2;
  fillList(ll1, c);
  ll2 = ll1 + 999;
  try {
    printf("print ll2\n");
    std::cout << ll2 << std::endl;
  } catch (std::out_of_range e) {
    std::cout << e.what() << "\n";
  }
  printf("ll_operator_plus_link_test end\n");
  std::cout << "--------------------------------------\n" << std::endl;
}

int main() {
  ll_addAt_test(5);
  ll_operator_eq_test(5);
  ll_operator_bracers_test(5);
  ll_operator_eq_eq_test(5);
  ll_operator_plus_test(5);
  ll_operator_plus_link_test(5);

  return 0;
}
