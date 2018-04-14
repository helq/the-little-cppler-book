#include <iostream>

int sum_i2n(int i, int n) {
  if(i<=n) {
    return i + sum_i2n(i+1, n);
  } else {
    return 0;
  }
}

int main() {
  std::cout << sum_i2n(1,10) << std::endl;
  std::cout << sum_i2n(1,10)*3 << std::endl;
  return 0;
}

