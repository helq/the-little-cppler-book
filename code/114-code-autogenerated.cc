#include <iostream>

void print_i2n_squared(int start, int n) {
  for(int i=start; i<=n; i++) {
    std::cout << i*i << " ";
  }
  std::cout << std::endl;
}

int main() {
  print_i2n_squared(3, 5);
  print_i2n_squared(12, 21);
  return 0;
}

