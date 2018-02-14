#include <iostream>

int main()
{
  int a = 0;
  int b = 0;
  while (a<=10) {
    if (a%2 == 0) {
      b = b + a;
    }
    std::cout << b << " ";
    a++;
  }
  std::cout << std::endl;

  return 0;
}
