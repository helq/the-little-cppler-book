#include <iostream>

int main()
{
  int i = -2;
  while (i<3) {
    std::cout << i << " squared is: " << i*i
              << std::endl;
    i = i + 1;
  }

  return 0;
}
