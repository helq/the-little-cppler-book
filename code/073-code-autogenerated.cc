#include <iostream>

int main()
{
  int sum = 0;
  int i = 1;
  while (i<=10) {
    sum = sum + i;
    i++;
  }
  std::cout << "1+2+3+...+10 == " << sum
            << std::endl;

  return 0;
}
