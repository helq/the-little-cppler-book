#include <iostream>

int main()
{
  int num = 42;
  std::cout << num << std::endl;
  {
    int num = 1;
    std::cout << num << std::endl;
  }
  std::cout << num << std::endl;
  {
    num = 1;
    std::cout << num << std::endl;
  }
  std::cout << num << std::endl;

  return 0;
}
