#include <iostream>

int sumToN(int n) {
  int total = 0;
  for (int i=0; i<=n; i++) {
    total += i;
  }
  return total;
}

int main() {
  if (sumToN(20) > 100) {
    std::cout << "1+2+..+20 > 100"
              << std::endl;
  } else {
    std::cout << "1+2+..+20 <= 100"
              << std::endl;
  }

  return 0;
}

