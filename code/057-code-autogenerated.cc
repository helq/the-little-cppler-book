#include <iostream>

int main()
{
  int a = 13;
  int b = 6;
  int c = 8;
  while (b<a && b<c) {
    std::cout << "Both conditions met"
              << std::endl;
    b++;
  }

  return 0;
}
