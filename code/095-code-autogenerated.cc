#include <iostream>

int main()
{
  char symbol = 32; // first "visible" character
  
  while (symbol < 127) {
    std::cout << symbol;
    symbol++;
    if (symbol % 32 == 0) {
      std::cout << std::endl;
    }
  }
  std::cout << std::endl;

  return 0;
}
