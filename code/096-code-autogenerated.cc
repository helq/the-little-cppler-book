#include <iostream>

int adding(int a, int b) {
  int c = a + b;
  return c;
  std::cout << "I'm never run :("
            << std::endl;
  c = c + 2;
}

int main() {
  for(int i=0; i<10; i++) {
    std::cout << adding(i,i) << ' ';
  }
  std::cout << std::endl;
  return 0;
}

