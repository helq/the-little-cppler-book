#include <iostream>

int main()
{
  bool a = 5 > 2;
  bool b = true;
  if (a==b) {
    std::cout << "5 > 2 is equal to true"
              << std::endl;
  } else {
    std::cout << "bananas!" << std::endl;
  }

  return 0;
}
