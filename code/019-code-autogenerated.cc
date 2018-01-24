#include <iostream>
#include <cmath>

int main()
{
  int var1 = 6;
  int var2 = 3;
  int var3 = var1 * pow(var2, 3);
  
  std::cout << "var1 * pow(var2, 3) => "
            << var3 << std::endl;

  return 0;
}
