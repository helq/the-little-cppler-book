#include <iostream>

int main()
{
  int i = -6;
  while (i<=-2) {
    std::cout << i << " squared is: " << i*i
              << std::endl;
    i++;
  }

  return 0;
}
