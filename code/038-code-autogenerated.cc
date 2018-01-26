#include <iostream>

int main()
{
  int n = 15;
  bool either = n<3;
  if (either) {
    std::cout << ":P" << std::endl;
  } else {
    std::cout << ":(" << std::endl;
  }

  return 0;
}
