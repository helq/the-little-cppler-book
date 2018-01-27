#include <iostream>

int main()
{
  char i = 126;
  std::cout << (int)i << " ";
  i = i + 1;
  std::cout << (int)i << " ";
  i = i + 1;
  std::cout << (int)i << " ";
  i = i + 1;
  std::cout << (int)i << std::endl;

  return 0;
}
