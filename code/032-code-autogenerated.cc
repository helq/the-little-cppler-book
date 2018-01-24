#include <iostream>

int main()
{
  int magicnumber = -2;
  if (2!=3) {
    int magicnumber = 0;
  } else {
    int magicnumber = 42;
  }
  std::cout << "Every integer is a divisor of "
            << magicnumber << std::endl;

  return 0;
}
