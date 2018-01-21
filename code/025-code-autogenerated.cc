#include <iostream>

int main()
{
  int var1 = 2*2+2;
  if (var1 != 7 + 3) {
    std::cout << "2*2+2 != 7+3" << std::endl;
  } else {
    std::cout << "2*2+2 == 7+3" << std::endl;
  }

  return 0;
}
