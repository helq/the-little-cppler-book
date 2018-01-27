#include <iostream>

int main()
{
  std::cout << "A char   is " << sizeof(char)
            << " bytes" << std::endl;
  std::cout << "A int    is " << sizeof(int)
            << " bytes" << std::endl;
  std::cout << "A double is " << sizeof(double)
            << " bytes" << std::endl;
  std::cout << "A float  is " << sizeof(float)
            << " bytes" << std::endl;
  std::cout << "A bool   is " << sizeof(bool)
            << " bytes" << std::endl;

  return 0;
}
