#include <iostream>

int addtwice(int a, int b) {
  int c = 2 * (a + b);
  return c;
}

int main() {
  std::cout << addtwice(5, 3) << std::endl;
  return 0;
}

