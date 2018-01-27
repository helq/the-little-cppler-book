#include <iostream>

int main()
{
  char a = 100;
  char b = 20;
  char c = a + b;
  std::cout << "a : " << (int)a << std::endl
            << "b : " << (int)b << std::endl
            << "a+b : " << (int)c << std::endl;

  return 0;
}
