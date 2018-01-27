#include <iostream>

int main()
{
  int i = 0;
  if (i<3) {
    std::cout << i << " ";
    i = i + 1;
  }
  if (i<3) {
    std::cout << i << " ";
    i = i + 1;
  }
  std::cout << std::endl;

  return 0;
}
