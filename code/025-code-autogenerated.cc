#include <iostream>

int main()
{
  int var1 = 19;
  if (var1 < 10) {
    std::cout << "var1 smaller than 10"
              << std::endl;
  } else {
    std::cout
      << "var1 greater than or equal to 10"
      << std::endl;
  }

  return 0;
}
