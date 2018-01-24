#include <iostream>

int main()
{
  int var1 = (2 + 18 - 6 * 2) * 5;
  int var2 = var1 / 3;
  int var3 = var1 % 3;
  
  std::cout << "var1 => " << var1 << std::endl;
  std::cout << "var2 => " << var2 << std::endl;
  std::cout << "var3 => " << var3 << std::endl;

  return 0;
}
