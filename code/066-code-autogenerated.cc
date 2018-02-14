#include <iostream>

int main()
{
  int b = 10;
  int c = 5;
  int i = 0;
  
  while ((i<b) && (i<c)) {
    std::cout << i << " ";
    i++;
  }
  std::cout << std::endl;

  return 0;
}
