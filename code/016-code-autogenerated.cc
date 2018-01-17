#include <iostream>

int main()
{
  int var1 = 6;
  int var2 = 3;
  int var3 = 10;
  
  var2 = var1*3;
  
  std::cout
    << (var1+var2) * var3 - var2
    << std::endl;

  return 0;
}
