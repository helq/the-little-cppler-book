#include <iostream>

int main()
{
  char symbol = 'A';
  
  while (symbol <= 'Z') {
    std::cout << symbol;
    symbol++;
  }
  std::cout << std::endl;

  return 0;
}
