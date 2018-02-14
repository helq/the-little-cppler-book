#include <iostream>

int main()
{
  int i = 0;
  while (i<=10) {
    int j = 0;
    while (j<=20) {
      std::cout << "*";
      j++;
    }
    std::cout << std::endl;
    i++;
  }

  return 0;
}
