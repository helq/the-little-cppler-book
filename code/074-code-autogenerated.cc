#include <iostream>

int main()
{
  int sum = 0;
  int i = 1;
  while (i<=10) {
    sum = sum + i*i;
    i++;
  }
  std::cout << "1^2 + 2^2 + 3^2 + ... + 10^2 == "
            << sum << std::endl;

  return 0;
}
