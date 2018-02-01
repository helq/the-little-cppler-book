#include <iostream>

void show_addition(int a, int b) {
  std::cout << a << " + " << b
            << " == " << a*b;
}

int main() {
  for (int i=4; i<=7; i++) {
    show_addition(i,3);
  }

  return 0;
}

