#include <iostream>

int main()
{
  int num = 20;
  std::cout << num << " ";
  {
    int num = 42;
    std::cout << num << " ";
    num = 3;
    std::cout << num << " ";
  }
  std::cout << num << " ";
  num = 0;
  std::cout << num << std::endl;

  return 0;
}
