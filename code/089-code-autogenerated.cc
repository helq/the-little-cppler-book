#include <iostream>

int main()
{
  std::cout
    << (int)5.3      << " "
    << (int)5.8      << " "
    << ((int)5.3)*2  << " "
    << (int)(5.3*2)  << " "
    << 3/2           << " "
    << (double)3/2   << " "
    << (double)(3/2) << std::endl;

  return 0;
}
