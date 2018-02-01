#include <iostream>

void add_two_nums(int a, int b, int c) {
  c = b + a;

  std::cout << "a == " << a << std::endl;
  std::cout << "b == " << b << std::endl;
  std::cout << "c == " << c << std::endl;
}

int main() {
  int first  = 4;
  int second = 3;
  int total  = -2;

  add_two_nums(first, second, total);

  std::cout
    << "total == " << total << std::endl;

  return 0;
}

