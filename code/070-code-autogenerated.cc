#include <iostream>

int main()
{
  int a = 0;
  while (a<=10) {
    if (a%2 == 0) {
      std::cout << a << " ";
    }
    a++;
  }
  std::cout << std::endl;

  return 0;
}
