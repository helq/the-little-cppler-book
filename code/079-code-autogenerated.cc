#include <iostream>

int main()
{
  int top = 10;
  int i = 0;
  while (i<top) {
    std::cout << i * top + 1 << " ";
    i++;
  }
  std::cout << std::endl;

  return 0;
}
