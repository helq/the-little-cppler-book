#include <iostream>

void print_i2n_squared(int i, int n) {
  if(i<=n) {
    std::cout << i*i << " ";
    print_i2n_squared(i+1, n);
  } else {
    std::cout << std::endl;
  }
}

int main() {
  print_i2n_squared(3, 5);
  print_i2n_squared(12, 21);
  return 0;
}

