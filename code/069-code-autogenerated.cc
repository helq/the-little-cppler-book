#include <iostream>

int main()
{
  int b = 7;
  int c = 10; // it works with 11 too
  int i = 0;
  
  while ((i<b) || (i+1<c)) {
    std::cout << i << " ";
    i++;
    i++;
  }
  std::cout << std::endl;

  return 0;
}
