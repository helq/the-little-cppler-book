#include <iostream>

int main()
{
  std::cout
    << "1 && 1 == " << (true  && true)
    << std::endl
    << "1 && 0 == " << (true  && false)
    << std::endl
    << "0 && 1 == " << (false && true)
    << std::endl
    << "0 && 0 == " << (false && false)
    << std::endl;

  return 0;
}
