#include <iostream>

int main()
{
  int magicnumber = -2;
  if (2!=3) {
    magicnumber = 0;
  } else {
    magicnumber = 42;
  }
  std::cout << "Every integer is a divisor of "
            << magicnumber << std::endl;

  return 0;
}
