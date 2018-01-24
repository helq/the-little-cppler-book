#include <iostream>

int main()
{
  int num = 42;
  std::cout << num << " ";
  {
    num = 1;
    std::cout << num << " ";
  }
  std::cout << num << std::endl;

  return 0;
}
